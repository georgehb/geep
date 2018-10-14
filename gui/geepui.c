#include "drawing.h"
#include "note_grid.h"
#include "notes.h"
#include "preamble.h"
#include <errno.h>
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BEATS UINT32_MAX
#define MAX_STRING 512 /* Maximum lengths of any strings */
#define KEY_WIDTH 5

struct application_state {
	struct note_grid note_grid;
	GtkBuilder *builder;
	GtkWidget *window;
	GtkWidget *keyboard;
	GtkWidget *beat_bar;
	GtkWidget *bpm;
	GtkWidget *grid;
	struct {
		GtkWidget *new;
		GtkWidget *save;
		GtkWidget *export;
		GtkWidget *load;
	} menu;
	/* TODO: Update filenames when required */
	char *export_filename;
	char *save_filename;
	unsigned int cur_x;
	unsigned int cur_y;
};

static void update_menu_state(struct application_state *state)
{
	if (state->note_grid.beats) {
		gtk_widget_set_sensitive(state->menu.save, true);
		gtk_widget_set_sensitive(state->menu.export, true);
	} else {
		gtk_widget_set_sensitive(state->menu.save, false);
		gtk_widget_set_sensitive(state->menu.export, false);
	}
}

static gboolean button_press(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
	if (event->type != GDK_BUTTON_PRESS) {
		return false;
	}
	struct application_state *state = (struct application_state *)data;
	/* TODO: align properly with buttons */
	state->cur_x = event->x * COLUMNS / gtk_widget_get_allocated_width(widget);
	state->cur_y = event->y * ROWS / gtk_widget_get_allocated_height(widget);
	unsigned int note = state->note_grid.note_offset + state->cur_y;
	unsigned int beat = state->note_grid.beat_offset + state->cur_x;
	toggle_note(&state->note_grid, note, beat);
	update_menu_state(state);
	gtk_widget_queue_draw(state->note_grid.buttons[state->cur_y * COLUMNS + state->cur_x].widget);
	if (state->cur_x > 0) {
		gtk_widget_queue_draw(state->note_grid.buttons[state->cur_y * COLUMNS + state->cur_x - 1].widget);
	}
	if (state->cur_x < COLUMNS) {
		gtk_widget_queue_draw(state->note_grid.buttons[state->cur_y * COLUMNS + state->cur_x + 1].widget);
	}
	return true;
}

static gboolean button_held(GtkWidget *widget, GdkEventMotion *event, gpointer data)
{
	/* TODO: Better drag functionality */
	if (!(event->state & GDK_BUTTON1_MASK)) {
		return false;
	}
	struct application_state *state = (struct application_state *)data;
	unsigned int x = event->x * COLUMNS / gtk_widget_get_allocated_width(widget);
	unsigned int y = event->y * ROWS / gtk_widget_get_allocated_height(widget);
	if (x == state->cur_x && y == state->cur_y) {
		return false;
	}
	if (x == state->cur_x + 1) {
		struct note *prev = get_note_beat(&state->note_grid,
				state->note_grid.note_offset + state->cur_y,
				state->note_grid.beat_offset + state->cur_x);
		if (prev && prev->state == separate) {
			toggle_note(&state->note_grid,
					state->note_grid.note_offset + state->cur_y,
					state->note_grid.beat_offset + state->cur_x);
		}
	}
	state->cur_x = x;
	state->cur_y = y;
	unsigned int note = state->note_grid.note_offset + state->cur_y;
	unsigned int beat = state->note_grid.beat_offset + state->cur_x;
	toggle_note(&state->note_grid, note, beat);
	update_menu_state(state);
	gtk_widget_queue_draw(state->note_grid.buttons[y * COLUMNS + x].widget);
	if (state->cur_x > 0) {
		gtk_widget_queue_draw(state->note_grid.buttons[state->cur_y * COLUMNS + state->cur_x - 1].widget);
	}
	if (state->cur_x < COLUMNS) {
		gtk_widget_queue_draw(state->note_grid.buttons[state->cur_y * COLUMNS + state->cur_x + 1].widget);
	}
	return true;
}

