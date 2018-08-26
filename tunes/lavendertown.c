#define BPM 120
#define QUALITY 1 

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
	
/*	
120 

c3*1 g3*1 b3*1 f#3*1    c3*1 g3*1 b3*1 f#3*1    c3*1 g3*1 b3*1 f#3*1    c3*1 g3*1 b3*1 f#3*1

% bar 5 start of repeat
g3*2 g3*2     f#3*2 f#3*2    g3*1 f#3*1 e3*1 b3*1       e3*1 c3*1 b2*1 e3*1

% bar 9
g3*2 g3*2     f#3*2 f#3*2    g3*1 f#3*1 e3*1 b3*1       e3*1 c3*1 b2*1 e3*1
*/
	// 1
	beep(QUAVER, 1, 		c6);
	rest(QUAVER);
	beep(QUAVER, 1, 		g6);
	rest(QUAVER);
	beep(QUAVER, 1, 		b6);
	rest(QUAVER);
	beep(QUAVER, 1, 		fs6);
	rest(QUAVER);

	// 2
	beep(QUAVER, 1, 		c6);
	rest(QUAVER);
	beep(QUAVER, 1, 		g6);
	rest(QUAVER);
	beep(QUAVER, 1, 		b6);
	rest(QUAVER);
	beep(QUAVER, 1, 		fs6);
	rest(QUAVER);

	// 3
	beep(QUAVER, 1, 		c6);
	rest(QUAVER);
	beep(QUAVER, 1, 		g6);
	rest(QUAVER);
	beep(QUAVER, 1, 		b6);
	rest(QUAVER);
	beep(QUAVER, 1, 		fs6);
	rest(QUAVER);
	
	// 4
	beep(QUAVER, 1, 		c6);
	rest(QUAVER);
	beep(QUAVER, 1, 		g6);
	rest(QUAVER);
	beep(QUAVER, 1, 		b6);
	rest(QUAVER);
	beep(QUAVER, 1, 		fs6);
	rest(QUAVER);

