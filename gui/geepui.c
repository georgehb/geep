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
#define MAX_LINE 512 /* Maximum line length to read */
#define KEY_WIDTH 3

struct application_state {
	struct note_grid grid;
	GtkBuilder *builder;
};

static gboolean button_press(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
	if (event->type != GDK_BUTTON_PRESS) {
		return false;
	}
	struct note_grid *grid = (struct note_grid *)data;
	/* TODO: align properly with buttons */
	grid->cur_x = event->x * COLUMNS / gtk_widget_get_allocated_width(widget);
	grid->cur_y = event->y * ROWS / gtk_widget_get_allocated_height(widget);
	unsigned int note = grid->note_offset + grid->cur_y;
	unsigned int beat = grid->beat_offset + grid->cur_x;
	toggle_note(grid, note, beat);
	gtk_widget_queue_draw(widget);
	return true;
}

static gboolean button_held(GtkWidget *widget, GdkEventMotion *event, gpointer data)
{
	/* TODO: Better drag functionality */
	if (!(event->state & GDK_BUTTON1_MASK)) {
		return false;
	}
	struct note_grid *grid = (struct note_grid *)data;
	unsigned int x = event->x * COLUMNS / gtk_widget_get_allocated_width(widget);
	unsigned int y = event->y * ROWS / gtk_widget_get_allocated_height(widget);
	if (x == grid->cur_x && y == grid->cur_y) {
		return false;
	}
	grid->cur_x = x;
	grid->cur_y = y;
	unsigned int note = grid->note_offset + grid->cur_y;
	unsigned int beat = grid->beat_offset + grid->cur_x;
	toggle_note(grid, note, beat);
	gtk_widget_queue_draw(widget);
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
	struct note_grid *note_grid = (struct note_grid *)data;
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
	gtk_widget_queue_draw(note_grid->keyboard);
	gtk_widget_queue_draw(note_grid->beat_bar);
}

