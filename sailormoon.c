#define BPM 140
#define QUALITY 100 

#include "notes.h"
#include "geep.h"
#include <linux/kd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

static int console_fd = -1;

void quit(int sig)
{
	ioctl(console_fd, KIOCSOUND, 0);
	exit(EXIT_FAILURE);
}

int main()
{
	console_fd = geep_setup();
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
	geep_close();
	exit(EXIT_SUCCESS);
}
