#include "notes.h"
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/kd.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define CLOCK_TICK_RATE 1193180lu

#define BPM 140
#define CROTCHET (1000000000lu * 60lu / BPM)
#define QUAVER (1000000000lu * 60lu / BPM / 2)
#define SEMIQUAVER (1000000000lu * 60lu / BPM / 4)
#define DEMISEMIQUAVER (1000000000lu * 60lu / BPM / 8)
#define SIXTH (1000000000lu * 60lu / BPM / 6)

static uint64_t min(uint64_t x, uint64_t y)
{
	return x < y ? x : y;
}

void beep(int freq, uint64_t length);
void beep_chord(int freq1, int freq2, uint64_t length);
uint64_t time_diff(const struct timespec *cur,
		const struct timespec *old);
void do_beep(int freq, int console_fd);

static int console_fd = -1;

void quit(int sig)
{
	ioctl(console_fd, KIOCSOUND, 0);
	exit(EXIT_FAILURE);
}

int main()
{
	if ((console_fd = open("/dev/tty0", O_WRONLY | O_CLOEXEC)) == -1) {
		console_fd = open("/dev/vc/0", O_WRONLY | O_CLOEXEC);
	}
	if (console_fd == -1) {
		perror("Couldn't open /dev/tty0 or /dev/vc/0");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, quit);

	// 1
	beep_chord(1, g4, QUAVER);
	beep_chord(1, c5, QUAVER);
	beep_chord(1, eb5, QUAVER);

	// 2
	beep_chord(c3, g5, QUAVER);
	beep_chord(g3, g5, QUAVER);
	beep_chord(eb3, g5, QUAVER);
	beep_chord(g3, f5, QUAVER);
	beep_chord(c3, f5, QUAVER);
	beep_chord(g3, f5, QUAVER);
	beep_chord(eb3, eb5, QUAVER);
	beep_chord(1, g3, QUAVER);

	// 3
	beep_chord(g2, d5, QUAVER);
	beep_chord(f3, d5, QUAVER);
	beep_chord(d3, f5, QUAVER);
	beep_chord(f3, f5, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep_chord(g3, b4, QUAVER);
	beep_chord(d3, d5, QUAVER);
	beep_chord(f3, f5, QUAVER);

	// 4
	beep_chord(g2, ab5, QUAVER);
	beep_chord(f3, ab5, QUAVER);
	beep_chord(d3, ab5, QUAVER);
	beep_chord(f3, bb5, QUAVER);
	beep_chord(g2, bb5, QUAVER);
	beep_chord(f3, ab5, QUAVER);
	beep_chord(d3, g5, QUAVER);
	beep_chord(f3, f5, QUAVER);

	// 5
	beep_chord(c3, eb5, QUAVER);
	beep_chord(g3, eb5, QUAVER);
	beep_chord(eb3, g5, QUAVER);
	beep_chord(g3, g5, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, c5, QUAVER);
	beep_chord(g3, eb5, QUAVER);

	// 6
	beep_chord(c3, c6, QUAVER);
	beep_chord(g3, c6, QUAVER);
	beep_chord(eb3, 1, QUAVER);
	beep_chord(g3, c6, QUAVER);
	beep_chord(c3, b5, QUAVER);
	beep_chord(g3, b5, QUAVER);
	beep_chord(eb3, 1, QUAVER);
	beep_chord(g3, b5, QUAVER);

	// 7
	beep_chord(f2, bb5, QUAVER);
	beep_chord(c3, bb5, QUAVER);
	beep_chord(ab2, ab5, QUAVER);
	beep_chord(1, ab5, QUAVER);
	beep(r, QUAVER);
	beep_chord(1, ab5, QUAVER);
	beep_chord(1, g5, QUAVER);
	beep_chord(1, f5, QUAVER);

	// 8
	beep_chord(g2, g5, QUAVER);
	beep_chord(g3, g5,  QUAVER);
	beep_chord(ab2, f5, QUAVER);
	beep_chord(ab3, f5, QUAVER);
	beep_chord(a2, eb5, QUAVER);
	beep_chord(b2, d5, QUAVER);
	beep_chord(b3, d5, QUAVER);
	beep_chord(c3, c5, QUAVER*3);

	// 9
	beep(r, QUAVER);
	beep_chord(g2, 1, QUAVER*3);
	beep_chord(g2, g3, QUAVER);
	beep_chord(g2, c4, QUAVER);
	beep_chord(g2, eb3, QUAVER);

	// 10
	beep_chord(c3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(c3, f4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	
	// 11
	beep_chord(g2, d4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep_chord(f3, g3, QUAVER);
	beep_chord(d3, b3, QUAVER);
	beep_chord(f3, d4, QUAVER);

	// 12
	beep_chord(g2, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(d3, f4, QUAVER);
	beep_chord(f3, eb4, QUAVER);
	beep_chord(g2, eb4, QUAVER);
	beep_chord(f3, eb4, QUAVER);
	beep_chord(d3, d4, QUAVER);
	beep_chord(f3, d4, QUAVER);

	// 13
	beep_chord(c3, c4, QUAVER);
	beep_chord(g3, c4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(g3, 1, QUAVER);
	beep_chord(eb3, c4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	
	// 14
	beep_chord(c3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(c3, f4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	
	// 15
	beep_chord(g2, d4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep_chord(f3, g3, QUAVER);
	beep_chord(d3, b3, QUAVER);
	beep_chord(f3, d4, QUAVER);

	// 16
	beep_chord(g2, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(d3, g4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, eb4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, d4, QUAVER);
	beep_chord(f3, eb4, QUAVER);

	// 17
	beep_chord(c3, eb4, QUAVER);
	beep_chord(gb2, eb4, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep_chord(b2, 1, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(c3, g3, QUAVER);
	beep_chord(c3, c4, QUAVER);
	beep_chord(c3, eb4, QUAVER);

	// 18
	// TODO: chords
	beep_chord(c3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(c3, f4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	
	// 19
	beep_chord(g2, d4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep_chord(f3, g3, QUAVER);
	beep_chord(d3, b3, QUAVER);
	beep_chord(f3, d4, QUAVER);

	// 20
	beep_chord(g2, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(d3, g4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, eb4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, d4, QUAVER);
	beep_chord(f3, eb4, QUAVER);

	// 21
	beep_chord(c3, c4, QUAVER);
	beep_chord(g3, c4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(g3, 1, QUAVER);
	beep_chord(eb3, c4, QUAVER);
	beep_chord(g3, eb4, QUAVER);

	// 22
	beep_chord(c3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(c3, f4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);

	// 23
	beep_chord(f2, bb4, QUAVER);
	beep_chord(c3, bb4, QUAVER);
	beep_chord(ab2, ab4, QUAVER);
	beep_chord(c3, ab4, QUAVER);
	beep_chord(f2, 1, QUAVER);
	beep_chord(c3, ab4, QUAVER);
	beep_chord(ab2, g4, QUAVER);
	beep_chord(c3, f4, QUAVER);

	// 24
	beep_chord(g2, g4, QUAVER);
	beep_chord(g3, g4,  QUAVER);
	beep_chord(ab2, f4, QUAVER);
	beep_chord(ab3, f4, QUAVER);
	beep_chord(a2, eb4, QUAVER);
	beep_chord(b2, d4, QUAVER);
	beep_chord(b3, d4, QUAVER);
	beep_chord(c3, c4, QUAVER*3);

	// 25
	beep_chord(c3, 1, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(c3, c4, QUAVER);
	beep_chord(c3, c4, QUAVER);

	// 26
	beep_chord(f3, ab5, QUAVER);
	beep_chord(c4, ab5,  QUAVER);
	beep_chord(ab3, ab5, QUAVER);
	beep_chord(c4, ab5, QUAVER);
	beep_chord(f3, ab5, QUAVER);
	beep_chord(c4, ab5,  QUAVER);
	beep_chord(ab3, bb5, QUAVER);
	beep_chord(c4, c6, QUAVER);

	// 27
	beep_chord(f3, c6, QUAVER);
	beep_chord(c4, c6,  QUAVER);
	beep_chord(ab3, c6, QUAVER);
	beep_chord(c4, c6, QUAVER);
	beep_chord(f3, bb5, QUAVER);
	beep_chord(c4, ab5,  QUAVER);
	beep_chord(ab3, ab5, QUAVER);
	beep_chord(c4, ab5, QUAVER);

	// 28
	beep_chord(c3, g5, QUAVER);
	beep_chord(g3, g5,  QUAVER);
	beep_chord(eb3, g5, QUAVER);
	beep_chord(g3, f5, QUAVER);
	beep_chord(c3, eb5, QUAVER);
	beep_chord(g3, f5,  QUAVER);
	beep_chord(eb3, f5, QUAVER);
	beep_chord(g3, g5, QUAVER);

	// 29
	beep_chord(c3, g5, QUAVER);
	beep_chord(g3, g5,  QUAVER);
	beep_chord(eb3, g5, QUAVER);
	beep_chord(g3, g5, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(g3, 1,  QUAVER);
	beep_chord(eb3, c5, QUAVER);
	beep_chord(g3, c5, QUAVER);

	// 30
	beep_chord(f3, ab5, QUAVER);
	beep_chord(c4, ab5,  QUAVER);
	beep_chord(ab3, ab5, QUAVER);
	beep_chord(c4, ab5, QUAVER);
	beep_chord(f3, ab5, QUAVER);
	beep_chord(c4, ab5,  QUAVER);
	beep_chord(ab3, bb5, QUAVER);
	beep_chord(c4, c6, QUAVER);
	
	// 31
	beep_chord(ab3, c6, QUAVER);
	beep_chord(eb4, c6,  QUAVER);
	beep_chord(c4, 1, QUAVER);
	beep_chord(eb4, c6, QUAVER);

	beep_chord(ab3, c6, QUAVER);
	beep_chord(eb4, c6,  SIXTH);
	beep_chord(eb4, bb5,  SIXTH*2);
	beep_chord(c4, bb5, SIXTH*2);
	beep_chord(c4, ab5, SIXTH);
	beep_chord(eb4, ab5, QUAVER);

	// 32
	beep_chord(d5, g5, QUAVER);
	beep_chord(gb2, 1, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep(r, QUAVER);
	beep_chord(eb3, 1, QUAVER);
	beep_chord(d3, 1, QUAVER);
	beep(r, QUAVER);
	beep_chord(bb2, 1, QUAVER);

	// 33
	beep_chord(b2, 1, QUAVER);
	beep_chord(d3, 1, QUAVER);
	beep_chord(1, ab3, QUAVER);
	beep_chord(g2, g3, QUAVER*2);
	beep_chord(g2, g3, QUAVER);
	beep_chord(g3, c4, QUAVER);
	beep_chord(g3, eb4, QUAVER);

	// 34
	// TODO: chords
	beep_chord(c3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(c3, f4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	
	// 35
	beep_chord(g2, d4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, 1, QUAVER);
	beep_chord(f3, g3, QUAVER);
	beep_chord(d3, b3, QUAVER);
	beep_chord(f3, d4, QUAVER);

	// 36
	beep_chord(g2, f4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(d3, g4, QUAVER);
	beep_chord(f3, f4, QUAVER);
	beep_chord(g2, eb4, QUAVER);
	beep_chord(f3, d4, QUAVER);
	beep_chord(d3, d4, QUAVER);
	beep_chord(f3, c4, QUAVER);

	// 37
	beep_chord(c3, c4, QUAVER);
	beep_chord(g3, c4, QUAVER);
	beep_chord(eb3, eb4, QUAVER);
	beep_chord(g3, eb4, QUAVER);
	beep_chord(c3, 1, QUAVER);
	beep_chord(g3, 1, QUAVER);
	beep_chord(eb3, c4, QUAVER);
	beep_chord(g3, eb4, QUAVER);

	// 38
	beep_chord(c3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(c3, f4, QUAVER);
	beep_chord(g3, f4, QUAVER);
	beep_chord(eb3, g4, QUAVER);
	beep_chord(g3, g4, QUAVER);

	// 39
	beep_chord(f2, bb4, QUAVER);
	beep_chord(c3, ab4, QUAVER);
	beep_chord(ab2, ab4, QUAVER);
	beep_chord(c3, ab4, QUAVER);
	beep_chord(f2, 1, QUAVER);
	beep_chord(c3, ab4, QUAVER);
	beep_chord(ab2, g4, QUAVER);
	beep_chord(c3, f4, QUAVER);

	// 40
	beep_chord(g2, g4, QUAVER);
	beep_chord(g3, g4,  QUAVER);
	beep_chord(ab2, f4, QUAVER);
	beep_chord(ab3, f4, QUAVER);
	beep_chord(a2, eb4, QUAVER);
	beep_chord(b2, d4, QUAVER);
	beep_chord(b3, d4, QUAVER);
	beep_chord(c3, c4, QUAVER);

	// 41
	beep_chord(c3, c4, QUAVER);
	beep_chord(c2, c5, QUAVER);
	beep_chord(c2, c5, QUAVER);
	beep_chord(c2, c5, QUAVER);
	beep_chord(c2, c5, QUAVER*2);
	beep_chord(c2, g5, QUAVER);
	beep_chord(c2, f5, QUAVER);

	// 42
	beep_chord(g2, g5, QUAVER);
	beep_chord(g3, g5, QUAVER);
	beep_chord(ab2, f5, QUAVER);
	beep_chord(ab3, f5, QUAVER);
	beep_chord(a2, eb5, QUAVER);
	beep_chord(b2, d5, QUAVER);
	beep_chord(b3, d5, QUAVER);
	beep_chord(c3, c5, QUAVER);

	// 43
	beep_chord(c3, c5, QUAVER);
	beep_chord(c2, c5, QUAVER);
	beep_chord(c2, 1, QUAVER);
	beep_chord(c2, 1, QUAVER);
	beep_chord(c2, 1, QUAVER);
	beep_chord(c2, 1, QUAVER);
	beep_chord(c2, ab5, QUAVER);
	beep_chord(c2, g5, QUAVER);
	beep_chord(c2, f5, QUAVER);

	// 44
	beep_chord(g2, g4, QUAVER);
	beep_chord(g3, g4,  QUAVER);
	beep_chord(ab2, ab4, QUAVER);
	beep_chord(ab3, ab4, QUAVER);
	beep_chord(a2, bb4, QUAVER);
	beep_chord(b2, b4, QUAVER);
	beep_chord(b3, b4, QUAVER);
	beep_chord(c3, c5, QUAVER);

	// 45
	beep_chord(c3, c5, QUAVER);
	beep(r, QUAVER);
	beep_chord(c2, d4, QUAVER*5);
	beep_chord(g2, d4, DEMISEMIQUAVER);
	beep_chord(f2, d4, DEMISEMIQUAVER);
	beep_chord(eb2, d4, DEMISEMIQUAVER);
	beep_chord(d2, d4, DEMISEMIQUAVER);

	// 46
	beep_chord(c2, d3, QUAVER);

	close(console_fd);
	exit(EXIT_SUCCESS);
}

void beep(int freq, uint64_t length) {
	struct timespec start;
	struct timespec time;
	/* Beep */
	do_beep(freq, console_fd);
	clock_gettime(CLOCK_REALTIME, &start);
	clock_gettime(CLOCK_REALTIME, &time);
	uint64_t diff = time_diff(&time, &start);
	while (diff < length) {
		clock_gettime(CLOCK_REALTIME, &time);
		diff = time_diff(&time, &start);
	}
	do_beep(0, console_fd);
}

void beep_chord(int freq1, int freq2, uint64_t length) {
	struct timespec start;
	struct timespec time;
	uint64_t diff;
	uint64_t period1 = CLOCK_TICK_RATE / freq1;
	uint64_t period2 = CLOCK_TICK_RATE / freq2;
	uint64_t sample = 0;
	uint64_t sample1 = 1;
	uint64_t sample2 = 1;
	uint64_t next_tick;
	uint64_t overshoot = 0;

	clock_gettime(CLOCK_REALTIME, &start);
	clock_gettime(CLOCK_REALTIME, &time);
	diff  = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;

	while (diff < length * CLOCK_TICK_RATE / 1000000000) {
		next_tick = min(period1 * sample1, period2 * sample2);
		if (next_tick == period1 * sample1) {
			sample1++;
		}
	       	if (next_tick == period2 * sample2) {
			sample2++;
		}
		/* 
		 * The following two magic numbers are just that - they sound
		 * good on George's machine, who knows why.
		 */
		ioctl(console_fd, KIOCSOUND, 40000);
		while (diff < sample + 200) {
			clock_gettime(CLOCK_REALTIME, &time);
			diff = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;
		}
		ioctl(console_fd, KIOCSOUND, 0);
		while (diff < next_tick) {
			clock_gettime(CLOCK_REALTIME, &time);
			diff = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;
		}
		overshoot = diff - next_tick;
		sample = next_tick + overshoot;
	}
	do_beep(0, console_fd);
}

uint64_t time_diff(const struct timespec * const cur,
		const struct timespec * const old)
{
	uint64_t sec = (uint64_t)(cur->tv_sec - old->tv_sec);
	uint64_t nsec;
	if (sec == 0) {
		nsec = (uint64_t)(cur->tv_nsec - old->tv_nsec);
		return nsec;
	}
	nsec = 1000000000 * sec;
	if (old->tv_nsec > cur->tv_nsec) {
		nsec -= (uint64_t)(old->tv_nsec - cur->tv_nsec);
	} else {
		nsec += (uint64_t)(cur->tv_nsec - old->tv_nsec);
	}
	return nsec;
}

void do_beep(int freq, int console_fd)
{
	int period = (freq != 0 ? (int)(CLOCK_TICK_RATE/freq) : freq);
	ioctl(console_fd, KIOCSOUND, period);
}
