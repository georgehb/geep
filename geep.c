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
#include <time.h>
#include <unistd.h>

#define CLOCK_TICK_RATE 1193180
#define SAMPLE_RATE 50000

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
	if((console_fd = open("/dev/tty0", O_WRONLY)) == -1) {
		console_fd = open("/dev/vc/0", O_WRONLY);
	}
	if (console_fd == -1) {
		perror("Couldn't open /dev/tty0 or /dev/vc/0");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, quit);
	beep(g3, quaver);
	beep(c4, quaver);
	beep(eb4, quaver);
	beep_chord(c2, g4, quaver);
	beep_chord(g2, g4, quaver);
	beep_chord(eb2, g4, quaver);
	beep_chord(g2, f4, quaver);
	beep_chord(c2, f4, quaver);
	beep_chord(g2, f4, quaver);
	beep_chord(eb2, eb4, quaver);
	beep(g2, quaver);
	beep_chord(g1, d4, quaver);
	beep_chord(f2, d4, quaver);
	beep_chord(d2, f4, quaver);
	beep_chord(f2, f4, quaver);
	beep(g1, quaver);
	beep_chord(g1, b3, quaver);
	beep_chord(d2, d4, quaver);
	beep_chord(f2, f4, quaver);
	beep_chord(g1, ab4, quaver);
	beep_chord(f2, ab4, quaver);
	beep_chord(d2, ab4, quaver);
	beep_chord(f2, bb4, quaver);
	beep_chord(g1, bb4, quaver);
	beep_chord(f2, ab4, quaver);
	beep_chord(d2, g4, quaver);
	beep_chord(f2, f4, quaver);
	beep_chord(c2, eb3, quaver);
	beep_chord(g2, eb3, quaver);
	beep_chord(eb2, g4, quaver);
	beep_chord(g2, g4, quaver);
	beep(c3, quaver);
	beep_chord(g2, g3, quaver);
	beep_chord(eb2, c4, quaver);
	beep_chord(g2, eb4, quaver);
	beep_chord(c2, c5, quaver);
	beep_chord(g2, c5, quaver);
	beep(eb2, quaver);
	beep_chord(g2, c5, quaver);
	beep_chord(c2, b4, quaver);
	beep_chord(g2, b4, quaver);
	beep(eb2, quaver);
	beep_chord(g2, b4, quaver);
	beep_chord(f2, bb4, quaver);
	beep_chord(c3, bb4, quaver);
	beep_chord(ab2, ab4, quaver);
	beep(ab4, quaver);
	beep(r, quaver);
	beep(ab4, quaver);
	beep(g4, quaver);
	beep(f4, quaver);
	beep_chord(g2, g4, quaver);
	beep_chord(g3, g4,  quaver);
	beep_chord(ab2, f4, quaver);
	beep_chord(ab3, f4, quaver);
	beep_chord(a2, eb4, quaver);
	beep_chord(b2, d4, quaver);
	beep_chord(b3, d4, quaver);
	beep_chord(c2, c4, quaver*3);
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

/* 
 * N.B.: freq1 must be less than freq2 
 */
void beep_chord(int freq1, int freq2, int length) {
	struct timespec start;
	struct timespec time;
	/* Beep */
	uint64_t t = 1000000000lu / (freq2); 
	for (int i = 0; i < freq2 * length / 2000; i++) {
		do_beep(freq1, console_fd);
		clock_gettime(CLOCK_REALTIME, &start);
		clock_gettime(CLOCK_REALTIME, &time);
		uint64_t diff = time_diff(&time, &start);
		while (diff < t) {
			clock_gettime(CLOCK_REALTIME, &time);
			diff = time_diff(&time, &start);
		}
		do_beep(freq2, console_fd);
		while (diff < 2*t) {
			clock_gettime(CLOCK_REALTIME, &time);
			diff = time_diff(&time, &start);
		}
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
