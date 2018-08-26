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

int geep_setup();
void geep_close();
void beep(uint64_t length, int num_notes, ...);
void rest(uint64_t length);

#endif /* GEEP_H */
