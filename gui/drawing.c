#include "drawing.h"
#include "note_grid.h"
#include "notes.h"
#include <gtk/gtk.h>
#include <math.h>

#ifndef M_PI
#define M_PI (4*atan(1))
#endif

#define CORNER_RADIUS 5

static bool is_black(int note)
{
	note %= 12;
	return (note == 2 || note == 4 || note == 7 || note == 9 || note == 11);
}

gboolean draw_keyboard(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	guint width;
	guint height;
	GdkRGBA white = (GdkRGBA){1.0, 1.0, 1.0, 1.0};
	GdkRGBA black = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	struct note_grid *grid = (struct note_grid *)data;

	width = gtk_widget_get_allocated_width(widget);
	height = gtk_widget_get_allocated_height(widget);

	/* Render the white background first */
	cairo_rectangle(cr, 0, 0, width, height);
	gdk_cairo_set_source_rgba(cr, &white);
	cairo_fill(cr);
	
	/* Then render the black keys on top */
	cairo_save(cr);
	for (int i = 0; i < ROWS; i++) {
		guint button_height = gtk_widget_get_allocated_height(grid->buttons[i * COLUMNS].widget);
		int note = i + 1 + grid->note_offset;
		if (is_black(note)) {
			cairo_rectangle(cr, width / 3.0, 0, width, button_height);
		}
		cairo_translate(cr, 0, button_height);
	}
	gdk_cairo_set_source_rgba(cr, &black);
	cairo_fill(cr);
	cairo_restore(cr);
	
	/* Then draw the space between keys */
	cairo_save(cr);
	for (unsigned int i = 0; i < ROWS; i++) {
		guint button_height = gtk_widget_get_allocated_height(grid->buttons[i * COLUMNS].widget);
		int note = (i + 1 + grid->note_offset) % 12;
		if (is_black(note)) {
			/* Under black keys */
			cairo_rectangle(cr, 0, 0.5 * button_height - 2 , width, 4);
		} else if (note == 6 || note == 1) {
			/* Between white keys */
			cairo_rectangle(cr, 0, -2, width, 4);
		}
		cairo_translate(cr, 0, button_height);
	}
	gdk_cairo_set_source_rgba(cr, &black);
	cairo_fill(cr);
	cairo_restore(cr);

	/* And finally the labels */
	PangoLayout *layout;
	PangoFontDescription *desc;
  	layout = pango_cairo_create_layout(cr);
	desc = pango_font_description_from_string("Monospace, 10");
	pango_layout_set_font_description(layout, desc);
	pango_font_description_free(desc);

	cairo_save(cr);
	cairo_translate(cr, 5.0 * width / 6.0, 0);
	for (int i = 0; i < ROWS; i++) {
		guint button_height = gtk_widget_get_allocated_height(grid->buttons[i * COLUMNS].widget);
		int note = (i + 1 + grid->note_offset) % 12;
		if (is_black(note)) {
				gdk_cairo_set_source_rgba(cr, &white);
		} else {
				gdk_cairo_set_source_rgba(cr, &black);
		}
		int text_width;
		int text_height;
		cairo_save(cr);
		pango_layout_set_text(layout, note_names[grid->note_offset + i], -1);
		pango_cairo_update_layout(cr, layout);
		pango_layout_get_pixel_size(layout, &text_width, &text_height);
		cairo_translate(cr, -text_width / 2.0, 0.5 * button_height - text_height / 2.0);
		pango_cairo_show_layout(cr, layout);
		cairo_restore(cr);
		cairo_translate(cr, 0, button_height);
	}
	cairo_restore(cr);

	return FALSE;
}

