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

static uint64_t min(uint64_t x, uint64_t y)
{
	return x < y ? x : y;
}

static const int quaver = 214;

void beep(int freq, int length);
void beep_chord(int freq1, int freq2, int length);
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
	beep_chord(1, g2, quaver);
	beep_chord(1, c3, quaver);
	beep_chord(1, eb3, quaver);
	beep_chord(c2, g3, quaver);
	beep_chord(g2, g3, quaver);
	beep_chord(eb2, g3, quaver);
	beep_chord(g2, f3, quaver);
	beep_chord(c2, f3, quaver);
	beep_chord(g2, f3, quaver);
	beep_chord(eb2, eb3, quaver);
	beep_chord(1, g2, quaver);
	beep_chord(g1, d3, quaver);
	beep_chord(f2, d3, quaver);
	beep_chord(d2, f3, quaver);
	beep_chord(f2, f3, quaver);
	beep_chord(1, g1, quaver);
	beep_chord(g1, b2, quaver);
	beep_chord(d2, d3, quaver);
	beep_chord(f2, f3, quaver);
	beep_chord(g1, ab3, quaver);
	beep_chord(f2, ab3, quaver);
	beep_chord(d2, ab3, quaver);
	beep_chord(f2, bb3, quaver);
	beep_chord(g1, bb3, quaver);
	beep_chord(f2, ab3, quaver);
	beep_chord(d2, g3, quaver);
	beep_chord(f2, f3, quaver);
	beep_chord(c2, eb2, quaver);
	beep_chord(g2, eb2, quaver);
	beep_chord(eb2, g3, quaver);
	beep_chord(g2, g3, quaver);
	beep_chord(1, c3, quaver);
	beep_chord(g2, g2, quaver);
	beep_chord(eb2, c3, quaver);
	beep_chord(g2, eb3, quaver);
	beep_chord(c2, c4, quaver);
	beep_chord(g2, c4, quaver);
	beep_chord(1, eb2, quaver);
	beep_chord(g2, c4, quaver);
	beep_chord(c2, b3, quaver);
	beep_chord(g2, b3, quaver);
	beep_chord(1, eb2, quaver);
	beep_chord(g2, b3, quaver);
	beep_chord(f2, bb3, quaver);
	beep_chord(c3, bb3, quaver);
	beep_chord(ab2, ab3, quaver);
	beep_chord(1, ab3, quaver);
	beep(r, quaver);
	beep_chord(1, ab3, quaver);
	beep_chord(1, g3, quaver);
	beep_chord(1, f3, quaver);
	beep_chord(g1, g3, quaver);
	beep_chord(g2, g3,  quaver);
	beep_chord(ab1, f3, quaver);
	beep_chord(ab2, f3, quaver);
	beep_chord(a2, eb3, quaver);
	beep_chord(b2, d3, quaver);
	beep_chord(b3, d3, quaver);
	beep_chord(c2, c3, quaver*3);
	close(console_fd);
	exit(EXIT_SUCCESS);
}

void beep(int freq, int length) {
	struct timespec start;
	struct timespec time;
	/* Beep */
	do_beep(freq, console_fd);
	clock_gettime(CLOCK_REALTIME, &start);
	clock_gettime(CLOCK_REALTIME, &time);
	uint64_t diff = time_diff(&time, &start);
	while (diff < 1000000*length) {
		clock_gettime(CLOCK_REALTIME, &time);
		diff = time_diff(&time, &start);
	}
	do_beep(0, console_fd);
}

void beep_chord(int freq1, int freq2, int length) {
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

	while (diff < 1000000lu * length * CLOCK_TICK_RATE / 1000000000) {
		next_tick = min(period1 * sample1, period2 * sample2);
		if (next_tick == period1 * sample1) {
			sample1++;
		}
	       	if (next_tick == period2 * sample2) {
			sample2++;
		}
		if (next_tick < sample + 80) {
			continue;
		}
		ioctl(console_fd, KIOCSOUND, 40);
		while (diff < sample + 80) {
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