loop:
	// 5
	beep(QUAVER, 3, e4,	g4,	c6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		g6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 3, e4,	g4,	b6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		fs6);
	beep(QUAVER, 1, e4);

	// 6
	beep(QUAVER, 3, d4,	fs4,	c6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4,		g6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 3, d4,	fs4,	b6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4, 		fs6);
	beep(QUAVER, 1, d4);

	// 7
	beep(QUAVER, 3, e4,	g4,	c6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 3, e4,	fs4,	g6);
	beep(QUAVER, 2, e4, 	fs4);
	beep(QUAVER, 3, e4,	e4,	b6);
	beep(QUAVER, 2, e4, 	e4);
	beep(QUAVER, 3, e4,	b4,	fs6);
	beep(QUAVER, 2, e4, 	g4);

	// 8
	beep(QUAVER, 3, cs4,	e4,	c6);
	beep(QUAVER, 2, cs4, 	e4);
	beep(QUAVER, 3, cs4,	c4,	g6);
	beep(QUAVER, 1, 	c4);
	beep(QUAVER, 3, cs4,	b3,	b6);
	beep(QUAVER, 2, cs4, 	b3);
	beep(QUAVER, 3, cs4,	e4,	fs6);
	beep(QUAVER, 1, 	e4);

	// 9
	beep(QUAVER, 3, e4,	g4,	c6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		g6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 3, e4,	g4,	b6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		fs6);
	beep(QUAVER, 1, e4);

	// 10
	beep(QUAVER, 3, d4,	fs4,	c6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4,		g6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 3, d4,	fs4,	b6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4, 		fs6);
	beep(QUAVER, 1, d4);

	// 11
	beep(QUAVER, 3, d4,	b4,	c6);
	beep(QUAVER, 2, d4, 	b4);
	beep(QUAVER, 3, d4,	g4,	g6);
	beep(QUAVER, 1, 	g4);
	beep(QUAVER, 3, d4,	fs4,	b6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 3, d4,	b4,	fs6);
	beep(QUAVER, 1, 	b4);

	// 12
	beep(QUAVER, 3, e4,	c5,	c6);
	beep(QUAVER, 2, e4, 	c5);
	beep(QUAVER, 3, c4,	c5,	g6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 3, b3,	c5,	b6);
	beep(QUAVER, 2, b3, 	c5);
	beep(QUAVER, 3, e4,	c5,	fs6);
	beep(QUAVER, 1, e4);

	// 13
	beep(QUAVER, 3, e4,	g4,	c6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		g6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 3, e4,	g4,	b6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		fs6);
	beep(QUAVER, 1, e4);

	// 14
	beep(QUAVER, 3, d4,	fs4,	c6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4,		g6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 3, d4,	fs4,	b6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4, 		fs6);
	beep(QUAVER, 1, d4);

	// 15
	beep(QUAVER, 3, e4,	g4,	c6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 3, e4,	fs4,	g6);
	beep(QUAVER, 2, e4, 	fs4);
	beep(QUAVER, 3, e4,	e4,	b6);
	beep(QUAVER, 2, e4, 	e4);
	beep(QUAVER, 3, e4,	b4,	fs6);
	beep(QUAVER, 2, e4, 	g4);

	// 16
	beep(QUAVER, 3, cs4,	e4,	c6);
	beep(QUAVER, 2, cs4, 	e4);
	beep(QUAVER, 3, cs4,	c4,	g6);
	beep(QUAVER, 1, 	c4);
	beep(QUAVER, 3, cs4,	b3,	b6);
	beep(QUAVER, 2, cs4, 	b3);
	beep(QUAVER, 3, cs4,	e4,	fs6);
	beep(QUAVER, 1, 	e4);

	// 17
	beep(QUAVER, 3, e4,	g4,	c6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		g6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 3, e4,	g4,	b6);
	beep(QUAVER, 2, e4, 	g4);
	beep(QUAVER, 2, e4, 		fs6);
	beep(QUAVER, 1, e4);

	// 18
	beep(QUAVER, 3, d4,	fs4,	c6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4,		g6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 3, d4,	fs4,	b6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 2, d4, 		fs6);
	beep(QUAVER, 1, d4);

	// 19
	beep(QUAVER, 3, d4,	b4,	c6);
	beep(QUAVER, 2, d4, 	b4);
	beep(QUAVER, 3, d4,	g4,	g6);
	beep(QUAVER, 1, 	g4);
	beep(QUAVER, 3, d4,	fs4,	b6);
	beep(QUAVER, 2, d4, 	fs4);
	beep(QUAVER, 3, d4,	b4,	fs6);
	beep(QUAVER, 1, 	b4);

	// 20
	beep(QUAVER, 2, c4,		c6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 2, c4,		g6);
	rest(QUAVER);
	beep(QUAVER, 2, c4,		b6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 2, c4,		fs6);
	rest(QUAVER);

	// 21
	beep(QUAVER, 2, e4,		c6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 2, e4,		g6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 2, e4,		b6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 2, e4,		fs6);
	beep(QUAVER, 1, e4);

	// 22
	beep(QUAVER, 2, d4,		c6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 2, d4,		g6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 2, d4,		b6);
	beep(QUAVER, 1, d4);
	beep(QUAVER, 2, d4,		fs6);
	beep(QUAVER, 1, d4);

	// 23
	beep(QUAVER, 2, c4,		c6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 2, c4,		g6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 2, c4,		b6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 2, c4,		fs6);
	beep(QUAVER, 1, c4);

	// 24
	beep(QUAVER, 2, e4,		c6);
	beep(QUAVER, 1, e4);
	beep(QUAVER, 2, c4,		g6);
	beep(QUAVER, 1, c4);
	beep(QUAVER, 2, b3,		b6);
	beep(QUAVER, 1, b3);
	beep(QUAVER, 2, e4,		fs6);
	beep(QUAVER, 1, e4);
	goto loop;

	geep_close();
	exit(EXIT_SUCCESS);
}
