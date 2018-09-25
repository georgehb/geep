#include "note_grid.h"

static struct note *add_note(struct note **head, unsigned int value);
static struct beat *add_beat(struct beat **head, unsigned int value);
static void remove_note(struct note **head, unsigned int value);
static void remove_beat(struct beat **head, unsigned int value);
static struct note *get_note(struct note *head, unsigned int value);
static struct beat *get_beat(struct beat *head, unsigned int value);
static bool contains_note(struct note *head, unsigned int value);
//static bool contains_beat(struct beat *head, unsigned int value);

struct note *add_note(struct note **head, unsigned int value)
{
	struct note *note = malloc(sizeof(struct note));
	note->note = value;
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

/*bool contains_beat(struct beat *head, unsigned int value)
{
	return (get_beat(head, value) != NULL);
}*/

bool contains_note_beat(struct note_grid *grid, unsigned int note, unsigned int beat)
{
	struct beat *b = get_beat(grid->beats, beat);
	if (b) {
		return contains_note(b->note_list, note);
	}
	return false;
}

void toggle_note(struct note_grid *grid, unsigned int note, unsigned int beat)
{
	struct beat *b = get_beat(grid->beats, beat);
	if (b) {
		if (contains_note(b->note_list, note)) {
			remove_note(&b->note_list, note);
			if (!b->note_list) {
				remove_beat(&grid->beats, beat);
			}
		} else {
			add_note(&b->note_list, note);
		}
	} else {
		b = add_beat(&grid->beats, beat);
		add_note(&b->note_list, note);
	}
}
