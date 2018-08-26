#define BPM 140

#include "notes.h"
#include "../geep.h"
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
	console_fd = geep_setup(100);
	signal(SIGINT, quit);

	// 1
	beep(QUAVER, 1, g4);
	beep(QUAVER, 1, c5);
	beep(QUAVER, 1, eb5);

	// 2
	beep(QUAVER, 2, c3, g5);
	beep(QUAVER, 2, g3, g5);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 2, eb3, g5);
	beep(QUAVER, 2, g3, f5);
	beep(QUAVER, 2, c3, f5);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, g3, f5);
	beep(QUAVER, 2, eb3, eb5);
	beep(QUAVER, 1, g3);

	// 3
	beep(QUAVER, 2, g2, d5);
	beep(QUAVER, 2, f3, d5);
	beep(QUAVER, 2, d3, f5);
	beep(QUAVER, 2, f3, f5);
	beep(QUAVER, 1, g2);
	beep(QUAVER, 2, g3, b4);
	beep(QUAVER, 2, d3, d5);
	beep(QUAVER, 2, f3, f5);

	// 4
	beep(QUAVER, 2, g2, ab5);
	beep(QUAVER, 2, f3, ab5);
	beep(SEPARATION, 1, f3);
	beep(QUAVER, 2, d3, ab5);
	beep(QUAVER, 2, f3, bb5);
	beep(QUAVER, 2, g2, bb5);
	beep(QUAVER, 2, f3, ab5);
	beep(QUAVER, 2, d3, g5);
	beep(QUAVER, 2, f3, f5);

	// 5
	beep(QUAVER, 2, c3, eb5);
	beep(QUAVER, 2, g3, eb5);
	beep(QUAVER, 2, eb3, g5);
	beep(QUAVER, 2, g3, g5);
	beep(QUAVER, 1, c3);
	beep(QUAVER, 2, g3, g4);
	beep(QUAVER, 2, eb3, c5);
	beep(QUAVER, 2, g3, eb5);

	// 6
	beep(QUAVER, 2, c3, c6);
	beep(QUAVER, 2, g3, c6);
	beep(QUAVER, 1, eb3);
	beep(QUAVER, 2, g3, c6);
	beep(QUAVER, 2, c3, b5);
	beep(QUAVER, 2, g3, b5);
	beep(QUAVER, 1, eb3);
	beep(QUAVER, 2, g3, b5);

	// 7
	beep(QUAVER, 2, f2, bb5);
	beep(QUAVER, 2, c3, bb5);
	beep(QUAVER, 2, ab2, ab5);
	beep(QUAVER, 1, ab5);
	rest(QUAVER);
	beep(QUAVER, 1, ab5);
	beep(QUAVER, 1, g5);
	beep(QUAVER, 1, f5);

	// 8
	beep(QUAVER, 2, g2, g5);
	beep(QUAVER, 2, g3, g5);
	beep(QUAVER, 2, ab2, f5);
	beep(QUAVER, 2, ab3, f5);
	beep(QUAVER, 2, a2, eb5);
	beep(QUAVER, 2, b2, d5);
	beep(QUAVER, 2, b3, d5);
	beep(QUAVER*3, 2, c3, c5);

	// 9
	rest(QUAVER);
	beep(QUAVER*3, 1, g2);
	beep(QUAVER, 2, g2, g3);
	beep(QUAVER, 2, g2, c4);
	beep(QUAVER, 2, g2, eb3);

	// 10
	beep(QUAVER, 2, c3, g4);
	beep(QUAVER, 2, g3, g4);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 2, eb3, g4);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, c3, f4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, eb3, eb4);
	beep(SEPARATION, 1, eb3);
	beep(QUAVER, 2, g3, eb4);
	
	// 11
	beep(QUAVER, 2, g2, d4);
	beep(QUAVER, 2, f3, d4);
	beep(QUAVER, 2, d3, f4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 1, g2);
	beep(QUAVER, 2, f3, g3);
	beep(QUAVER, 2, d3, b3);
	beep(QUAVER, 2, f3, d4);

	// 12
	beep(QUAVER, 2, g2, f4);
	beep(QUAVER, 2, f3, f4);
	beep(SEPARATION, 1, f3);
	beep(QUAVER, 2, d3, f4);
	beep(QUAVER, 2, f3, eb4);
	beep(QUAVER, 2, g2, eb4);
	beep(SEPARATION, 1, g2);
	beep(QUAVER, 2, f3, eb4);
	beep(QUAVER, 2, d3, d4);
	beep(QUAVER, 2, f3, d4);

	// 13
	beep(QUAVER, 2, c3, c4);
	beep(QUAVER, 2, g3, c4);
	beep(QUAVER, 2, eb3, eb4);
	beep(QUAVER, 2, g3, eb4);
	beep(QUAVER, 1, c3);
	beep(QUAVER, 1, g3);
	beep(QUAVER, 2, eb3, c4);
	beep(QUAVER, 2, g3, eb4);
	
	// 14
	beep(QUAVER, 2, c3, g4);
	beep(QUAVER, 2, g3, g4);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 2, eb3, g4);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, c3, f4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, eb3, eb4);
	beep(SEPARATION, 1, eb3);
	beep(QUAVER, 2, g3, eb4);
	
	// 15
	beep(QUAVER, 2, g2, d4);
	beep(QUAVER, 2, f3, d4);
	beep(QUAVER, 2, d3, f4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 1, g2);
	beep(QUAVER, 2, f3, g3);
	beep(QUAVER, 2, d3, b3);
	beep(QUAVER, 2, f3, d4);

	// 16
	beep(QUAVER, 2, g2, f4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 2, d3, g4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 2, g2, eb4);
	beep(QUAVER, 2, f3, d4);
	beep(QUAVER, 2, d3, d4);
	beep(QUAVER, 2, f3, eb4);

	// 17
	beep(QUAVER, 2, c3, eb4);
	beep(QUAVER, 2, gb2, eb4);
	beep(QUAVER, 1, g2);
	beep(QUAVER, 1, b2);
	beep(QUAVER, 1, c3);
	beep(QUAVER, 2, c3, g3);
	beep(QUAVER, 2, c3, c4);
	beep(QUAVER, 2, c3, eb4);

	// 18
	beep(QUAVER, 3, c3, eb4, g4);
	beep(QUAVER, 3, g3, eb4, g4);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 3, eb3, eb4, g4);
	beep(QUAVER, 3, g3, d4, f4);
	beep(QUAVER, 3, c3, d4, f4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 3, g3, d4, f4);
	beep(QUAVER, 3, eb3, c4, eb4);
	beep(SEPARATION, 1, eb3);
	beep(QUAVER, 3, g3, c4, eb4);
	
	// 19
	beep(QUAVER, 3, g2, b3, d4);
	beep(QUAVER, 3, f3, b3, d4);
	beep(QUAVER, 3, d3, d4, f4);
	beep(QUAVER, 3, f3, d4, f4);
	beep(QUAVER, 1, g2);
	beep(QUAVER, 2, f3, g3);
	beep(QUAVER, 2, d3, b3);
	beep(QUAVER, 2, f3, d4);

	// 20
	beep(QUAVER, 3, g2, d4, f4);
	beep(QUAVER, 3, f3, d4, f4);
	beep(SEPARATION, 1, f3);
	beep(QUAVER, 3, d3, d4, f4);
	beep(QUAVER, 3, f3, c4, eb4);
	beep(QUAVER, 3, g2, c4, eb4);
	beep(SEPARATION, 1, g2);
	beep(QUAVER, 3, f3, c4, eb4);
	beep(QUAVER, 3, d3, b3, d4);
	beep(QUAVER, 3, f3, b3, d4);

	// 21
	beep(QUAVER, 3, c3, g3, c4);
	beep(QUAVER, 1, g3);
	beep(QUAVER, 3, eb3, g3, eb4);
	beep(QUAVER, 1, g3);
	beep(QUAVER, 1, c3);
	beep(QUAVER, 1, g3);
	beep(QUAVER, 2, eb3, c4);
	beep(QUAVER, 2, g3, eb4);

	// 22
	beep(QUAVER, 2, c3, g4);
	beep(QUAVER, 2, g3, g4);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 2, eb3, g4);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, c3, f4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, eb3, g4);
	beep(SEPARATION, 1, eb3);
	beep(QUAVER, 2, g3, g4);

	// 23
	beep(QUAVER, 2, f2, bb4);
	beep(QUAVER, 2, c3, bb4);
	beep(QUAVER, 2, ab2, ab4);
	beep(QUAVER, 2, c3, ab4);
	beep(QUAVER, 1, f2);
	beep(QUAVER, 2, c3, ab4);
	beep(QUAVER, 2, ab2, g4);
	beep(QUAVER, 2, c3, f4);

	// 24
	beep(QUAVER, 2, g2, g4);
	beep(QUAVER, 2, g3, g4);
	beep(QUAVER, 2, ab2, f4);
	beep(SEPARATION, 1, ab2);
	beep(QUAVER, 2, ab3, f4);
	beep(QUAVER, 2, a2, eb4);
	beep(QUAVER, 2, b2, d4);
	beep(QUAVER, 2, b3, d4);
	beep(QUAVER, 2, c3, c4);
	beep(SEPARATION, 1, c4);

	// 25
	beep(QUAVER, 2, c3, c4);
	beep(SEPARATION, 1, c4);
	beep(QUAVER, 2, c3, c4);
	beep(SEPARATION, 1, c4);
	beep(QUAVER, 1, c3);
	rest(SEPARATION);
	beep(QUAVER, 1, c3);
	rest(SEPARATION);
	beep(QUAVER, 1, c3);
	rest(SEPARATION);
	beep(QUAVER, 1, c3);
	rest(SEPARATION);
	beep(QUAVER, 2, c3, c4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, c3, c4);

	// 26
	beep(QUAVER, 3, f3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, ab3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, f3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, ab3, g5, bb5);
	beep(QUAVER, 3, c4, ab5, c6);

	// 27
	beep(QUAVER, 3, f3, ab5, c6);
	beep(QUAVER, 3, c4, ab5, c6);
	beep(SEPARATION, 1, c4);
	beep(QUAVER, 3, ab3, ab5, c6);
	beep(QUAVER, 3, c4, ab5, c6);
	beep(QUAVER, 3, f3, g5, bb5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, ab3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);

	// 28
	beep(QUAVER, 3, c3, eb5, g5);
	beep(QUAVER, 3, g3, eb5, g5);
	beep(QUAVER, 3, eb3, eb5, g5);
	beep(QUAVER, 3, g3, d5, f5);
	beep(QUAVER, 3, c3, c5, eb5);
	beep(QUAVER, 3, g3, d5, f5);
	beep(QUAVER, 3, eb3, d5, f5);
	beep(QUAVER, 3, g3, eb5, g5);

	// 29
	beep(QUAVER, 3, c3, eb5, g5);
	beep(QUAVER, 3, g3, eb5, g5);
	beep(QUAVER, 3, eb3, eb5, g5);
	beep(QUAVER, 3, g3, eb5, g5);
	beep(QUAVER, 1, c3);
	beep(QUAVER, 1, g3);
	beep(QUAVER, 2, eb3, c5);
	beep(QUAVER, 2, g3, c5);

	// 30
	beep(QUAVER, 3, f3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, ab3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, f3, f5, ab5);
	beep(QUAVER, 3, c4, f5, ab5);
	beep(QUAVER, 3, ab3, g5, bb5);
	beep(QUAVER, 3, c4, ab5, c6);
	
	// 31
	beep(QUAVER, 3, ab3, ab5, c6);
	beep(QUAVER, 3, eb4, ab5, c6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 3, eb4, ab5, c6);
	beep(SEPARATION, 1, eb4);

	beep(QUAVER, 3, ab3, ab5, c6);
	beep(SIXTH, 3, eb4, ab5, c6);
	beep(SIXTH*2, 3, eb4, g5, bb5);
	beep(SIXTH*2, 3, c4, g5, bb5);
	beep(SIXTH, 3, c4, f5, ab5);
	beep(QUAVER, 3, eb4, f5, ab5);

	// 32
	beep(QUAVER, 2, d5, g5);
	beep(QUAVER, 1, gb2);
	beep(QUAVER, 1, g2);
	rest(QUAVER);
	beep(QUAVER, 1, eb3);
	beep(QUAVER, 1, d3);
	rest(QUAVER);
	beep(QUAVER, 1, bb2);

	// 33
	beep(QUAVER, 1, b2);
	beep(QUAVER, 1, d3);
	beep(QUAVER, 1, ab3);
	beep(QUAVER*2, 2, g2, g3);
	beep(SEPARATION, 1, g2);
	beep(QUAVER, 2, g2, g3);
	beep(QUAVER, 2, g3, c4);
	beep(QUAVER, 2, g3, eb4);

	// 34
	beep(QUAVER, 2, c3, g4);
	beep(QUAVER, 2, g3, g4);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 2, eb3, g4);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, c3, f4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, eb3, eb4);
	beep(SEPARATION, 1, eb3);
	beep(QUAVER, 2, g3, eb4);
	
	// 35
	beep(QUAVER, 2, g2, d4);
	beep(QUAVER, 2, f3, d4);
	beep(QUAVER, 2, d3, f4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 1, g2);
	beep(QUAVER, 2, f3, g3);
	beep(QUAVER, 2, d3, b3);
	beep(QUAVER, 2, f3, d4);

	// 36
	beep(QUAVER, 2, g2, f4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 2, d3, g4);
	beep(QUAVER, 2, f3, f4);
	beep(QUAVER, 2, g2, eb4);
	beep(QUAVER, 2, f3, d4);
	beep(QUAVER, 2, d3, d4);
	beep(QUAVER, 2, f3, c4);

	// 37
	beep(QUAVER, 2, c3, c4);
	beep(QUAVER, 2, g3, c4);
	beep(QUAVER, 2, eb3, eb4);
	beep(QUAVER, 2, g3, eb4);
	beep(QUAVER, 1, c3);
	beep(QUAVER, 1, g3);
	beep(QUAVER, 2, eb3, c4);
	beep(QUAVER, 2, g3, eb4);

	// 38
	beep(QUAVER, 2, c3, g4);
	beep(QUAVER, 2, g3, g4);
	beep(SEPARATION, 1, g3);
	beep(QUAVER, 2, eb3, g4);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, c3, f4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, g3, f4);
	beep(QUAVER, 2, eb3, g4);
	beep(SEPARATION, 1, eb3);
	beep(QUAVER, 2, g3, g4);

	// 39
	beep(QUAVER, 2, f2, bb4);
	beep(QUAVER, 2, c3, ab4);
	beep(SEPARATION, 1, c3);
	beep(QUAVER, 2, ab2, ab4);
	beep(QUAVER, 2, c3, ab4);
	beep(QUAVER, 1, f2);
	beep(QUAVER, 2, c3, ab4);
	beep(QUAVER, 2, ab2, g4);
	beep(QUAVER, 2, c3, f4);

	// 40
	beep(QUAVER, 2, g2, g4);
	beep(QUAVER, 2, g3, g4);
	beep(QUAVER, 2, ab2, f4);
	beep(QUAVER, 2, ab3, f4);
	beep(QUAVER, 2, a2, eb4);
	beep(QUAVER, 2, b2, d4);
	beep(QUAVER, 2, b3, d4);
	beep(QUAVER, 2, c3, c4);

	// 41
	beep(QUAVER, 2, c3, c4);
	beep(QUAVER, 2, c2, c5);
	rest(SEPARATION);
	beep(QUAVER, 2, c2, c5);
	rest(SEPARATION);
	beep(QUAVER, 2, c2, c5);
	rest(SEPARATION);
	beep(QUAVER*2, 2, c2, c5);
	beep(SEPARATION, 1, c5);
	beep(QUAVER, 2, c2, g5);
	beep(QUAVER, 2, c2, f5);

	// 42
	beep(QUAVER, 2, g2, g5);
	beep(QUAVER, 2, g3, g5);
	beep(QUAVER, 2, ab2, f5);
	beep(QUAVER, 2, ab3, f5);
	beep(QUAVER, 2, a2, eb5);
	beep(QUAVER, 2, b2, d5);
	beep(QUAVER, 2, b3, d5);
	beep(QUAVER, 2, c3, c5);

	// 43
	beep(QUAVER, 2, c3, c5);
	beep(QUAVER, 2, c2, c5);
	beep(SEPARATION, 1, c5);
	beep(QUAVER, 1, c2);
	rest(SEPARATION);
	beep(QUAVER, 1, c2);
	rest(SEPARATION);
	beep(QUAVER, 1, c2);
	rest(SEPARATION);
	beep(QUAVER, 1, c2);
	beep(QUAVER, 2, c2, ab5);
	beep(SEPARATION, 1, ab5);
	beep(QUAVER, 2, c2, g5);
	beep(QUAVER, 2, c2, f5);

	// 44
	beep(QUAVER, 2, g2, g5);
	beep(QUAVER, 2, g3, g5);
	beep(QUAVER, 3, ab2, f5, ab5);
	beep(QUAVER, 3, ab3, f5, ab5);
	beep(QUAVER, 3, a2, eb5, bb5);
	beep(QUAVER, 3, b2, d5, b5);
	beep(QUAVER, 3, b3, d5, b5);
	beep(QUAVER, 3, c3, c5, c6);

	// 45
	beep(QUAVER, 3, c3, c5, c6);
	rest(QUAVER);
	beep(QUAVER*5, 4, c2, eb4, g4, d5);
	beep(DEMISEMIQUAVER, 4, g2, eb4, g4, d5);
	beep(DEMISEMIQUAVER, 4, f2, eb4, g4, d5);
	beep(DEMISEMIQUAVER, 4, eb2, eb4, g4, d5);
	beep(DEMISEMIQUAVER, 4, d2, eb4, g4, d5);

	// 46
	beep(QUAVER, 4, c2, eb3, g3, d3);
	geep_close();
	exit(EXIT_SUCCESS);
}
