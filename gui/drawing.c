#include "drawing.h"
#include "note_grid.h"
#include "notes.h"

gboolean draw_keyboard(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	guint width;
	guint height;
	guint button_height;
	GdkRGBA color;
	GtkStyleContext *context;
	struct note_grid *grid = (struct note_grid *)data;

	cairo_select_font_face(cr, "Noto Sans Mono", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);

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
	PangoLayout *layout;
	PangoFontDescription *desc;
  	layout = pango_cairo_create_layout (cr);
	desc = pango_font_description_from_string ("Monospace, 10");
	pango_layout_set_font_description (layout, desc);
	pango_font_description_free (desc);

	color = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	for (int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		switch (note) {
			case 2:
			case 4:
			case 7:
			case 9:
			case 11:
				continue;
		}
		int text_width;
		int text_height;
		cairo_save(cr);
		pango_layout_set_text(layout, note_names[grid->note_offset + i], -1);
		pango_cairo_update_layout(cr, layout);
		pango_layout_get_pixel_size(layout, &text_width, &text_height);
		cairo_move_to(cr, 5.0 * width / 6.0 - text_width / 2.0, (i + 0.5) * button_height - text_height / 2.0);
		pango_cairo_show_layout(cr, layout);
		cairo_restore(cr);
	}
	
	color = (GdkRGBA){1.0, 1.0, 1.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	for (int i = 0; i < ROWS; i++) {
		int note = (i + 1 + grid->note_offset) % 12;
		switch (note) {
			case 0:
			case 1:
			case 3:
			case 5:
			case 6:
			case 8:
			case 10:
				continue;
		}
		int text_width;
		int text_height;
		cairo_save(cr);
		pango_layout_set_text(layout, note_names[grid->note_offset + i], -1);
		pango_cairo_update_layout(cr, layout);
		pango_layout_get_pixel_size(layout, &text_width, &text_height);
		cairo_move_to(cr, 5.0 * width / 6.0 - 0.5 * text_width, (i + 0.5) * button_height - 0.5 * text_height);
		pango_cairo_show_layout(cr, layout);
		cairo_restore(cr);
	}

	return FALSE;
}

gboolean draw_beat_bar(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	guint width;
	guint height;
	guint button_width;
	GdkRGBA color;
	GtkStyleContext *context;
	struct note_grid *grid = (struct note_grid *)data;

	context = gtk_widget_get_style_context(widget);

	width = gtk_widget_get_allocated_width(widget);
	height = gtk_widget_get_allocated_height(widget);
	button_width = gtk_widget_get_allocated_width(grid->buttons[0]);

	gtk_render_background(context, cr, 0, 0, width, height);
	
	/* Then render the black keys on top */
	for (int i = 0; i < COLUMNS; i++) {
		cairo_rectangle(cr, i * button_width, 0,
				button_width-1, height);
	}
	color = (GdkRGBA){1.0, 1.0, 1.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	cairo_fill(cr);
	
	/* And finally the labels */
	/* Label string only needs to go up to 11 to hold all possible uint32
	 * values, but better to be safe */
	PangoLayout *layout;
	PangoFontDescription *desc;
  	layout = pango_cairo_create_layout (cr);
	desc = pango_font_description_from_string ("Monospace, 10");
	pango_layout_set_font_description (layout, desc);
	pango_font_description_free (desc);
	char beat_str[20];
	color = (GdkRGBA){0.0, 0.0, 0.0, 1.0};
	gdk_cairo_set_source_rgba(cr, &color);
	for (int i = 0; i < COLUMNS; i++) {
		cairo_move_to(cr,  (i + 0.5) * button_width, 0.5 * height);
		snprintf(beat_str, 20, "%d", grid->beat_offset + i);
		int text_width;
		int text_height;
		cairo_save(cr);
		pango_layout_set_text(layout, beat_str, -1);
		pango_cairo_update_layout(cr, layout);
		pango_layout_get_pixel_size(layout, &text_width, &text_height);
		cairo_move_to(cr, (i + 0.5) * button_width - 0.5 * text_width, 0.5 * height - 0.5 * text_height);
		pango_cairo_show_layout(cr, layout);
		cairo_restore(cr);
	}

	return FALSE;
}
