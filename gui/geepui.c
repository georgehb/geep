#include "drawing.h"
#include "note_grid.h"
#include "notes.h"
#include "preamble.h"
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_BEATS UINT32_MAX
#define KEY_WIDTH 3

static void note_button(GtkWidget *button, gpointer data)
{
	struct note_grid *grid = (struct note_grid *)data;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int idx = i * COLUMNS + j;
			if (button == grid->buttons[idx]) {
				unsigned int note = grid->note_offset + i;
				unsigned int beat = grid->beat_offset + j;
				toggle_note(grid, note, beat);
			}
		}
	}
}

static void update_grid(struct note_grid *grid)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int idx = i * COLUMNS + j;
			unsigned int note = grid->note_offset + i;
			unsigned int beat = grid->beat_offset + j;
			gtk_toggle_button_set_active(
					GTK_TOGGLE_BUTTON(grid->buttons[idx]),
					contains_note_beat(grid, note, beat)
					);
		}
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
	struct note_grid *grid = (struct note_grid *)data;
	struct beat *beat = grid->beats;
	struct note *note;
	if (!beat) {
		return;
	}
	unsigned int max_beat = beat->beat;
	printf("#define BPM %s\n", gtk_entry_get_text(GTK_ENTRY(grid->bpm)));
	printf("%s", preamble);
	{
		struct beat *head = grid->beats;
		while (head) {
			max_beat = head->beat;
			head = head->next;
		}
	}
	for (unsigned int i = 0; (i <= max_beat) && beat; i++) {
		if (i < beat->beat) {
			printf("\trest(SEMIQUAVER);\n");
			continue;
		}
		note = beat->note_list;
		printf("\tbeep(SEMIQUAVER, %d, ", num_notes(note));
		while (note->next) {
			printf("%s, ", note_names[note->note]);
			note = note->next;
		}
		printf("%s);\n", note_names[note->note]);
		beat = beat->next;
	}
	printf("%s", end_string);
}

static void save(GtkWidget *widget, gpointer data)
{
	(void) widget;
	struct note_grid *grid = (struct note_grid *)data;
	struct beat *beat = grid->beats;
	struct note *note;
	if (!beat) {
		return;
	}
	printf("%s\n", gtk_entry_get_text(GTK_ENTRY(grid->bpm)));
	while (beat) {
		note = beat->note_list;
		printf("%d ", beat->beat);
		while (note->next) {
			printf("%d,", note->note);
			note = note->next;
		}
		printf("%d\n", note->note);
		beat = beat->next;
	}
}

int main(int argc, char *argv[]) 
{ 
	GtkWidget *window;
	GtkWidget *grid; 
	GtkWidget *save_button; 
	GtkWidget *export_button; 
	GtkWidget *menu_bar;
	struct note_grid note_grid = { .note_offset = 48 - ROWS / 2, .beat_offset = 0 };
	gtk_init(&argc, &argv); 
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
	gtk_widget_add_events(window, GDK_SCROLL_MASK);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(window, "scroll-event", G_CALLBACK(scroll), &note_grid);

	/* Generate main note button grid */
	grid = gtk_grid_new();
	gtk_grid_set_row_homogeneous(GTK_GRID(grid), true);
	gtk_grid_set_column_homogeneous(GTK_GRID(grid), true);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int idx = i * COLUMNS + j;
			note_grid.buttons[idx] = gtk_toggle_button_new();
			gtk_widget_set_size_request(note_grid.buttons[idx], 10, 10);
			g_signal_connect(note_grid.buttons[idx], "pressed",
					G_CALLBACK(note_button), &note_grid);
			gtk_grid_attach(GTK_GRID(grid), note_grid.buttons[idx], j, i, 1, 1); 
		}
	}

	/* Create the lhs keyboard and attach it */
	note_grid.keyboard = gtk_drawing_area_new();
	g_signal_connect(note_grid.keyboard, "draw",
			G_CALLBACK(draw_keyboard), &note_grid);
	for (int i = 0; i < KEY_WIDTH; i++) {
		gtk_grid_insert_column(GTK_GRID(grid), 0);
	}
	gtk_grid_attach(GTK_GRID(grid), note_grid.keyboard, 0, 0, KEY_WIDTH, ROWS);
	
	/* Create the top beat bar and attach it */
	note_grid.beat_bar = gtk_drawing_area_new();
	g_signal_connect(note_grid.beat_bar, "draw",
			G_CALLBACK(draw_beat_bar), &note_grid);
	gtk_grid_insert_row(GTK_GRID(grid), 0);
	gtk_grid_attach(GTK_GRID(grid), note_grid.beat_bar, KEY_WIDTH, 0, COLUMNS, 1);
	
	/* Save button */
	save_button = gtk_button_new_with_label("Save");
	g_signal_connect(save_button, "pressed",
			G_CALLBACK(save), &note_grid);
	gtk_grid_attach(GTK_GRID(grid), save_button, 0, ROWS + 1, COLUMNS + KEY_WIDTH - (COLUMNS + KEY_WIDTH) / 2, 1);

	/* Export button */
	export_button = gtk_button_new_with_label("Export");
	g_signal_connect(export_button, "pressed",
			G_CALLBACK(export), &note_grid);
	gtk_grid_attach(GTK_GRID(grid), export_button, COLUMNS + KEY_WIDTH - (COLUMNS + KEY_WIDTH) / 2, ROWS + 1, (COLUMNS + KEY_WIDTH) / 2, 1);
		
	/* Menu bar */
	menu_bar = gtk_menu_bar_new();
	{
		GtkWidget *menu_item = gtk_menu_item_new_with_label("File");
		GtkWidget *submenu = gtk_menu_new();
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), submenu);
		gtk_container_add(GTK_CONTAINER(menu_bar), menu_item);
	}


	/* BPM entry */
	{
		GtkWidget *label = gtk_label_new("BPM");
		gtk_widget_set_size_request(label, 10, 10);
		gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
	}
	note_grid.bpm = gtk_entry_new_with_buffer(gtk_entry_buffer_new("120", -1));
	gtk_entry_set_width_chars(GTK_ENTRY(note_grid.bpm), 3);
	gtk_grid_attach(GTK_GRID(grid), note_grid.bpm, 1, 0, KEY_WIDTH - 1, 1);

	{
		GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
		gtk_container_add(GTK_CONTAINER(window), box); 
		gtk_box_pack_start(GTK_BOX(box), menu_bar, false, false, 0);
		gtk_box_pack_start(GTK_BOX(box), grid, true, true, 0);
	}
	gtk_widget_show_all(window); 
	gtk_main(); 
	return 0; 
}