static void update_grid(struct note_grid *grid)
{
	for (int i = 0; i < BUTTONS; i++) {
		gtk_widget_queue_draw(grid->buttons[i].widget);
	}
}

static void scroll(GtkWidget *widget, GdkEventScroll *event, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	struct note_grid *note_grid = &state->note_grid;
	switch (event->direction) {
		case GDK_SCROLL_UP:
			if (note_grid->note_offset > 0) {
				note_grid->note_offset--;
			}
			update_grid(note_grid);
			break;
		case GDK_SCROLL_DOWN:
			if (note_grid->note_offset < NUM_NOTES - ROWS) {
				note_grid->note_offset++;
			}
			update_grid(note_grid);
			break;
		case GDK_SCROLL_LEFT:
			if (note_grid->beat_offset > 0) {
				note_grid->beat_offset--;
			}
			update_grid(note_grid);
			break;
		case GDK_SCROLL_RIGHT:
			if (note_grid->beat_offset < MAX_BEATS) {
				note_grid->beat_offset++;
			}
			update_grid(note_grid);
			break;
		case GDK_SCROLL_SMOOTH:
			break;
	}
	gtk_widget_queue_draw(state->keyboard);
	gtk_widget_queue_draw(state->beat_bar);
}

static void key_press(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	struct note_grid *note_grid = &state->note_grid;
	switch (event->keyval) {
		case GDK_KEY_Up:
			if (note_grid->note_offset > 0) {
				note_grid->note_offset--;
			}
			update_grid(note_grid);
			break;
		case GDK_KEY_Down:
			if (note_grid->note_offset < NUM_NOTES - ROWS) {
				note_grid->note_offset++;
			}
			update_grid(note_grid);
			break;
		case GDK_KEY_Left:
			if (note_grid->beat_offset > 0) {
				note_grid->beat_offset--;
			}
			update_grid(note_grid);
			break;
		case GDK_KEY_Right:
			if (note_grid->beat_offset < MAX_BEATS) {
				note_grid->beat_offset++;
			}
			update_grid(note_grid);
			break;
		default:
			break;
	}
	gtk_widget_queue_draw(state->keyboard);
	gtk_widget_queue_draw(state->beat_bar);
}

static bool confirm_dialog(GtkWindow *parent,
		const gchar *title,
		const gchar *message,
		const gchar *yes_button,
		const gchar *no_button)
{
	GtkWidget *confirm = gtk_dialog_new_with_buttons(
			title,
			parent,
			GTK_DIALOG_MODAL,
			no_button, GTK_RESPONSE_REJECT,
			yes_button, GTK_RESPONSE_ACCEPT,
			NULL);
	GtkWidget *content = gtk_dialog_get_content_area(GTK_DIALOG(confirm));
	GtkWidget *label = gtk_label_new(message);
	gtk_container_add(GTK_CONTAINER(content), label);
	gtk_box_set_spacing(GTK_BOX(content), 6);
	gtk_container_set_border_width(GTK_CONTAINER(content), 6);

	/* Ensure that the dialog box is destroyed when the user responds */
	gtk_widget_show_all(confirm);
	bool res = (gtk_dialog_run(GTK_DIALOG(confirm)) == GTK_RESPONSE_ACCEPT); 
	gtk_widget_destroy(confirm);
	/* TODO: why does errno get set? */
	errno = 0;
	return res;
}

static void new(GtkWidget *widget, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	if (!state->note_grid.beats || !confirm_dialog(GTK_WINDOW(state->window), "New file", "Are you sure? You will lose any unsaved work.", "Yes", "No")) {
		return;
	}
	note_grid_clear(&state->note_grid);
	update_grid(&state->note_grid);
	update_menu_state(state);
}

