#ifndef GEEP_H
#define GEEP_H

#include <stdarg.h>
#include <stdint.h>

#ifndef BPM
#define BPM 140
#endif

#define CLOCK_TICK_RATE 1193180lu


/*
 * Set sound_quality higher than 100 for better sounding notes, but may kill
 * high chords. 200 sounds pretty good for most things that don't go extremely
 * high.
 */
int geep_setup(int sound_quality);
void geep_close();
void beep(uint64_t length, int num_notes, ...);
void rest(uint64_t length);

#endif /* GEEP_H */
