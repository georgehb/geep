#ifndef NOTE_GRID_H
#define NOTE_GRID_H

#include "drawing.h"
#include "notes.h"
#include <gtk/gtk.h>
#include <stdbool.h>

#define ROWS 20
#define COLUMNS 30
#define BUTTONS (ROWS * COLUMNS)

struct note {
	unsigned int note;
	enum note_state state;
	struct note *next;
};

struct beat {
	unsigned int beat;
	struct note *note_list;
	struct beat *next;
};

struct note_grid {
	struct note_button buttons[BUTTONS];
	struct beat *beats;
	unsigned int note_offset;
	unsigned int beat_offset;
};


unsigned int num_notes(struct note *head);
bool contains_note_beat(struct note_grid *grid, unsigned int note, unsigned int beat);
struct note *get_note_beat(struct note_grid *grid, unsigned int note, unsigned int beat);

struct note *toggle_note(struct note_grid *grid, unsigned int note, unsigned int beat);
void note_grid_clear(struct note_grid *grid);

#endif /* NOTE_GRID_H */
