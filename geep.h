#ifndef GEEP_H
#define GEEP_H

#include <stdarg.h>
#include <stdint.h>

#ifndef BPM
#define BPM 140
#endif

/*
 * Set higher than 100 for better sounding notes, but may kill high chords.
 * 200 sounds pretty good for most things that don't go extremely high.
 */
#ifndef QUALITY
#define QUALITY 100 
#endif

#define CLOCK_TICK_RATE 1193180lu
#define NANOSECONDS 1000000000lu
#define CROTCHET (NANOSECONDS * 60lu / BPM)
#define QUAVER (CROTCHET / 2)
#define SEMIQUAVER (CROTCHET / 4)
#define DEMISEMIQUAVER (CROTCHET / 8)
#define SIXTH (CROTCHET / 6)
#define SEPARATION (CROTCHET / 25)

int geep_setup();
void geep_close();
void beep(int freq, uint64_t length);
void beep_chord(uint64_t length, int num_notes, ...);

#endif /* GEEP_H */
