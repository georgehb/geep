#include "notes.h"
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdint.h>

#define ROWS 30
#define COLUMNS 20
#define BUTTONS (ROWS * COLUMNS)
#define MAX_BEATS UINT32_MAX
#define KEY_WIDTH 3

struct note {
	unsigned int beat;
	struct note *next;
};

struct note *add_note(struct note **head, unsigned int beat)
{
	struct note *note = malloc(sizeof(struct note));
	note->beat = beat;
	note->next = NULL;
	if (!(*head)) {
		*head = note;
		return note;
	}
	while ((*head)->next && (*head)->next->beat < beat) {
		head = &(*head)->next;
	}
	note->next = (*head)->next;
	(*head)->next = note;
	return note;
}

void remove_note(struct note **head, unsigned int beat)
{
	while ((*head)->beat != beat) {
		head = &(*head)->next;
	}
	struct note *tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

bool contains_note(struct note *head, unsigned int beat)
{
	while (head && head->beat != beat) {
		head = head->next;
	}
	return (head != NULL);
}

void toggle_note(struct note **head, unsigned int beat)
{
	if (contains_note(*head, beat)) {
		remove_note(head, beat);
		g_print("removed %d\n", beat);
	} else {
		add_note(head, beat);
		g_print("added %d\n", beat);
	}
}

struct note_grid {
	GtkWidget *buttons[BUTTONS];
	GtkWidget *keyboard;
	struct note *notes[NUM_NOTES];
	unsigned int note_offset;
	unsigned int beat_offset;
};

static void note_button(GtkWidget *button, gpointer data)
{
	struct note_grid *grid = (struct note_grid *)data;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int idx = i * COLUMNS + j;
			if (button == grid->buttons[idx]) {
				unsigned int note = grid->note_offset + i;
				unsigned int beat = grid->beat_offset + j;
				toggle_note(&grid->notes[note], beat);
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
					contains_note(grid->notes[note], beat)
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
}

gboolean draw_keyboard(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	guint width;
	guint height;
	guint button_height;
	GdkRGBA color;
	GtkStyleContext *context;
	struct note_grid *grid = (struct note_grid *)data;

	context = gtk_widget_get_style_context(widget);

	width = gtk_widget_get_allocated_width(widget);
	height = gtk_widget_get_allocated_height(widget);
	button_height = gtk_widget_get_allocated_height(grid->buttons[0]);

	gtk_render_background(context, cr, 0, 0, width, height);

	/* Render the white background first */
	cairo_rectangle(cr, 0, 0,
			width, height);
	color = (GdkRGBA){1.0, 1.0, 1.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	cairo_fill(cr);
	
	/* Then render the black keys on top */
	for (int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		if (note == 2 || note == 4 || note == 7 || note == 9 || note == 11) {
			cairo_rectangle(cr, width / 3.0, i * button_height,
					width, button_height-1);
		}
	}
	color = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	cairo_fill(cr);
	
	/* Then draw the space between white keys under black keys */
	for (unsigned int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		if (note == 2 || note == 4 || note == 7 || note == 9 || note == 11) {
			cairo_rectangle(cr, 0, (i + 0.5) * button_height - 2,
					width, 4);
		}
	}
	color = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	cairo_fill(cr);

	/* And then the space between consecutive white keys */
	for (unsigned int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		if (note == 5 || note == 0) {
			cairo_rectangle(cr, 0, (i + 1) * button_height - 2,
					width, 4);
		}
	}
	color = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	cairo_fill(cr);
	

	/* And finally the labels */
	color = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	for (int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		if (note == 2 || note == 4 || note == 7 || note == 9 || note == 11) {
			continue;
		}
			cairo_move_to(cr, 5.0 * width / 6.0, (i + 0.5) * button_height);
			cairo_show_text(cr, note_names[grid->note_offset + i]);
	}
	
	color = (GdkRGBA){1.0, 1.0, 1.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	for (int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		if (note == 2 || note == 4 || note == 7 || note == 9 || note == 11) {
		cairo_move_to(cr, 4.0 * width / 6.0, (i + 0.5) * button_height);
		cairo_show_text(cr, note_names[grid->note_offset + i]);
		}
	}

	return FALSE;
}

int main(int argc, char *argv[]) 
{ 
	GtkWidget *window, *grid; 
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
	gtk_grid_attach(GTK_GRID(grid), gtk_button_new_with_label("Export"), 0, ROWS, COLUMNS + KEY_WIDTH, 1);

	gtk_container_add(GTK_CONTAINER(window), grid); 
	gtk_widget_show_all(window); 
	gtk_main(); 
	return 0; 
}
