#ifndef DRAWING_H
#define DRAWING_H

#include <gtk/gtk.h>

struct note_button {
	int x;
	int y;
	struct note_grid *grid;
	GtkWidget *widget;
};

gboolean draw_keyboard(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw_beat_bar(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw_note(GtkWidget *widget, cairo_t *cr, gpointer data);

#endif /* DRAWING_H */
