#include "notes.h"
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/kd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define BPM 140
#define QUALITY 100 // Set higher than 100 for better sounding notes, but may kill high chords

#define CLOCK_TICK_RATE 1193180lu
#define NANOSECONDS 1000000000lu
#define CROTCHET (NANOSECONDS * 60lu / BPM)
#define QUAVER (CROTCHET / 2)
#define SEMIQUAVER (CROTCHET / 4)
#define DEMISEMIQUAVER (CROTCHET / 8)
#define SIXTH (CROTCHET / 6)
#define SEPARATION (CROTCHET / 25)

static uint64_t min(uint64_t x, uint64_t y)
{
	return x < y ? x : y;
}

static void beep(int freq, uint64_t length);
static void beep_chord(uint64_t length, int num_notes, ...);
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
	beep_chord(QUAVER, 2, 1, g4);
	beep_chord(QUAVER, 2, 1, c5);
	beep_chord(QUAVER, 2, 1, eb5);

	// 2
	beep_chord(QUAVER, 2, c3, g5);
	beep_chord(QUAVER, 2, g3, g5);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, g5);
	beep_chord(QUAVER, 2, g3, f5);
	beep_chord(QUAVER, 2, c3, f5);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, f5);
	beep_chord(QUAVER, 2, eb3, eb5);
	beep_chord(QUAVER, 2, 1, g3);

	// 3
	beep_chord(QUAVER, 2, g2, d5);
	beep_chord(QUAVER, 2, f3, d5);
	beep_chord(QUAVER, 2, d3, f5);
	beep_chord(QUAVER, 2, f3, f5);
	beep_chord(QUAVER, 2, g2, 1);
	beep_chord(QUAVER, 2, g3, b4);
	beep_chord(QUAVER, 2, d3, d5);
	beep_chord(QUAVER, 2, f3, f5);

	// 4
	beep_chord(QUAVER, 2, g2, ab5);
	beep_chord(QUAVER, 2, f3, ab5);
	beep_chord(SEPARATION, 2, f3, 1);
	beep_chord(QUAVER, 2, d3, ab5);
	beep_chord(QUAVER, 2, f3, bb5);
	beep_chord(QUAVER, 2, g2, bb5);
	beep_chord(QUAVER, 2, f3, ab5);
	beep_chord(QUAVER, 2, d3, g5);
	beep_chord(QUAVER, 2, f3, f5);

	// 5
	beep_chord(QUAVER, 2, c3, eb5);
	beep_chord(QUAVER, 2, g3, eb5);
	beep_chord(QUAVER, 2, eb3, g5);
	beep_chord(QUAVER, 2, g3, g5);
	beep_chord(QUAVER, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(QUAVER, 2, eb3, c5);
	beep_chord(QUAVER, 2, g3, eb5);

	// 6
	beep_chord(QUAVER, 2, c3, c6);
	beep_chord(QUAVER, 2, g3, c6);
	beep_chord(QUAVER, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, c6);
	beep_chord(QUAVER, 2, c3, b5);
	beep_chord(QUAVER, 2, g3, b5);
	beep_chord(QUAVER, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, b5);

	// 7
	beep_chord(QUAVER, 2, f2, bb5);
	beep_chord(QUAVER, 2, c3, bb5);
	beep_chord(QUAVER, 2, ab2, ab5);
	beep_chord(QUAVER, 2, 1, ab5);
	beep(r, QUAVER);
	beep_chord(QUAVER, 2, 1, ab5);
	beep_chord(QUAVER, 2, 1, g5);
	beep_chord(QUAVER, 2, 1, f5);

	// 8
	beep_chord(QUAVER, 2, g2, g5);
	beep_chord(QUAVER, 2, g3, g5);
	beep_chord(QUAVER, 2, ab2, f5);
	beep_chord(QUAVER, 2, ab3, f5);
	beep_chord(QUAVER, 2, a2, eb5);
	beep_chord(QUAVER, 2, b2, d5);
	beep_chord(QUAVER, 2, b3, d5);
	beep_chord(QUAVER*3, 2, c3, c5);

	// 9
	beep(r, QUAVER);
	beep_chord(QUAVER*3, 2, g2, 1);
	beep_chord(QUAVER, 2, g2, g3);
	beep_chord(QUAVER, 2, g2, c4);
	beep_chord(QUAVER, 2, g2, eb3);

	// 10
	beep_chord(QUAVER, 2, c3, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, c3, f4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, eb3, eb4);
	beep_chord(SEPARATION, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, eb4);
	
	// 11
	beep_chord(QUAVER, 2, g2, d4);
	beep_chord(QUAVER, 2, f3, d4);
	beep_chord(QUAVER, 2, d3, f4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, g2, 1);
	beep_chord(QUAVER, 2, f3, g3);
	beep_chord(QUAVER, 2, d3, b3);
	beep_chord(QUAVER, 2, f3, d4);

	// 12
	beep_chord(QUAVER, 2, g2, f4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(SEPARATION, 2, f3, 1);
	beep_chord(QUAVER, 2, d3, f4);
	beep_chord(QUAVER, 2, f3, eb4);
	beep_chord(QUAVER, 2, g2, eb4);
	beep_chord(SEPARATION, 2, g2, 1);
	beep_chord(QUAVER, 2, f3, eb4);
	beep_chord(QUAVER, 2, d3, d4);
	beep_chord(QUAVER, 2, f3, d4);

	// 13
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(QUAVER, 2, g3, c4);
	beep_chord(QUAVER, 2, eb3, eb4);
	beep_chord(QUAVER, 2, g3, eb4);
	beep_chord(QUAVER, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, c4);
	beep_chord(QUAVER, 2, g3, eb4);
	
	// 14
	beep_chord(QUAVER, 2, c3, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, c3, f4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, eb3, eb4);
	beep_chord(SEPARATION, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, eb4);
	
	// 15
	beep_chord(QUAVER, 2, g2, d4);
	beep_chord(QUAVER, 2, f3, d4);
	beep_chord(QUAVER, 2, d3, f4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, g2, 1);
	beep_chord(QUAVER, 2, f3, g3);
	beep_chord(QUAVER, 2, d3, b3);
	beep_chord(QUAVER, 2, f3, d4);

	// 16
	beep_chord(QUAVER, 2, g2, f4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, d3, g4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, g2, eb4);
	beep_chord(QUAVER, 2, f3, d4);
	beep_chord(QUAVER, 2, d3, d4);
	beep_chord(QUAVER, 2, f3, eb4);

	// 17
	beep_chord(QUAVER, 2, c3, eb4);
	beep_chord(QUAVER, 2, gb2, eb4);
	beep_chord(QUAVER, 2, g2, 1);
	beep_chord(QUAVER, 2, b2, 1);
	beep_chord(QUAVER, 2, c3, 1);
	beep_chord(QUAVER, 2, c3, g3);
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(QUAVER, 2, c3, eb4);

	// 18
	beep_chord(QUAVER, 3, c3, eb4, g4);
	beep_chord(QUAVER, 3, g3, eb4, g4);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 3, eb3, eb4, g4);
	beep_chord(QUAVER, 3, g3, d4, f4);
	beep_chord(QUAVER, 3, c3, d4, f4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 3, g3, d4, f4);
	beep_chord(QUAVER, 3, eb3, c4, eb4);
	beep_chord(SEPARATION, 2, eb3, 1);
	beep_chord(QUAVER, 3, g3, c4, eb4);
	
	// 19
	beep_chord(QUAVER, 3, g2, b3, d4);
	beep_chord(QUAVER, 3, f3, b3, d4);
	beep_chord(QUAVER, 3, d3, d4, f4);
	beep_chord(QUAVER, 3, f3, d4, f4);
	beep_chord(QUAVER, 2, g2, 1);
	beep_chord(QUAVER, 2, f3, g3);
	beep_chord(QUAVER, 2, d3, b3);
	beep_chord(QUAVER, 2, f3, d4);

	// 20
	beep_chord(QUAVER, 3, g2, d4, f4);
	beep_chord(QUAVER, 3, f3, d4, f4);
	beep_chord(SEPARATION, 2, f3, 1);
	beep_chord(QUAVER, 3, d3, d4, f4);
	beep_chord(QUAVER, 3, f3, c4, eb4);
	beep_chord(QUAVER, 3, g2, c4, eb4);
	beep_chord(SEPARATION, 2, g2, 1);
	beep_chord(QUAVER, 3, f3, c4, eb4);
	beep_chord(QUAVER, 3, d3, b4, d4);
	beep_chord(QUAVER, 3, f3, b4, d4);

	// 21
	beep_chord(QUAVER, 3, c3, g3, c4);
	beep_chord(QUAVER, 2, g3, 1);
	beep_chord(QUAVER, 3, eb3, g3, eb4);
	beep_chord(QUAVER, 2, g3, 1);
	beep_chord(QUAVER, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, c4);
	beep_chord(QUAVER, 2, g3, eb4);

	// 22
	beep_chord(QUAVER, 2, c3, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, c3, f4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(SEPARATION, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, g4);

	// 23
	beep_chord(QUAVER, 2, f2, bb4);
	beep_chord(QUAVER, 2, c3, bb4);
	beep_chord(QUAVER, 2, ab2, ab4);
	beep_chord(QUAVER, 2, c3, ab4);
	beep_chord(QUAVER, 2, f2, 1);
	beep_chord(QUAVER, 2, c3, ab4);
	beep_chord(QUAVER, 2, ab2, g4);
	beep_chord(QUAVER, 2, c3, f4);

	// 24
	beep_chord(QUAVER, 2, g2, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(QUAVER, 2, ab2, f4);
	beep_chord(SEPARATION, 2, ab2, 1);
	beep_chord(QUAVER, 2, ab3, f4);
	beep_chord(QUAVER, 2, a2, eb4);
	beep_chord(QUAVER, 2, b2, d4);
	beep_chord(QUAVER, 2, b3, d4);
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(SEPARATION, 2, 1, c4);

	// 25
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(SEPARATION, 2, 1, c4);
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(SEPARATION, 2, 1, c4);
	beep_chord(QUAVER, 2, c3, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c3, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c3, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c3, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, c3, c4);

	// 26
	beep_chord(QUAVER, 3, f3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, ab3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, f3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, ab3, g5, bb5);
	beep_chord(QUAVER, 3, c4, ab5, c6);

	// 27
	beep_chord(QUAVER, 3, f3, ab5, c6);
	beep_chord(QUAVER, 3, c4, ab5, c6);
	beep_chord(SEPARATION, 2, c4, 1);
	beep_chord(QUAVER, 3, ab3, ab5, c6);
	beep_chord(QUAVER, 3, c4, ab5, c6);
	beep_chord(QUAVER, 3, f3, g5, bb5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, ab3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);

	// 28
	beep_chord(QUAVER, 3, c3, eb5, g5);
	beep_chord(QUAVER, 3, g3, eb5, g5);
	beep_chord(QUAVER, 3, eb3, eb5, g5);
	beep_chord(QUAVER, 3, g3, d5, f5);
	beep_chord(QUAVER, 3, c3, c5, eb5);
	beep_chord(QUAVER, 3, g3, d5, f5);
	beep_chord(QUAVER, 3, eb3, d5, f5);
	beep_chord(QUAVER, 3, g3, eb5, g5);

	// 29
	beep_chord(QUAVER, 3, c3, eb5, g5);
	beep_chord(QUAVER, 3, g3, eb5, g5);
	beep_chord(QUAVER, 3, eb3, eb5, g5);
	beep_chord(QUAVER, 3, g3, eb5, g5);
	beep_chord(QUAVER, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, c5);
	beep_chord(QUAVER, 2, g3, c5);

	// 30
	beep_chord(QUAVER, 3, f3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, ab3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, f3, f5, ab5);
	beep_chord(QUAVER, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, ab3, g5, bb5);
	beep_chord(QUAVER, 3, c4, ab5, c6);
	
	// 31
	beep_chord(QUAVER, 3, ab3, ab5, c6);
	beep_chord(QUAVER, 3, eb4, ab5, c6);
	beep_chord(QUAVER, 3, c4, 1);
	beep_chord(QUAVER, 3, eb4, ab5, c6);
	beep_chord(SEPARATION, 2, eb4, 1);

	beep_chord(QUAVER, 3, ab3, ab5, c6);
	beep_chord(SIXTH, 3, eb4, ab5, c6);
	beep_chord(SIXTH*2, 3, eb4, g5, bb5);
	beep_chord(SIXTH*2, 3, c4, g5, bb5);
	beep_chord(SIXTH, 3, c4, f5, ab5);
	beep_chord(QUAVER, 3, eb4, f5, ab5);

	// 32
	beep_chord(QUAVER, 2, d5, g5);
	beep_chord(QUAVER, 2, gb2, 1);
	beep_chord(QUAVER, 2, g2, 1);
	beep(r, QUAVER);
	beep_chord(QUAVER, 2, eb3, 1);
	beep_chord(QUAVER, 2, d3, 1);
	beep(r, QUAVER);
	beep_chord(QUAVER, 2, bb2, 1);

	// 33
	beep_chord(QUAVER, 2, b2, 1);
	beep_chord(QUAVER, 2, d3, 1);
	beep_chord(QUAVER, 2, 1, ab3);
	beep_chord(QUAVER*2, 2, g2, g3);
	beep_chord(SEPARATION, 2, g2, 1);
	beep_chord(QUAVER, 2, g2, g3);
	beep_chord(QUAVER, 2, g3, c4);
	beep_chord(QUAVER, 2, g3, eb4);

	// 34
	// TODO: chords
	beep_chord(QUAVER, 2, c3, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, c3, f4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, eb3, eb4);
	beep_chord(SEPARATION, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, eb4);
	
	// 35
	beep_chord(QUAVER, 2, g2, d4);
	beep_chord(QUAVER, 2, f3, d4);
	beep_chord(QUAVER, 2, d3, f4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, g2, 1);
	beep_chord(QUAVER, 2, f3, g3);
	beep_chord(QUAVER, 2, d3, b3);
	beep_chord(QUAVER, 2, f3, d4);

	// 36
	beep_chord(QUAVER, 2, g2, f4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, d3, g4);
	beep_chord(QUAVER, 2, f3, f4);
	beep_chord(QUAVER, 2, g2, eb4);
	beep_chord(QUAVER, 2, f3, d4);
	beep_chord(QUAVER, 2, d3, d4);
	beep_chord(QUAVER, 2, f3, c4);

	// 37
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(QUAVER, 2, g3, c4);
	beep_chord(QUAVER, 2, eb3, eb4);
	beep_chord(QUAVER, 2, g3, eb4);
	beep_chord(QUAVER, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, c4);
	beep_chord(QUAVER, 2, g3, eb4);

	// 38
	beep_chord(QUAVER, 2, c3, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(SEPARATION, 2, g3, 1);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, c3, f4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, g3, f4);
	beep_chord(QUAVER, 2, eb3, g4);
	beep_chord(SEPARATION, 2, eb3, 1);
	beep_chord(QUAVER, 2, g3, g4);

	// 39
	beep_chord(QUAVER, 2, f2, bb4);
	beep_chord(QUAVER, 2, c3, ab4);
	beep_chord(SEPARATION, 2, c3, 1);
	beep_chord(QUAVER, 2, ab2, ab4);
	beep_chord(QUAVER, 2, c3, ab4);
	beep_chord(QUAVER, 2, f2, 1);
	beep_chord(QUAVER, 2, c3, ab4);
	beep_chord(QUAVER, 2, ab2, g4);
	beep_chord(QUAVER, 2, c3, f4);

	// 40
	beep_chord(QUAVER, 2, g2, g4);
	beep_chord(QUAVER, 2, g3, g4);
	beep_chord(QUAVER, 2, ab2, f4);
	beep_chord(QUAVER, 2, ab3, f4);
	beep_chord(QUAVER, 2, a2, eb4);
	beep_chord(QUAVER, 2, b2, d4);
	beep_chord(QUAVER, 2, b3, d4);
	beep_chord(QUAVER, 2, c3, c4);

	// 41
	beep_chord(QUAVER, 2, c3, c4);
	beep_chord(QUAVER, 2, c2, c5);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c2, c5);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c2, c5);
	beep(r, SEPARATION);
	beep_chord(QUAVER*2, 2, c2, c5);
	beep_chord(SEPARATION, 2, 1, c5);
	beep_chord(QUAVER, 2, c2, g5);
	beep_chord(QUAVER, 2, c2, f5);

	// 42
	beep_chord(QUAVER, 2, g2, g5);
	beep_chord(QUAVER, 2, g3, g5);
	beep_chord(QUAVER, 2, ab2, f5);
	beep_chord(QUAVER, 2, ab3, f5);
	beep_chord(QUAVER, 2, a2, eb5);
	beep_chord(QUAVER, 2, b2, d5);
	beep_chord(QUAVER, 2, b3, d5);
	beep_chord(QUAVER, 2, c3, c5);

	// 43
	beep_chord(QUAVER, 2, c3, c5);
	beep_chord(QUAVER, 2, c2, c5);
	beep_chord(SEPARATION, 2, 1, c5);
	beep_chord(QUAVER, 2, c2, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c2, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c2, 1);
	beep(r, SEPARATION);
	beep_chord(QUAVER, 2, c2, 1);
	beep_chord(QUAVER, 2, c2, ab5);
	beep_chord(SEPARATION, 2, 1, ab5);
	beep_chord(QUAVER, 2, c2, g5);
	beep_chord(QUAVER, 2, c2, f5);

	// 44
	beep_chord(QUAVER, 2, g2, g5);
	beep_chord(QUAVER, 2, g3, g5);
	beep_chord(QUAVER, 3, ab2, f5, ab5);
	beep_chord(QUAVER, 3, ab3, f5, ab5);
	beep_chord(QUAVER, 3, a2, eb5, bb5);
	beep_chord(QUAVER, 3, b2, d5, b5);
	beep_chord(QUAVER, 3, b3, d5, b5);
	beep_chord(QUAVER, 3, c3, c5, c6);

	// 45
	beep_chord(QUAVER, 3, c3, c5, c6);
	beep(r, QUAVER);
	beep_chord(QUAVER*5, 4, c2, eb4, g4, d5);
	beep_chord(DEMISEMIQUAVER, 4, g2, eb4, g4, d5);
	beep_chord(DEMISEMIQUAVER, 4, f2, eb4, g4, d5);
	beep_chord(DEMISEMIQUAVER, 4, eb2, eb4, g4, d5);
	beep_chord(DEMISEMIQUAVER, 4, d2, eb4, g4, d5);

	// 46
	beep_chord(QUAVER, 4, c2, eb3, g3, d3);

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

void beep_chord(uint64_t length, int num_notes, ...) {
	struct timespec start;
	struct timespec time;
	uint64_t diff;
	va_list arg_ptr;
	int periods[num_notes];
	uint64_t sample = 0;
	int samples[num_notes];
	uint64_t next_tick;
	uint64_t overshoot = 0;

	va_start(arg_ptr, num_notes);
	for (int i = 0; i < num_notes; i++) {
		periods[i] = CLOCK_TICK_RATE / va_arg(arg_ptr, int);
		samples[i] = 1;
	}
	va_end(arg_ptr);

	clock_gettime(CLOCK_REALTIME, &start);
	clock_gettime(CLOCK_REALTIME, &time);
	diff  = time_diff(&time, &start) * CLOCK_TICK_RATE / 1000000000;

	while (diff < length * CLOCK_TICK_RATE / 1000000000) {
		next_tick = UINT64_MAX;
		for (int i = 0; i < num_notes; i++) {
			next_tick = min(next_tick, periods[i] * samples[i]);
		}
		for (int i = 0; i < num_notes; i++) {
			if (next_tick == periods[i] * samples[i]) {
				samples[i]++;
			}
		}
		/* 
		 * The following two magic numbers are just that - they sound
		 * good on George's machine, who knows why.
		 */
		ioctl(console_fd, KIOCSOUND, 40000);
		while (diff < sample + 100) {
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
