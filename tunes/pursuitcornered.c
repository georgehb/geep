#define BPM 150

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
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(QUAVER,     3, 	gb2, 	db4, 	gb4);
	
	// 2
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(QUAVER,     3, 	e2, 	b3, 	e4);
	
	// 3
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(QUAVER,     3, 	gb2, 	db4, 	gb4);
	
	// 4
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 4, 	f2, 	g4, 	c5, 	g5);
	beep(SEPARATION, 3, 		g4, 	c5, 	g5);
	beep(QUAVER,     4, 	f2, 	g4, 	c5, 	g5);
	beep(SEPARATION, 3, 	 	g4, 	c5, 	g5);
	beep(SEMIQUAVER, 4, 	f2, 	g4, 	c5, 	g5);
	beep(SEPARATION, 3, 	 	g4, 	c5, 	g5);
	beep(QUAVER,     4, 	f2, 	g4, 	c5, 	g5);
	beep(QUAVER,     4, 	e2, 	g4, 	c5, 	g5);

loop:
	// 5
	beep(QUAVER,     4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(QUAVER,     4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(QUAVER,     4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(QUAVER,     4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 2, 	f2, 			bb5);
	beep(SEMIQUAVER, 2, 	f2, 			c6);

	// 6
	beep(QUAVER,     4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 3, 	 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(QUAVER,     4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(QUAVER,     4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(QUAVER,     4, 	ab2, 	f4, 	c5, 	f5);
	beep(SEPARATION, 3, 	 	f4, 	c5, 	f5);
	beep(SEMIQUAVER, 2, 	ab2, 			g5);
	beep(SEMIQUAVER, 2, 	ab2, 			ab5);

	// 7
	beep(QUAVER,     3, 	db2, 	 	bb4, 	bb5);
	beep(SEPARATION, 2, 	 	 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	db5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	db5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	db5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	 	f5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	db2, 	f5, 	bb4);
	beep(SEPARATION, 2, 	 	f5, 	bb4);
	beep(QUAVER,     4, 	db2, 	bb5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	bb5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	ab5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	ab5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	ab5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	db5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	db5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	db5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	db5, 	bb4, 	bb5);
	beep(QUAVER,     4, 	db2, 	f5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	f5, 	bb4, 	bb5);
	beep(QUAVER,     4, 	db2, 	ab5,	bb4,	bb5);

	// 8
	beep(QUAVER,     3, 	eb2, 	 	g4, 	g5);
	beep(SEPARATION, 2, 	 	 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	bb4, 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	 	eb5, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	eb2, 	eb5, 	g4);
	beep(SEPARATION, 2, 	 	eb5, 	g4);
	beep(QUAVER,     4, 	eb2, 	g5, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	g5, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	eb2, 	 	eb4, 	eb5);
	beep(SEPARATION, 2, 	 	 	eb4, 	eb5);
	beep(SEMIQUAVER, 2, 	eb2, 	 	 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	eb4, 	eb4, 	eb5);
	beep(SEPARATION, 3, 	 	eb4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	eb4, 	eb4, 	eb5);
	beep(SEPARATION, 3, 	 	eb4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 3, 	eb2, 	bb4, 	eb4);
	beep(SEPARATION, 2,	 	bb4, 	eb4);
	beep(QUAVER,     4, 	eb2, 	eb5,	eb4,	eb5);

	// 9
	beep(QUAVER,     3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	f4, 	f5);
	beep(SEMIQUAVER, 2, 	 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(QUAVER,     3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(QUAVER,     3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	f4, 	f5);
	beep(SEPARATION, 2, 	 	f4, 	f5);
	beep(QUAVER,     3, 	f2, 	c5, 	c6);
	beep(SEPARATION, 2, 	 	c5, 	c6);
	beep(SEMIQUAVER, 3, 	f2, 	c5,	c6);
	beep(SEMIQUAVER, 3, 	f2, 	c5,	c6);

	// 10
	beep(QUAVER,     3, 	ab2, 	 	db5, 	db6);
	beep(SEPARATION, 2, 	 	 	db5, 	db6);
	beep(SEMIQUAVER, 4, 	ab2, 	f5, 	db5, 	db6);
	beep(SEPARATION, 3, 	 	f5, 	db5, 	db6);
	beep(SEMIQUAVER, 4, 	ab2, 	f5, 	db5, 	db6);
	beep(SEMIQUAVER, 3, 	 	ab5, 	db5, 	db6);
	beep(SEMIQUAVER, 3, 	ab2, 	ab5, 	db5);
	beep(SEPARATION, 2, 	 	ab5, 	db5);
	beep(QUAVER,     4, 	ab2, 	db6, 	db5, 	db6);
	beep(SEPARATION, 3, 	 	db6, 	db5, 	db6);
	beep(SEMIQUAVER, 2, 	ab2, 	 	 	c6);
	beep(SEPARATION, 1, 	 	 	 	c6);
	beep(SEMIQUAVER, 3, 	ab2, 	c5, 	c5, 	c6);
	beep(SEMIQUAVER, 3, 	ab2, 	g5, 	c5);
	beep(SEPARATION, 3, 	 	g5, 	c5);
	beep(SEMIQUAVER, 4, 	ab2, 	c6, 	c5, 	c6);
	beep(SEPARATION, 3, 	 	c6, 	c5, 	c6);
	beep(SEMIQUAVER, 3, 	ab2, 	 	ab4, 	ab5);
	beep(SEMIQUAVER, 4, 	ab2, 	c5, 	ab4, 	ab5);
	beep(SEPARATION, 3, 	 	c5, 	ab4, 	ab5);
	beep(SEMIQUAVER, 3, 	ab2, 	f5,	ab4);
	beep(SEPARATION, 3, 	ab2, 	f5,	ab4);
	beep(SEMIQUAVER, 4, 	ab2, 	ab5,	ab4,	ab5);

	// 11
	beep(SEMIQUAVER, 3, 	db2, 	 	bb4, 	bb5);
	beep(SEMIQUAVER, 2, 	db2, 	 	 	bb5);
	beep(SEPARATION, 1, 	 	 	 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	 	eb5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	db2, 	eb5, 	bb4);
	beep(SEPARATION, 2, 	 	eb5, 	bb4);
	beep(QUAVER,     4, 	db2, 	bb5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	bb5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	db2, 	 	eb5, 	eb6);
	beep(SEPARATION, 2, 	 	 	eb5, 	eb6);
	beep(SEMIQUAVER, 2, 	db2, 	 	 	eb6);
	beep(SEMIQUAVER, 4, 	db2, 	eb5, 	eb5, 	eb6);
	beep(SEPARATION, 3, 	 	eb5, 	eb5, 	eb6);
	beep(SEMIQUAVER, 4, 	db2, 	eb5, 	eb5, 	eb6);
	beep(SEPARATION, 3, 	 	eb5, 	eb5, 	eb6);
	beep(QUAVER,     3, 	db2, 	bb5, 	eb5);
	beep(SEPARATION, 2, 	 	bb5, 	eb5);
	beep(QUAVER,     4, 	db2, 	eb6,	eb5,	eb6);

	// 12
	beep(SEMIQUAVER, 3, 	eb2, 	 	c5, 	c6);
	beep(SEMIQUAVER, 2, 	eb2, 	 	 	c6);
	beep(SEPARATION, 1, 	 	 	 	c6);
	beep(SEMIQUAVER, 4, 	eb2, 	c5, 	c5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	c5, 	c6);
	beep(SEMIQUAVER, 4, 	eb2, 	c5, 	c5, 	c6);
	beep(SEMIQUAVER, 3, 	 	f5, 	c5, 	c6);
	beep(SEMIQUAVER, 3, 	eb2, 	f5, 	c5);
	beep(SEPARATION, 2, 	 	f5, 	c5);
	beep(QUAVER,     4, 	eb2, 	c6, 	c5, 	c6);
	beep(SEPARATION, 3, 	 	c6, 	c5, 	c6);
	beep(SEMIQUAVER, 3, 	eb2, 	 	bb4, 	bb5);
	beep(SEPARATION, 2, 	 	 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	eb2, 	 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	eb2, 	c5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	c5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	eb2, 	c5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	c5, 	bb4, 	bb5);
	beep(QUAVER,     3, 	eb2, 	 	ab4, 	ab5);
	beep(QUAVER,     4, 	eb2, 	c5,	ab4,	ab5);

	// 13
	beep(QUAVER,     3, 	f2, 	 	g4, 	g5);
	beep(SEPARATION, 2, 	 	 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	ab4, 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	 	eb5, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	f2, 	eb5, 	g4);
	beep(SEPARATION, 2, 	 	eb5, 	g4);
	beep(QUAVER,     4, 	f2, 	g5, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	g5, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	f2, 	 	ab4, 	ab5);
	beep(SEPARATION, 2, 	 	 	ab4, 	ab5);
	beep(SEMIQUAVER, 2, 	f2, 	 	 	ab5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	ab4, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	ab4, 	ab5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	ab4, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	ab4, 	ab5);
	beep(SEMIQUAVER, 4, 	f2, 	eb4, 	ab4, 	ab5);
	beep(SEMIQUAVER, 3, 	f2, 	eb4, 	ab4);
	beep(SEPARATION, 2, 	 	eb4, 	ab4);
	beep(QUAVER,     4, 	f2, 	ab5,	ab4,	ab5);
	
	// 14
	beep(QUAVER,     4, 	c2, 	f4, 	c5, 	f5);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	c2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	c2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	c2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	c2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	c2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	c2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	c2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	c2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	c2, 	b3, 	e4);
	
	// 15
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	db2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	db2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	db2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	db2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	db4, 	gb4);
	
	// 16
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	eb2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	eb2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	b3, 	e4);
	
	// 17
	beep(QUAVER,     4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(QUAVER,     4, 	f2, 	c5, 	f5, 	c6);
	beep(SEPARATION, 3, 	 	c5, 	f5, 	c6);
	beep(SEMIQUAVER, 4, 	f2, 	eb5, 	ab5, 	eb6);
	beep(SEPARATION, 3, 	 	eb5, 	ab5, 	eb6);
	beep(QUAVER,     4, 	f2, 	eb5, 	ab5, 	eb6);
	beep(SEPARATION, 3, 	 	eb5, 	ab5, 	eb6);
	beep(SEMIQUAVER, 4, 	f2, 	eb5, 	ab5, 	eb6);
	beep(SEPARATION, 3, 	 	eb5, 	ab5, 	eb6);
	beep(QUAVER,     4, 	f2, 	eb5, 	ab5, 	eb6);
	beep(SEPARATION, 2, 	 	eb5, 	ab5, 	eb6);
	beep(SEMIQUAVER, 2, 	f2, 			ab5);
	beep(SEMIQUAVER, 2, 	f2, 			bb5);

	// 18
	beep(QUAVER,     4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 3, 	 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(QUAVER,     4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(QUAVER,     4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 3, 	 	ab4, 	c5, 	ab5);
	beep(QUAVER,     4, 	ab2, 	ab4, 	c5, 	ab5);
	beep(SEPARATION, 4, 	 	ab4, 	c5, 	ab5);
	beep(SEMIQUAVER, 2, 	ab2, 			bb5);
	beep(SEMIQUAVER, 2, 	ab2, 			c6);

	// 19
	beep(QUAVER,     4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEMIQUAVER, 3, 	 	bb4, 	eb5, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(QUAVER,     4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(QUAVER,     4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(SEMIQUAVER, 4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 3, 	 	bb4, 	eb5, 	bb5);
	beep(QUAVER,     4, 	db2, 	bb4, 	eb5, 	bb5);
	beep(SEPARATION, 4, 	 	bb4, 	eb5, 	bb5);
	beep(QUAVER,     4, 	db2, 	bb4,	eb5,	bb5);

	// 20
	beep(QUAVER,     3, 	eb2, 	 	g4, 	g5);
	beep(SEPARATION, 2, 	 	 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	bb4, 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	 	eb5, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	eb2, 	eb5, 	g4);
	beep(SEPARATION, 2, 	 	eb5, 	g4);
	beep(QUAVER,     4, 	eb2, 	g5, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	g5, 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	eb2, 	 	eb4, 	eb5);
	beep(SEPARATION, 2, 	 	 	eb4, 	eb5);
	beep(SEMIQUAVER, 2, 	eb2, 	 	 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	eb4, 	eb4, 	eb5);
	beep(SEPARATION, 3, 	 	eb4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	eb4, 	eb4, 	eb5);
	beep(SEPARATION, 3, 	 	eb4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	g4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	eb2, 	g4, 	eb4, 	eb5);
	beep(SEPARATION, 3,	 	g4, 	eb4, 	eb5);
	beep(QUAVER,     4, 	eb2, 	bb4,	eb4,	eb5);

	// 21
	beep(QUAVER,     3, 	f2, 	 	f4, 	f5);
	beep(SEPARATION, 2, 	 	 	f4, 	f5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	f4, 	f5);
	beep(SEPARATION, 3, 	 	ab4, 	f4, 	f5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	 	c5, 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	c5, 	f4);
	beep(SEPARATION, 2, 	 	c5, 	f4);
	beep(QUAVER,     4, 	f2, 	f5, 	f4, 	f5);
	beep(SEPARATION, 3, 	 	f5, 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	f2, 	 	c4, 	c5);
	beep(SEPARATION, 2, 	 	 	c4, 	c5);
	beep(SEMIQUAVER, 2, 	f2, 	 	 	c5);
	beep(SEMIQUAVER, 4, 	f2, 	f4, 	c4, 	c5);
	beep(SEPARATION, 3, 	 	f4, 	c4, 	c5);
	beep(SEMIQUAVER, 4, 	f2, 	f4, 	c4, 	c5);
	beep(SEPARATION, 3, 	 	f4, 	c4, 	c5);
	beep(SEMIQUAVER, 4, 	f2, 	ab4, 	c4, 	c5);
	beep(SEMIQUAVER, 3, 	f2, 	ab4, 	c4);
	beep(SEPARATION, 2,	 	ab4, 	c4);
	beep(QUAVER,     4, 	f2, 	c5,	c4,	c5);

	// 22
	beep(SEMIQUAVER, 3, 	ab2, 	 	db4, 	db5);
	beep(SEMIQUAVER, 2, 	ab2, 	 	 	db5);
	beep(SEPARATION, 1, 	 	 	 	db5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	db4, 	db5);
	beep(SEPARATION, 3, 	 	f4, 	db4, 	db5);
	beep(SEMIQUAVER, 4, 	ab2, 	f4, 	db4, 	db5);
	beep(SEMIQUAVER, 3, 	 	ab4, 	db4, 	db5);
	beep(SEMIQUAVER, 3, 	ab2, 	ab4, 	db4);
	beep(SEPARATION, 2, 	 	ab4, 	db4);
	beep(QUAVER,     4, 	ab2, 	db5, 	db4, 	db5);
	beep(SEPARATION, 3, 	 	db5, 	db4, 	db5);
	beep(SEMIQUAVER, 3, 	ab2, 	 	eb4, 	eb5);
	beep(SEPARATION, 2, 	 	 	eb4, 	eb5);
	beep(SEMIQUAVER, 3, 	ab2, 	 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	eb4, 	eb5);
	beep(SEPARATION, 3, 	 	ab4, 	eb4, 	eb5);
	beep(SEMIQUAVER, 4, 	ab2, 	ab4, 	eb4, 	eb5);
	beep(SEPARATION, 3, 	 	ab4, 	eb4, 	eb5);
	beep(QUAVER,     3, 	ab2, 	 	g4, 	g5);
	beep(QUAVER,     4, 	ab2, 	bb4,	g4,	g5);

	// 23
	beep(QUAVER,     3, 	db2, 	 	ab4, 	ab5);
	beep(SEPARATION, 2, 	 	 	ab4, 	ab5);
	beep(SEMIQUAVER, 4, 	db2, 	c5, 	ab4, 	ab5);
	beep(SEPARATION, 3, 	 	c5, 	ab4, 	ab5);
	beep(SEMIQUAVER, 4, 	db2, 	c5, 	ab4, 	ab5);
	beep(SEMIQUAVER, 3, 	 	eb5, 	ab4, 	ab5);
	beep(SEMIQUAVER, 3, 	db2, 	eb5, 	ab4);
	beep(SEPARATION, 2, 	 	eb5, 	ab4);
	beep(QUAVER,     4, 	db2, 	ab5, 	ab4, 	ab5);
	beep(SEPARATION, 3, 	 	ab5, 	ab4, 	ab5);
	beep(SEMIQUAVER, 3, 	db2, 	 	f4, 	f5);
	beep(SEPARATION, 2, 	 	 	f4, 	f5);
	beep(SEMIQUAVER, 2, 	db2, 	 	 	f5);
	beep(SEMIQUAVER, 4, 	db2, 	ab4, 	f4, 	f5);
	beep(SEPARATION, 3, 	 	ab4, 	f4, 	f5);
	beep(SEMIQUAVER, 4, 	db2, 	ab4, 	f4, 	f5);
	beep(SEPARATION, 3, 	 	ab4, 	f4, 	f5);
	beep(SEMIQUAVER, 4, 	db2, 	c5, 	f4, 	f5);
	beep(SEMIQUAVER, 3, 	db2, 	c5, 	f4);
	beep(SEPARATION, 2,	 	c5, 	f4);
	beep(QUAVER,     4, 	db2, 	f5,	f4,	f5);

	// 24
	beep(SEMIQUAVER, 3, 	eb2, 	 	bb4, 	bb5);
	beep(SEMIQUAVER, 2, 	eb2, 	 	 	bb5);
	beep(SEPARATION, 1, 	 	 	 	bb5);
	beep(SEMIQUAVER, 4, 	eb2, 	db5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	db5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 4, 	eb2, 	db5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	 	f5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	eb2, 	f5, 	bb4);
	beep(SEPARATION, 2, 	 	f5, 	bb4);
	beep(QUAVER,     4, 	eb2, 	bb5, 	bb4, 	bb5);
	beep(SEPARATION, 3, 	 	bb5, 	bb4, 	bb5);
	beep(SEMIQUAVER, 3, 	eb2, 	 	g4, 	g5);
	beep(SEPARATION, 2, 	 	 	g4, 	g5);
	beep(SEMIQUAVER, 3, 	eb2, 	 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	bb4, 	g4, 	g5);
	beep(SEMIQUAVER, 4, 	eb2, 	bb4, 	g4, 	g5);
	beep(SEPARATION, 3, 	 	bb4, 	g4, 	g5);
	beep(QUAVER,     3, 	eb2, 	 	eb4, 	eb5);
	beep(QUAVER,     4, 	eb2, 	bb4,	eb4,	eb5);
	
	// 25
	beep(QUAVER,     4, 	f2, 	f4, 	c5, 	f5);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	f2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	f2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	gb2, 	db4, 	gb4);
	
	// 26
	beep(QUAVER,     3, 	g2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	g2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	g2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	g2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	g2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	g2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	g2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	g2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	g2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	g2, 	b3, 	e4);
	
	// 27
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	db2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	db2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	db2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	db2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	db2, 	db4, 	gb4);
	
	// 28
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 3,	eb2, 	c4, 	f4);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 	eb2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb2);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	beep(SEPARATION, 2, 	 	c4, 	f4);
	beep(SEMIQUAVER, 3,	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	c4, 	f4);
	rest(SEPARATION);
	beep(QUAVER,     3, 	eb2, 	b3, 	e4);
	goto loop;

	geep_close();
	exit(EXIT_SUCCESS);
}
