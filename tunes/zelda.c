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
	beep(CROTCHET, 2, d4, 	bb4);
	rest(QUAVER);
	beep(SEMIQUAVER, 2, 1, 	bb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, 1, 	bb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, 1, 	bb2);
	rest(SEMIQUAVER);
	beep(QUAVER, 2, d4, 	bb4);
	rest(SEPARATION);
	beep(QUAVER, 2, d4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, d4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, d4, 	bb4);
	rest(SEPARATION);

	// 2
	beep(SEMIQUAVER*3, 2, c4, bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, c4, 	ab4);
	rest(SEPARATION);
	beep(QUAVER, 2, c4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, ab2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, ab2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, ab2);
	rest(SEMIQUAVER);
	beep(QUAVER, 2, c4, 	bb4);
	rest(SEPARATION);
	beep(QUAVER, 2, c4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, c4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, c4, 	bb4);
	rest(SEPARATION);

	// 3
	beep(SEMIQUAVER*3, 2, db4, bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, db4, 	ab4);
	rest(SEPARATION);
	beep(QUAVER, 2, db4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, gb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, gb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, gb2);
	rest(SEMIQUAVER);
	beep(QUAVER, 2, db4, 	bb4);
	rest(SEPARATION);
	beep(QUAVER, 2, db4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, db4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, db4, 	bb4);
	rest(SEPARATION);

	// 4
	beep(QUAVER, 2, db4, 	bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(QUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(QUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, a3, 	f4);
	rest(SEPARATION);
	beep(QUAVER, 2, eb2, 	f4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, g2, 	f4);
	beep(SEPARATION, 1, 	f4);
	beep(SEMIQUAVER, 2, a2, 	f4);
	rest(SEPARATION);

loop:
	// 5
	beep(SEMIQUAVER, 2, bb2, 	bb4);
	beep(SEMIQUAVER, 1,  	bb4);
	beep(SEMIQUAVER, 1, bb3);
	rest(SEMIQUAVER);
	beep(QUAVER, 1,  		f4);
	beep(SEMIQUAVER, 2, bb3, 	f4);
	beep(SEMIQUAVER, 1, 	f4);
	rest(QUAVER);
	beep(SEMIQUAVER, 1, bb3);
	beep(SEMIQUAVER, 1, 		bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, bb2, 	bb4);
	beep(SEMIQUAVER, 1, 	c5);
	beep(SEMIQUAVER, 2, bb3, 	d5);
	beep(SEMIQUAVER, 1, 	eb5);

	// 6
	beep(SEMIQUAVER, 2, ab2, 	f5);
	beep(SEMIQUAVER, 1, 	f5);
	beep(SEMIQUAVER, 3, ab3, 	f5, 	bb5);
	beep(SEMIQUAVER, 1, 	f5);
	beep(SEMIQUAVER, 2, 	f5, 	bb5);
	beep(SEMIQUAVER, 2, 	f5, 	c6);
	beep(SEMIQUAVER, 3, ab3, 	f5, 	d6);
	beep(SEMIQUAVER, 2,  	f5, 	eb6);
	beep(SEMIQUAVER, 3, ab2, 	f5, 	f6);
	beep(SEMIQUAVER, 2,  	f5,	f6);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, ab3, 	f5);
	beep(SEMIQUAVER, 1,  	f5);
	rest(SEPARATION);
	beep(QUAVER, 1,  		f5);
	beep(SEMIQUAVER, 2, ab3, 	gb5);
	beep(SEMIQUAVER, 1,  	ab5);

	// 7
	beep(SEMIQUAVER, 2, fs2, 	bb5);
	beep(SEMIQUAVER, 1,  	bb5);
	beep(SEMIQUAVER, 2, fs3, 	bb5);
	beep(SEMIQUAVER, 1, 	bb5);
	beep(SEMIQUAVER, 2, 	bb5, 	db6);
	beep(SEMIQUAVER, 2, 	bb5, 	gb6);
	beep(SEMIQUAVER, 3, fs3, 	bb5, 	ab6);
	beep(SEMIQUAVER, 2,  	bb5, 	bb6);
	beep(SEMIQUAVER, 3, fs2, 	bb5, 	db7);
	beep(SEMIQUAVER, 2,  	bb5,  	db7);
	rest(SEPARATION);
	beep(SEMIQUAVER, 2, fs3, 	bb5);
	beep(SEMIQUAVER, 1,  	bb5);
	rest(SEPARATION);
	beep(QUAVER, 1,  		bb5);
	beep(SEMIQUAVER, 2, fs3, 	ab5);
	beep(SEMIQUAVER, 1,  	gb5);

	// 8
	beep(SEMIQUAVER, 2, db3, 	ab5);
	beep(SEMIQUAVER, 1,  	ab5);
	beep(SEMIQUAVER, 1, db4);
	beep(SEMIQUAVER, 1,  	gb5);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 3, db4, 	f5, 	db6);
	beep(SEMIQUAVER, 2,  	f5, 	eb6);
	beep(SEMIQUAVER, 3, db3, 	f5, 	f6);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 3, db4, 	f5, 	db6);
	beep(SEMIQUAVER, 1, 	f5);
	beep(SEMIQUAVER, 2,  	f5, 	ab5);
	beep(SEMIQUAVER, 2,  	f5, 	ab5);
	beep(SEMIQUAVER, 1, db4);
	rest(SEMIQUAVER);

	// 9
	beep(SEMIQUAVER, 2, b2, 	eb5);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 2, b3, 	eb5);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 1,  	gb5);
	beep(SEMIQUAVER, 1,  	gb5);
	beep(SEMIQUAVER, 3, b3, 	gb5, 	eb6);
	beep(SEMIQUAVER, 2,  	gb5, 	f6);
	beep(SEMIQUAVER, 3, b2, 	gb5, 	gb6);
	beep(SEMIQUAVER, 1,  	gb5);
	beep(SEMIQUAVER, 3, b3, 	gb5, 	eb6);
	beep(SEMIQUAVER, 1,  		f6);
	beep(SEMIQUAVER, 2,  	f5, 	gb6);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 2, b3, 	eb5);
	beep(SEMIQUAVER, 1,  	eb5);

	// 10
	beep(SEMIQUAVER, 2, bb2, 	db5);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 2, bb3, 	db5);
	beep(SEMIQUAVER, 1,  	eb5);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 3, bb3, 	f5, 	db6);
	beep(SEMIQUAVER, 2, 	f5, 	eb6);
	beep(SEMIQUAVER, 3, bb2, 	f5, 	f6);
	beep(SEMIQUAVER, 1,  	f5);
	beep(SEMIQUAVER, 3, bb3, 	f5, 	db6);
	beep(SEMIQUAVER, 1,  		eb6);
	beep(SEMIQUAVER, 2,  	eb5, 	f6);
	beep(SEMIQUAVER, 1,  	eb5);
	beep(SEMIQUAVER, 2, bb3, 	db5);
	beep(SEMIQUAVER, 1,  	db5);

	// 11
	beep(SEMIQUAVER, 2, c3, 	c5);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 2, c4, 	c5);
	beep(SEMIQUAVER, 1,  	d5);
	beep(SEMIQUAVER, 1,  	e5);
	beep(SEMIQUAVER, 1,  	e5);
	beep(SEMIQUAVER, 3, c4, 	e5, 	c6);
	beep(SEMIQUAVER, 2, 	e5, 	d6);
	beep(SEMIQUAVER, 3, c3, 	e5, 	e6);
	beep(SEMIQUAVER, 1, 	e5);
	beep(SEMIQUAVER, 3, c4, 	e5, 	e6);
	beep(SEMIQUAVER, 1, 	 	f6);
	beep(SEMIQUAVER, 2, 	g5,	g6);
	beep(SEMIQUAVER, 2,  	g5, 	a6);
	beep(SEMIQUAVER, 3, c4, 	g5, 	bb6);
	beep(SEMIQUAVER, 2, 	g5, 	c7);

	// 12
	beep(SEMIQUAVER, 3, c5, 	f5, 	a6);
	rest(SEMIQUAVER);
	beep(SEMIQUAVER, 1, 		bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	 	bb4);
	rest(SEPARATION);
	beep(QUAVER, 1, 		bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		bb4);
	rest(SEPARATION);
	beep(QUAVER, 1, 		bb4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb3);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb3);
	rest(SEPARATION);
	beep(QUAVER, 1, 		eb3);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb3);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 	eb3);
	rest(SEPARATION);

	// 13
	beep(QUAVER, 1, 		f3);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		a4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		a4);
	rest(SEPARATION);
	beep(QUAVER, 1, 		a4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		a4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		a4);
	rest(SEPARATION);
	beep(QUAVER, 1, 		a4);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		eb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		eb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		eb2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		f2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		g2);
	rest(SEPARATION);
	beep(SEMIQUAVER, 1, 		a2);
	rest(SEPARATION);
	goto loop;

	geep_close();
	exit(EXIT_SUCCESS);
}