static void export(GtkWidget *widget, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	struct beat *beat = state->note_grid.beats;
	struct note *note;
	GtkWidget *dialog;
	gint res;
	if (!beat) {
		return;
	}
	dialog = gtk_file_chooser_dialog_new ("Export File",
                                      NULL,
                                      GTK_FILE_CHOOSER_ACTION_SAVE,
                                      "Cancel", GTK_RESPONSE_CANCEL,
                                      "Export", GTK_RESPONSE_ACCEPT,
                                      NULL);
	{
		GtkFileFilter *filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "C source file (*.c)");
		gtk_file_filter_add_pattern(filter, "*.c");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
		filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "All Files");
		gtk_file_filter_add_pattern(filter, "*");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
	}
	if (state->export_filename) {
		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(dialog), state->export_filename);
	} else {
		gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "untitled.c");
	}
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		FILE *file;
		
		file = fopen(filename, "re");
		if (file) {
			fclose(file);
			char message[MAX_STRING];
			snprintf(message, MAX_STRING, "File \"%s\" \n already exists, do you want to overwrite it?", filename);
			if (!confirm_dialog(GTK_WINDOW(dialog), "Overwrite file",
						message,
						"Overwrite",
						"Cancel")) {
				g_free(filename);
				gtk_widget_destroy(dialog);
				return;
			}
		}

		file = fopen(filename, "we");
		unsigned int max_beat = beat->beat;
		fprintf(file, "#define BPM %s\n", gtk_entry_get_text(GTK_ENTRY(state->bpm)));
		fprintf(file, "%s", preamble);
		{
			struct beat *head = state->note_grid.beats;
			while (head) {
				max_beat = head->beat;
				head = head->next;
			}
		}
		for (unsigned int i = 0; (i <= max_beat) && beat; i++) {
			if (i < beat->beat) {
				fprintf(file, "\trest(SEMIQUAVER);\n");
				continue;
			}
			int num_separated = 0;
			note = beat->note_list;
			fprintf(file, "\tbeep(SEMIQUAVER, %d, ", num_notes(note));
			while (note->next) {
				fprintf(file, "%s, ", note_names[note->note]);
				if (note->state == separate) {
					num_separated++;
				}
				note = note->next;
			}
			fprintf(file, "%s);\n", note_names[note->note]);
			if (note->state == separate) {
				num_separated++;
			}
			if (num_separated > 0) {
				note = beat->note_list;
				if (num_separated == num_notes(note)) {
					fprintf(file, "\trest(SEPARATION);\n");
					beat = beat->next;
					continue;
				}
				fprintf(file, "\tbeep(SEPARATION, %d", num_notes(note) - num_separated);
				while (note->next) {
					if (note->state == held) {
						fprintf(file, ", %s", note_names[note->note]);
					}
					note = note->next;
				}
				if (note->state == held) {
					fprintf(file, ", %s", note_names[note->note]);
				}
				fprintf(file, ");\n");
			}
			beat = beat->next;
		}
		fprintf(file, "%s", end_string);
		g_free(filename);
		fclose(file);
	}
	gtk_widget_destroy(GTK_WIDGET(dialog));
}

static void save(GtkWidget *widget, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	struct beat *beat = state->note_grid.beats;
	struct note *note;
	GtkWidget *dialog;
	gint res;
	if (!beat) {
		return;
	}

	dialog = gtk_file_chooser_dialog_new ("Save File",
                                      NULL,
                                      GTK_FILE_CHOOSER_ACTION_SAVE,
                                      "Cancel", GTK_RESPONSE_CANCEL,
                                      "Save", GTK_RESPONSE_ACCEPT,
                                      NULL);
	{
		GtkFileFilter *filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "Geep Script (*.geep)");
		gtk_file_filter_add_pattern(filter, "*.geep");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
		filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "All Files");
		gtk_file_filter_add_pattern(filter, "*");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
	}
	if (state->save_filename) {
		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(dialog), state->save_filename);
	} else {
		gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "untitled.geep");
	}
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		FILE *file;
		
		/* TODO: auto-append .geep to filename */
		file = fopen(filename, "re");
		if (file) {
			fclose(file);
			char message[MAX_STRING];
			snprintf(message, MAX_STRING, "File \"%s\" \n already exists, do you want to overwrite it?", filename);
			if (!confirm_dialog(GTK_WINDOW(dialog), "Overwrite file",
						message,
						"Overwrite",
						"Cancel")) {
				g_free(filename);
				gtk_widget_destroy(dialog);
				return;
			}
		}

		file = fopen(filename, "we");
		fprintf(file, "%s\n", gtk_entry_get_text(GTK_ENTRY(state->bpm)));
		while (beat) {
			note = beat->note_list;
			fprintf(file, "%d ", beat->beat);
			while (note->next) {
				fprintf(file, "%d ", note->note);
				fprintf(file, "%d ", note->state);
				note = note->next;
			}
			fprintf(file, "%d ", note->note);
			fprintf(file, "%d\n", note->state);
			beat = beat->next;
		}
		g_free(filename);
		fclose(file);
	}
	gtk_widget_destroy(dialog);
}

