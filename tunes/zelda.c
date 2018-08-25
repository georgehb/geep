#define BPM 150
#define QUALITY 100 

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
/*
   %% crotchet  = 4
   %% quaver    = 2
   %% semi quav = 1
   600

   bb2*4 r*2 bb1*1 bb1*1 bb1*2 bb2*2 bb2*2 bb2*1 bb2*1
   bb2*3 ab2*1 bb2*2 ab1*1 ab1*1 ab1*2 bb2*2 bb2*2 bb2*1 bb2*1
   bb2*3 ab2*1 bb2*2 gb1*1 gb1*1 gb1*2 bb2*2 bb2*2 bb2*1 bb2*1
   bb2*2 f2*1 f2*1 f2*2 f2*1 f2*1 f2*2 f2*1 f2*1 f2*2 f2*2

   % bar 5
   bb2*4 f2*4 r*2 bb2*2 bb2*1 c3*1 d3*1 eb3*1
   f3*2 bb3*2 bb3*1 c4*1 d4*1 eb4*1 f4*2 
   f3*2 f3*2 gb3*1 ab3*1

   bb3*4 gb4*1 ab4*1 bb4*1 c5*1 db5*1 r*1 
   bb3*2 bb3*2 ab3*1 gb3*1
   ab3*3 gb3*1 f3*2 db4*1 eb4*1 f4*2 db4*2 f3*4

   % bar 9
   eb3*3 f3*1 gb3*2 gb4*1 ab4*1 bb4*2 gb4*1 ab4*1 f3*2 eb3*2
   db3*3 eb3*1 f3*2 f4*1 gb4*1 ab4*2 f4*1 gb4*1 eb3*2 db3*2
   c3*3 d3*1 e3*2 e4*1 f4*1 g4*2 g4*1 a4*1 g3*4
   f3*2 bb2*1 bb2*1 bb2*2 bb2*1 bb2*1 bb2*2 r*4
   r*2 a2*1 a2*1 a2*2 a2*1 a2*1 a2*2 r*4
   */