gboolean draw_beat_bar(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	#define BAR_LENGTH 16
	guint width;
	guint height;
	GdkRGBA white = (GdkRGBA){1.0, 1.0, 1.0, 1.0};
	GdkRGBA black = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	GtkStyleContext *context;
	struct note_grid *grid = (struct note_grid *)data;

	context = gtk_widget_get_style_context(widget);
	width = gtk_widget_get_allocated_width(widget);
	height = gtk_widget_get_allocated_height(widget);
	gtk_render_background(context, cr, 0, 0, width, height);
	
	cairo_save(cr);
	/*for (int i = 0; i < COLUMNS; i++) {
		guint button_width = gtk_widget_get_allocated_width(grid->buttons[i].widget);
		cairo_rectangle(cr, 1, 0, button_width-2, height);
		cairo_translate(cr, button_width, 0);
	}*/
	cairo_rectangle(cr, 0, 0, width, height);
	gdk_cairo_set_source_rgba(cr, &white);
	cairo_fill(cr);
	cairo_restore(cr);

	/* Then the bar lines */
	cairo_save(cr);
	gdk_cairo_set_source_rgba(cr, &black);
	for (int i = 0; i < COLUMNS; i++) {
		guint button_width = gtk_widget_get_allocated_width(grid->buttons[i].widget);
		if (!((grid->beat_offset + i) % BAR_LENGTH)) {
			cairo_rectangle(cr, -1, 0, 2, height);
		} else if ((grid->beat_offset + i) % 4) {
			cairo_rectangle(cr, -1, 0.75 * height, 2, 0.25 * height);
		} else {
			cairo_rectangle(cr, -1, 0.5 * height, 2, 0.5 * height);
		}
		cairo_fill(cr);
		cairo_translate(cr, button_width, 0);
	}
	cairo_restore(cr);
	
	/* Then the labels */
	/* Label string only needs to go up to 11 to hold all possible uint32
	 * values, but better to be safe */
	PangoLayout *layout;
	PangoFontDescription *desc;
  	layout = pango_cairo_create_layout(cr);
	desc = pango_font_description_from_string("Monospace, 10");
	pango_layout_set_font_description(layout, desc);
	pango_font_description_free(desc);

	char beat_str[20];
	cairo_save(cr);
	cairo_translate(cr, 0, 0.5 * height);
	gdk_cairo_set_source_rgba(cr, &black);
	for (int i = 0; i < COLUMNS; i++) {
		guint button_width = gtk_widget_get_allocated_width(grid->buttons[i].widget);
		if ((grid->beat_offset + i) % BAR_LENGTH) {
			cairo_translate(cr, button_width, 0);
			continue;
		}
		snprintf(beat_str, 20, "%d", (grid->beat_offset + i) / BAR_LENGTH + 1);
		int text_width;
		int text_height;
		cairo_save(cr);
		pango_layout_set_text(layout, beat_str, -1);
		pango_cairo_update_layout(cr, layout);
		pango_layout_get_pixel_size(layout, &text_width, &text_height);
		cairo_translate(cr, 0.5 * (button_width - text_width), -0.5 * text_height);
		pango_cairo_show_layout(cr, layout);
		cairo_fill(cr);
		cairo_restore(cr);
		cairo_translate(cr, button_width, 0);
	}
	cairo_restore(cr);

	return FALSE;
}

gboolean draw_note(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	guint width;
	guint height;
	GtkStyleContext *context;
	struct note_button *button = (struct note_button *)data;
	unsigned int note = button->grid->note_offset + button->y;
	unsigned int beat = button->grid->beat_offset + button->x;
	struct note *n = get_note_beat(button->grid, note, beat);
	struct note *n_prev = get_note_beat(button->grid, note, beat-1);
	struct note *n_next = get_note_beat(button->grid, note, beat+1);
	static GtkWidget *b = NULL;
	if (!b) {
		b = gtk_button_new();
	}
	context = gtk_widget_get_style_context(b);

	width = gtk_widget_get_allocated_width(widget);
	height = gtk_widget_get_allocated_height(widget);

	if (!n) {
		gtk_style_context_set_state(context, GTK_STATE_FLAG_NORMAL);
		gtk_render_background(context, cr, 0, 0, width, height);
		gtk_render_frame(context, cr, 0, 0, width, height);
	} else {
		switch (n->state) {
			case off:
				gtk_style_context_set_state(context, GTK_STATE_FLAG_NORMAL);
				break;
			case separate:
			case held:
				gtk_style_context_set_state(context, GTK_STATE_FLAG_ACTIVE);
				break;
		}
		if (n_prev && n_prev->state == held && n_next && n->state == held) {
			gtk_render_background(context, cr, -width, 0, 3*width, height);
			gtk_render_frame(context, cr, -width, 0, 3*width, height);
		} else if (n_prev && n_prev->state == held) {
			gtk_render_background(context, cr, -width, 0, 2*width, height);
			gtk_render_frame(context, cr, -width, 0, 2*width, height);
		} else if (n_next && n->state == held) {
			gtk_render_background(context, cr, 0, 0, 2*width, height);
			gtk_render_frame(context, cr, 0, 0, 2*width, height);
		} else {
			gtk_render_background(context, cr, 0, 0, width, height);
			gtk_render_frame(context, cr, 0, 0, width, height);
		}
	}

	cairo_fill(cr);
	return false;
}