static void load(GtkWidget *widget, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	int note;
	int beat;
	GtkWidget *dialog;
	gint res;

	dialog = gtk_file_chooser_dialog_new ("Load File",
                                      NULL,
                                      GTK_FILE_CHOOSER_ACTION_OPEN,
                                      "Cancel",
                                      GTK_RESPONSE_CANCEL,
                                      "Load",
                                      GTK_RESPONSE_ACCEPT,
                                      NULL);
	{
		GtkFileFilter *filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "Geep Script (*.geep)");
		gtk_file_filter_add_pattern(filter, "*.geep");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
		filter = gtk_file_filter_new();
		gtk_file_filter_set_name(filter, "All Files");
		gtk_file_filter_add_pattern(filter, "*");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
	}
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		char line[MAX_STRING];
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		FILE *file = fopen(filename, "re");
		if (!file) {
			gtk_widget_destroy(dialog);
			return;
		}
		if (!confirm_dialog(GTK_WINDOW(dialog), "Load file", "Are you sure? You will lose any unsaved work.", "Yes", "No")) {
			g_free(filename);
			fclose(file);
			gtk_widget_destroy(dialog);
			return;
		}
		note_grid_clear(&state->note_grid);
		fgets(line, MAX_STRING, file);
		sprintf(line, "%ld", strtol(line, NULL, 10));
		gtk_entry_set_text(GTK_ENTRY(state->bpm), line);
		errno = 0;
		while (fgets(line, MAX_STRING, file)) {
			char *cursor;
			beat = strtol(line, &cursor, 10);
			while (!errno) {
				char *tmp = cursor;
				note = strtol(cursor, &cursor, 10);
				if (tmp == cursor) {
					break;
				}
				toggle_note(&state->note_grid, note, beat)->state = strtol(cursor, &cursor, 10);
				//get_note_beat(&state->note_grid, note, beat)->state = strtol(cursor, &cursor, 10);
			}
		}
		g_free(filename);
		fclose(file);
	}
	gtk_widget_destroy(dialog);
	update_grid(&state->note_grid);
}

