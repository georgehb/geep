#include "note_grid.h"

static struct note *add_note(struct note **head, unsigned int value);
static struct beat *add_beat(struct beat **head, unsigned int value);
static void remove_note(struct note **head, unsigned int value);
static void remove_beat(struct beat **head, unsigned int value);
static struct note *get_note(struct note *head, unsigned int value);
static struct beat *get_beat(struct beat *head, unsigned int value);
static bool contains_note(struct note *head, unsigned int value);

struct note *add_note(struct note **head, unsigned int value)
{
	struct note *note = malloc(sizeof(struct note));
	note->note = value;
	note->state = separate;
	note->next = NULL;
	if (!(*head)) {
		*head = note;
		return note;
	}
	while ((*head)->next && (*head)->next->note < value) {
		head = &(*head)->next;
	}
	if ((*head)->note < value) {
		note->next = (*head)->next;
		(*head)->next = note;
	} else {
		note->next = *head;
		*head = note;
	}
	return note;
}

struct beat *add_beat(struct beat **head, unsigned int value)
{
	struct beat *beat = malloc(sizeof(struct beat));
	beat->beat = value;
	beat->note_list = NULL;
	beat->next = NULL;
	if (!(*head)) {
		*head = beat;
		return beat;
	}
	while ((*head)->next && (*head)->next->beat < value) {
		head = &(*head)->next;
	}
	if ((*head)->beat < value) {
		beat->next = (*head)->next;
		(*head)->next = beat;
	} else {
		beat->next = *head;
		*head = beat;
	}
	return beat;
}

void remove_note(struct note **head, unsigned int value)
{
	while ((*head)->note != value) {
		head = &(*head)->next;
	}
	struct note *tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void remove_beat(struct beat **head, unsigned int value)
{
	while ((*head)->beat != value) {
		head = &(*head)->next;
	}
	struct beat *tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

struct note *get_note(struct note *head, unsigned int value)
{
	while (head && head->note != value) {
		head = head->next;
	}
	return head;
}

bool contains_note(struct note *head, unsigned int value)
{
	return (get_note(head, value) != NULL);
}

unsigned int num_notes(struct note *head)
{
	unsigned int n = 0;
	while (head) {
		n++;
		head = head->next;
	}
	return n;
}

struct beat *get_beat(struct beat *head, unsigned int value)
{
	while (head && head->beat != value) {
		head = head->next;
	}
	return head;
}

struct note *get_note_beat(struct note_grid *grid, unsigned int note, unsigned int beat)
{
	struct beat *b = get_beat(grid->beats, beat);
	if (b) {
		return get_note(b->note_list, note);
	}
	return NULL;
}

bool contains_note_beat(struct note_grid *grid, unsigned int note, unsigned int beat)
{
	struct beat *b = get_beat(grid->beats, beat);
	if (b) {
		return contains_note(b->note_list, note);
	}
	return false;
}

struct note *toggle_note(struct note_grid *grid, unsigned int note, unsigned int beat)
{
	struct beat *b = get_beat(grid->beats, beat);
	if (b) {
		struct note *n = get_note(b->note_list, note);
		if (n) {
			n->state++;
			n->state %= 3;
			if (n->state == off) {
				remove_note(&b->note_list, note);
				if (!b->note_list) {
					remove_beat(&grid->beats, beat);
				}
			}
		} else {
			return add_note(&b->note_list, note);
		}
	} else {
		b = add_beat(&grid->beats, beat);
		return add_note(&b->note_list, note);
	}
	return NULL;
}

void note_grid_clear(struct note_grid *grid)
{
	struct beat *beat = grid->beats;
	struct note *note;
	void *tmp;

	while (beat) {
		note = beat->note_list;
		while (note) {
			tmp = (void *)note;
			note = note->next;
			free(tmp);
		}
		tmp = (void *)beat;
		beat = beat->next;
		free(tmp);
	}
	grid->beats = NULL;
}