int main()
{
	console_fd = geep_setup();
	signal(SIGINT, quit);

	beep_chord(CROTCHET, 2, 1, bb2);
	beep(QUAVER, r);
	beep_chord(SEMIQUAVER, 2, 1, bb1);
	beep_chord(SEMIQUAVER, 2, 1, bb1);
	beep_chord(QUAVER, 2, 1, bb1);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);

	beep_chord(SEMIQUAVER*3, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, ab2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, ab1);
	beep_chord(SEMIQUAVER, 2, 1, ab1);
	beep_chord(QUAVER, 2, 1, ab1);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);

	beep_chord(SEMIQUAVER*3, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, ab2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, gb1);
	beep_chord(SEMIQUAVER, 2, 1, gb1);
	beep_chord(QUAVER, 2, 1, gb1);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);

	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, f2);
	beep_chord(SEMIQUAVER, 2, 1, f2);
	beep_chord(QUAVER, 2, 1, f2);
	beep_chord(SEMIQUAVER, 2, 1, f2);
	beep_chord(SEMIQUAVER, 2, 1, f2);
	beep_chord(QUAVER, 2, 1, f2);
	beep_chord(SEMIQUAVER, 2, 1, f2);
	beep_chord(SEMIQUAVER, 2, 1, f2);
	beep_chord(QUAVER, 2, 1, f2);
	beep_chord(QUAVER, 2, 1, f2);

	beep_chord(CROTCHET, 2, 1, bb2);
	beep_chord(CROTCHET, 2, 1, f2);
	beep(QUAVER, r);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, c3);
	beep_chord(SEMIQUAVER, 2, 1, d3);
	beep_chord(SEMIQUAVER, 2, 1, eb3);

	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(QUAVER, 2, 1, bb3);
	beep_chord(SEMIQUAVER, 2, 1, bb3);
	beep_chord(SEMIQUAVER, 2, 1, c4);
	beep_chord(SEMIQUAVER, 2, 1, d4);
	beep_chord(SEMIQUAVER, 2, 1, eb4);
	beep_chord(QUAVER, 2, 1, f4);

	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(SEMIQUAVER, 2, 1, gb3);
	beep_chord(SEMIQUAVER, 2, 1, ab3);

	beep_chord(CROTCHET, 2, 1, bb3);
	beep_chord(SEMIQUAVER, 2, 1, gb4);
	beep_chord(SEMIQUAVER, 2, 1, ab4);
	beep_chord(SEMIQUAVER, 2, 1, bb4);
	beep_chord(SEMIQUAVER, 2, 1, c5);
	beep_chord(SEMIQUAVER, 2, 1, db5);
	beep(SEMIQUAVER, r);

	beep_chord(QUAVER, 2, 1, bb3);
	beep_chord(QUAVER, 2, 1, bb3);
	beep_chord(SEMIQUAVER, 2, 1, ab3);
	beep_chord(SEMIQUAVER, 2, 1, gb3);

	beep_chord(SEMIQUAVER*3, 2, 1, ab3);
	beep_chord(SEMIQUAVER, 2, 1, gb3);
	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(SEMIQUAVER, 2, 1, db4);
	beep_chord(SEMIQUAVER, 2, 1, eb4);
	beep_chord(QUAVER, 2, 1, f4);
	beep_chord(QUAVER, 2, 1, db4);
	beep_chord(CROTCHET, 2, 1, f3);

	beep_chord(SEMIQUAVER*3, 2, 1, eb3);
	beep_chord(SEMIQUAVER, 2, 1, f3);
	beep_chord(QUAVER, 2, 1, gb3);
	beep_chord(SEMIQUAVER, 2, 1, gb4);
	beep_chord(SEMIQUAVER, 2, 1, ab4);
	beep_chord(QUAVER, 2, 1, bb4);
	beep_chord(SEMIQUAVER, 2, 1, gb4);
	beep_chord(SEMIQUAVER, 2, 1, ab4);
	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(QUAVER, 2, 1, eb3);

	beep_chord(SEMIQUAVER*3, 2, 1, db3);
	beep_chord(SEMIQUAVER, 2, 1, eb3);
	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(SEMIQUAVER, 2, 1, f4);
	beep_chord(SEMIQUAVER, 2, 1, gb4);
	beep_chord(QUAVER, 2, 1, ab4);
	beep_chord(SEMIQUAVER, 2, 1, f4);
	beep_chord(SEMIQUAVER, 2, 1, gb4);
	beep_chord(QUAVER, 2, 1, eb3);
	beep_chord(QUAVER, 2, 1, db3);

	beep_chord(SEMIQUAVER*3, 2, 1, c3);
	beep_chord(SEMIQUAVER, 2, 1, d3);
	beep_chord(QUAVER, 2, 1, e3);
	beep_chord(SEMIQUAVER, 2, 1, e4);
	beep_chord(SEMIQUAVER, 2, 1, f4);
	beep_chord(QUAVER, 2, 1, g4);
	beep_chord(SEMIQUAVER, 2, 1, g4);
	beep_chord(SEMIQUAVER, 2, 1, a4);
	beep_chord(CROTCHET, 2, 1, g3);

	beep_chord(QUAVER, 2, 1, f3);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(SEMIQUAVER, 2, 1, bb2);
	beep_chord(QUAVER, 2, 1, bb2);
	beep(CROTCHET, r);

	beep(QUAVER, r);
	beep_chord(SEMIQUAVER, 2, 1, a2);
	beep_chord(SEMIQUAVER, 2, 1, a2);
	beep_chord(QUAVER, 2, 1, a2);
	beep_chord(SEMIQUAVER, 2, 1, a2);
	beep_chord(SEMIQUAVER, 2, 1, a2);
	beep_chord(QUAVER, 2, 1, a2);
	beep(CROTCHET, r);


	geep_close();
	exit(EXIT_SUCCESS);
}