int main(int argc, char *argv[]) 
{
	GObject *grid; 
	GtkAccelGroup *accel = gtk_accel_group_new();
	GError *error = NULL;
	struct application_state state = {
		.note_grid = {
			.note_offset = 48 - ROWS / 2,
			.beat_offset = 0
		},
		.builder = gtk_builder_new(),
		.cur_x = 0,
		.cur_y = 0,
		.export_filename = NULL,
		.save_filename = NULL
	};

	gtk_init(&argc, &argv); 

	/* Load the UI description */
	state.builder = gtk_builder_new ();
	if (gtk_builder_add_from_file(state.builder, "geepui.ui", &error) == 0)
	{
		g_printerr("Error loading file: %s\n", error->message);
		g_clear_error(&error);
		return 1;
	}

	state.window = GTK_WIDGET(gtk_builder_get_object(state.builder, "window"));
	gtk_widget_add_events(state.window, GDK_SCROLL_MASK);
	g_signal_connect(state.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(state.window, "scroll-event", G_CALLBACK(scroll), &state);
	gtk_window_add_accel_group(GTK_WINDOW(state.window), accel);

	/* Generate main note button grid */
	grid = gtk_builder_get_object(state.builder, "note_grid");
	state.grid = gtk_grid_new();
	gtk_grid_set_row_homogeneous(GTK_GRID(state.grid), true);
	gtk_grid_set_column_homogeneous(GTK_GRID(state.grid), true);
	{
		GtkWidget *event = gtk_event_box_new();
		gtk_widget_add_events(event, GDK_BUTTON_PRESS_MASK);
		gtk_widget_add_events(event, GDK_POINTER_MOTION_MASK);
		g_signal_connect(event, "button-press-event", G_CALLBACK(button_press), &state.note_grid);
		g_signal_connect(event, "motion-notify-event", G_CALLBACK(button_held), &state.note_grid);
		gtk_container_add(GTK_CONTAINER(event), state.grid);
		gtk_grid_attach(GTK_GRID(grid), event, 0, 0, COLUMNS, ROWS);
	}
	g_signal_connect(grid, "key-press-event", G_CALLBACK(key_press), &state);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int idx = i * COLUMNS + j;
			GtkWidget *drawing = gtk_drawing_area_new();
			state.note_grid.buttons[idx] = (struct note_button){
				.x = j, .y = i,
				.grid = &state.note_grid,
				.widget = drawing
			};
			g_signal_connect(drawing, "draw", G_CALLBACK(draw_note), &state.note_grid.buttons[idx]);
			gtk_grid_attach(GTK_GRID(state.grid), drawing, j, i, 1, 1); 
		}
	}

	/* Create the lhs keyboard and attach it */
	state.keyboard = gtk_drawing_area_new();
	g_signal_connect(state.keyboard, "draw", G_CALLBACK(draw_keyboard), &state.note_grid);
	for (int i = 0; i < KEY_WIDTH; i++) {
		gtk_grid_insert_column(GTK_GRID(grid), 0);
	}
	gtk_grid_attach(GTK_GRID(grid), state.keyboard, 0, 0, KEY_WIDTH, ROWS);
	
	/* Create the top beat bar and attach it */
	state.beat_bar = gtk_drawing_area_new();
	g_signal_connect(state.beat_bar, "draw", G_CALLBACK(draw_beat_bar), &state.note_grid);
	gtk_grid_insert_row(GTK_GRID(grid), 0);
	gtk_grid_attach(GTK_GRID(grid), state.beat_bar, KEY_WIDTH, 0, COLUMNS, 1);
	
	/* Connect up the menu item signals */
	gtk_builder_add_callback_symbol(state.builder, "new", G_CALLBACK(new));
	gtk_builder_add_callback_symbol(state.builder, "save", G_CALLBACK(save));
	gtk_builder_add_callback_symbol(state.builder, "export", G_CALLBACK(export));
	gtk_builder_add_callback_symbol(state.builder, "load", G_CALLBACK(load));
	gtk_builder_connect_signals(state.builder, &state);

	state.menu.new = GTK_WIDGET(gtk_builder_get_object(state.builder, "new"));
	state.menu.save = GTK_WIDGET(gtk_builder_get_object(state.builder, "save"));
	state.menu.export = GTK_WIDGET(gtk_builder_get_object(state.builder, "export"));
	state.menu.load = GTK_WIDGET(gtk_builder_get_object(state.builder, "load"));

	gtk_widget_add_accelerator(state.menu.new, "activate", accel, GDK_KEY_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(state.menu.save, "activate", accel, GDK_KEY_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(state.menu.export, "activate", accel, GDK_KEY_e, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(state.menu.load, "activate", accel, GDK_KEY_l, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	/* BPM entry */
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("BPM"), 0, 0, 2, 1);
	state.bpm = gtk_entry_new_with_buffer(gtk_entry_buffer_new("120", -1));
	gtk_entry_set_width_chars(GTK_ENTRY(state.bpm), 3);
	gtk_grid_attach(GTK_GRID(grid), state.bpm, 2, 0, KEY_WIDTH - 2, 1);

	update_menu_state(&state);
	gtk_widget_show_all(state.window); 
	gtk_main(); 
	return 0; 
}
