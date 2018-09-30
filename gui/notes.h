#ifndef NOTES_H
#define NOTES_H

/* 
 * #define NANOSECONDS 1000000000lu
 * #define CROTCHET (NANOSECONDS * 60lu / BPM)
 * #define QUAVER (CROTCHET / 2)
 * #define SEMIQUAVER (CROTCHET / 4)
 * #define DEMISEMIQUAVER (CROTCHET / 8)
 * #define SIXTH (CROTCHET / 6)
 * #define SEPARATION (CROTCHET / 50)
 */
#define NUM_NOTES 108

enum note_state {off, separate, held};

extern const int notes[NUM_NOTES];
extern const char *note_names[NUM_NOTES];

#endif /* NOTES_H */
