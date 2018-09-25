#ifndef NOTE_GRID_H
#define NOTE_GRID_H

#include <gtk/gtk.h>
#include <stdbool.h>

#define ROWS 20
#define COLUMNS 20
#define BUTTONS (ROWS * COLUMNS)

struct note {
	unsigned int note;
	struct note *next;
};

struct beat {
	unsigned int beat;
	struct note *note_list;
	struct beat *next;
};

struct note_grid {
	GtkWidget *buttons[BUTTONS];
	GtkWidget *keyboard;
	GtkWidget *beat_bar;
	GtkWidget *bpm;
	struct beat *beats;
	unsigned int note_offset;
	unsigned int beat_offset;
};


unsigned int num_notes(struct note *head);
bool contains_note_beat(struct note_grid *grid, unsigned int note, unsigned int beat);

void toggle_note(struct note_grid *grid, unsigned int note, unsigned int beat);

#endif /* NOTE_GRID_H */
