#ifndef DRAWING_H
#define DRAWING_H

#include <gtk/gtk.h>
gboolean draw_keyboard(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw_beat_bar(GtkWidget *widget, cairo_t *cr, gpointer data);

#endif /* DRAWING_H */