static void export(GtkWidget *widget, gpointer data)
{
	(void) widget;
	struct application_state *state = (struct application_state *)data;
	struct beat *beat = state->grid.beats;
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
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		FILE *file;
		
		file = fopen(filename, "re");
		if (file) {
			fclose(file);
			GtkWidget *confirm = gtk_message_dialog_new(NULL,
					GTK_DIALOG_MODAL,
					GTK_MESSAGE_QUESTION,
					GTK_BUTTONS_NONE,
					"File \"%s\" already exists, do you want to overwrite it?",
					filename);
			gtk_dialog_add_buttons(GTK_DIALOG(confirm),
					"Cancel", GTK_RESPONSE_CANCEL,
					"Overwrite", GTK_RESPONSE_ACCEPT,
					NULL);
			if (gtk_dialog_run(GTK_DIALOG(confirm)) != GTK_RESPONSE_ACCEPT) {
				g_free(filename);
				gtk_widget_destroy(confirm);
				gtk_widget_destroy(dialog);
				return;
			}
			gtk_widget_destroy(confirm);
		}

		file = fopen(filename, "we");
		unsigned int max_beat = beat->beat;
		fprintf(file, "#define BPM %s\n", gtk_entry_get_text(GTK_ENTRY(state->grid.bpm)));
		fprintf(file, "%s", preamble);
		{
			struct beat *head = state->grid.beats;
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
			note = beat->note_list;
			fprintf(file, "\tbeep(SEMIQUAVER, %d, ", num_notes(note));
			while (note->next) {
				fprintf(file, "%s, ", note_names[note->note]);
				note = note->next;
			}
			fprintf(file, "%s);\n", note_names[note->note]);
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
	struct note_grid *grid = (struct note_grid *)data;
	struct beat *beat = grid->beats;
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
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		FILE *file;
		
		file = fopen(filename, "re");
		if (file) {
			fclose(file);
			GtkWidget *confirm = gtk_message_dialog_new(NULL,
					GTK_DIALOG_MODAL,
					GTK_MESSAGE_QUESTION,
					GTK_BUTTONS_NONE,
					"File \"%s\" already exists, do you want to overwrite it?",
					filename);
			gtk_dialog_add_buttons(GTK_DIALOG(confirm),
					"Cancel", GTK_RESPONSE_CANCEL,
					"Overwrite", GTK_RESPONSE_ACCEPT,
					NULL);
			if (gtk_dialog_run(GTK_DIALOG(confirm)) != GTK_RESPONSE_ACCEPT) {
				g_free(filename);
				gtk_widget_destroy(confirm);
				gtk_widget_destroy(dialog);
				return;
			}
			gtk_widget_destroy(confirm);
		}

		file = fopen(filename, "we");
		fprintf(file, "%s\n", gtk_entry_get_text(GTK_ENTRY(grid->bpm)));
		while (beat) {
			note = beat->note_list;
			fprintf(file, "%d ", beat->beat);
			while (note->next) {
				fprintf(file, "%d ", note->note);
				note = note->next;
			}
			fprintf(file, "%d\n", note->note);
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
	struct note_grid *grid = (struct note_grid *)data;
	int note;
	int beat;
	GtkWidget *dialog;
	gint res;

	dialog = gtk_file_chooser_dialog_new ("Load File",
                                      NULL,
                                      GTK_FILE_CHOOSER_ACTION_SAVE,
                                      "Cancel",
                                      GTK_RESPONSE_CANCEL,
                                      "Load",
                                      GTK_RESPONSE_ACCEPT,
                                      NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT) {
		note_grid_clear(grid);
		char line[MAX_LINE];
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
		FILE *file = fopen(filename, "re");
		fgets(line, MAX_LINE, file);
		sprintf(line, "%ld", strtol(line, NULL, 10));
		gtk_entry_set_text(GTK_ENTRY(grid->bpm), line);
		while (fgets(line, MAX_LINE, file)) {
			char *cursor;
			beat = strtol(line, &cursor, 10);
			while (!errno) {
				char *tmp = cursor;
				note = strtol(cursor, &cursor, 10);
				if (tmp == cursor) {
					break;
				}
				toggle_note(grid, note, beat);
			}
		}
		g_free(filename);
		fclose(file);
	}
	gtk_widget_destroy(dialog);
	update_grid(grid);
}

int main(int argc, char *argv[]) 
{ 
	GObject *window;
	GObject *grid; 
	GError *error = NULL;
	struct application_state state = {
		.grid = {
			.note_offset = 48 - ROWS / 2,
			.beat_offset = 0,
			.cur_x = 0,
			.cur_y = 0
		},
		.builder = gtk_builder_new()
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

	window = gtk_builder_get_object(state.builder, "window");
	gtk_widget_add_events(GTK_WIDGET(window), GDK_SCROLL_MASK);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(window, "scroll-event", G_CALLBACK(scroll), &state.grid);

	/* Generate main note button grid */
	grid = gtk_builder_get_object(state.builder, "note_grid");
	state.grid.grid = gtk_grid_new();
	gtk_grid_set_row_homogeneous(GTK_GRID(state.grid.grid), true);
	gtk_grid_set_column_homogeneous(GTK_GRID(state.grid.grid), true);
	{
		GtkWidget *event = gtk_event_box_new();
		gtk_widget_add_events(event, GDK_BUTTON_PRESS_MASK);
		gtk_widget_add_events(event, GDK_POINTER_MOTION_MASK);
		g_signal_connect(event, "button-press-event", G_CALLBACK(button_press), &state.grid);
		g_signal_connect(event, "motion-notify-event", G_CALLBACK(button_held), &state.grid);
		gtk_container_add(GTK_CONTAINER(event), state.grid.grid);
		gtk_grid_attach(GTK_GRID(grid), event, 0, 0, COLUMNS, ROWS);
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int idx = i * COLUMNS + j;
			GtkWidget *drawing = gtk_drawing_area_new();
			state.grid.buttons[idx] = (struct note_button){
				.x = j, .y = i,
				.grid = &state.grid,
				.widget = drawing
			};
			g_signal_connect(drawing, "draw", G_CALLBACK(draw_note), &state.grid.buttons[idx]);
			gtk_grid_attach(GTK_GRID(state.grid.grid), drawing, j, i, 1, 1); 
		}
	}

	/* Create the lhs keyboard and attach it */
	state.grid.keyboard = gtk_drawing_area_new();
	g_signal_connect(state.grid.keyboard, "draw",
			G_CALLBACK(draw_keyboard), &state.grid);
	for (int i = 0; i < KEY_WIDTH; i++) {
		gtk_grid_insert_column(GTK_GRID(grid), 0);
	}
	gtk_grid_attach(GTK_GRID(grid), state.grid.keyboard, 0, 0, KEY_WIDTH, ROWS);
	
	/* Create the top beat bar and attach it */
	state.grid.beat_bar = gtk_drawing_area_new();
	g_signal_connect(state.grid.beat_bar, "draw",
			G_CALLBACK(draw_beat_bar), &state.grid);
	gtk_grid_insert_row(GTK_GRID(grid), 0);
	gtk_grid_attach(GTK_GRID(grid), state.grid.beat_bar, KEY_WIDTH, 0, COLUMNS, 1);
	
	gtk_builder_add_callback_symbol(state.builder, "save", G_CALLBACK(save));
	gtk_builder_add_callback_symbol(state.builder, "export", G_CALLBACK(export));
	gtk_builder_add_callback_symbol(state.builder, "load", G_CALLBACK(load));
	gtk_builder_connect_signals(state.builder, &state);

	/* BPM entry */
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("BPM"), 0, 0, 1, 1);
	state.grid.bpm = gtk_entry_new_with_buffer(gtk_entry_buffer_new("120", -1));
	gtk_entry_set_width_chars(GTK_ENTRY(state.grid.bpm), 3);
	gtk_grid_attach(GTK_GRID(grid), state.grid.bpm, 1, 0, KEY_WIDTH - 1, 1);

	printf("%d\n", gtk_widget_get_has_window(state.grid.grid));

	gtk_widget_show_all(GTK_WIDGET(window)); 
	gtk_main(); 
	return 0; 
}
