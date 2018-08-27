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
    console_fd = geep_setup(120);
    signal(SIGINT, quit);

    
    // bar 65 (upbeat)
    beep(QUAVER, 2, 1, g3);
    rest(SEPARATION);
    beep(QUAVER, 2, 1, c4);
    rest(SEPARATION);
    beep(QUAVER, 2, 1, d4);
    rest(SEPARATION);

    // bar 66
    beep(QUAVER, 2, c2, eb4);
    beep(SEPARATION, 2, 1, eb4);
    beep(QUAVER, 2, c2, eb4);
    rest(SEPARATION);
    beep(QUAVER, 2, c3, f4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, bb1, d4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, bb3);
    beep(SEPARATION, 2, 1, bb3);
    beep(QUAVER, 2, bb2, bb3);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, ab1, g3);
    rest(SEPARATION);

    // bar 67
    beep(QUAVER, 2, ab1, f3);
    rest(SEPARATION);
    beep(QUAVER, 2, ab2, g3);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, bb1, 1);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, g3);
    rest(SEPARATION);
    beep(QUAVER, 2, bb2, c4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, d4);
    rest(SEPARATION);

    //bar 68
    beep(QUAVER, 2, c2, eb4);
    beep(SEPARATION, 2, 1, eb4);
    beep(QUAVER, 2, c2, eb4);
    rest(SEPARATION);
    beep(QUAVER, 2, c3, f4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, bb1, d4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, bb3);
    beep(SEPARATION, 2, 1, bb3);
    beep(QUAVER, 2, bb2, bb3);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 3, ab1, g4, eb4);


    // bar 69
    rest(SEPARATION);
    beep(QUAVER, 2, ab1, f4);
    rest(SEPARATION);
    beep(QUAVER, 2, ab2, g4);
    beep(SEPARATION, 2, 1, g4);
    beep(QUAVER, 2, bb1, g4);
    beep(SEPARATION, 2, bb1, 1);
    beep(QUAVER, 2, bb1,  1);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb2, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, g4);
    rest(SEPARATION);

    // bar 70
    beep(QUAVER, 4, f2, ab4, eb4, c4);
    beep(SEPARATION, 3, ab4, eb4, c4);
    beep(QUAVER, 4, f2, ab4, eb4, c4);
    rest(SEPARATION);
    beep(QUAVER, 2, f3, eb4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, e2, d4, b3);
    rest(SEPARATION);
    beep(QUAVER, 2, e2, ab4);
    rest(SEPARATION);
    beep(QUAVER, 2, e3, ab4);
    rest(SEPARATION);
    beep(QUAVER, 2, e2, ab4);
    rest(SEPARATION);

    //bar 71

    beep(QUAVER, 4, eb2, g4, d4, bb3);
    beep(SEPARATION, 3,  g4, d4, bb3);
    beep(QUAVER, 4, eb2, g4, d4, bb3);
    rest(SEPARATION);
    beep(QUAVER, 2, eb3, d4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, ab1, c4);
    rest(SEPARATION);
    beep(QUAVER, 2, ab1, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, ab2, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, ab1, g4);
    rest(SEPARATION);

    // bar 72
    beep(QUAVER, 2, d2, f4);
    beep(SEPARATION, 2, 1, f4);
    beep(QUAVER, 2, d2, f4);
    rest(SEPARATION);
    beep(QUAVER, 2, d3, c4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, db2, b3);
    rest(SEPARATION);
    beep(QUAVER, 4, db2, a4, eb4, b3);
    beep(SEPARATION, 3, a4, eb4, b3);
    beep(QUAVER, 4, db3, a4, eb4, b3);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 5, g1, g2, g4, d4, c4);


    // bar 73
    rest(SEPARATION);
    beep(QUAVER, 5, g1, g2, c4, d4, f4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 5, g1, g2, b3, d4, g4);
    rest(SEPARATION);
    rest(QUAVER);
    rest(SEPARATION);
    beep(QUAVER, 2, 1, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, 1, c5);
    rest(SEPARATION);
    beep(QUAVER, 2, 1, d5);
    rest(SEPARATION);

    // bar 74
    beep(QUAVER, 3, c2, eb5, c5);
    beep(SEPARATION, 2, eb5, c5);
    beep(QUAVER, 3, c2, eb5, c5);
    rest(SEPARATION);
    beep(QUAVER, 2, c3, f5);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, bb1, d5);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, bb4);
    beep(SEPARATION, 2, 1, bb4);
    beep(QUAVER, 2, bb2, bb4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 4, ab1, g4, eb4, c4);
    rest(SEPARATION);

    // bar 75
    beep(QUAVER, 2, ab1, f4);
    rest(SEPARATION);
    beep(QUAVER, 2, ab2, g4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, bb1, d4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb2, c5);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, d5);
    rest(SEPARATION);

    //bar 76
    beep(QUAVER, 4, c2, eb5, c5, g4);
    beep(SEPARATION, 3, eb5, c5, g4);
    beep(QUAVER, 4, c2, eb5, c5, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, c3, f5);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 2, bb1, d5);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, bb4);
    beep(SEPARATION, 2, 1, bb4);
    beep(QUAVER, 2, bb2, bb4);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 5, ab1, g5, eb5, c5, g4);

    // bar 77
    rest(SEPARATION);
    beep(QUAVER, 2, ab1, f5);
    rest(SEPARATION);
    beep(QUAVER, 2, ab2, g5);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 3, bb1, d5, bb4);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, g5);
    rest(SEPARATION);
    beep(QUAVER, 2, bb2, g5);
    rest(SEPARATION);
    beep(QUAVER, 2, bb1, g5);
    rest(SEPARATION);

    // bar 78
    beep(CROTCHET+SEPARATION, 5, f2, ab5, eb5, c5, ab4);
    rest(SEPARATION);
    beep(QUAVER, 2, f3, eb5);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 4, e2, d5, b4, ab4);
    rest(SEPARATION);
    beep(QUAVER, 2, e2, ab5);
    rest(SEPARATION);
    beep(QUAVER, 2, e3, ab5);
    rest(SEPARATION);
    beep(QUAVER, 2, e2, ab5);
    rest(SEPARATION);

    //bar 79

    beep(QUAVER, 5, eb2, g5, d5, bb4, g4);
    beep(SEPARATION, 3,  g5, d5, bb4, g4);
    beep(QUAVER, 5, eb2, g5, d5, bb4, g4);
    rest(SEPARATION);
    beep(QUAVER, 2, eb3, d5);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 3, ab1, c5, g4);
    rest(SEPARATION);
    beep(QUAVER, 4, ab1, g5, c5, g4);
    rest(SEPARATION);
    beep(QUAVER, 4, ab2, g5, c5, g4);
    beep(SEPARATION, 3, g5, c5, g4);
    beep(QUAVER, 4, ab1, g5, c5, g4);
    rest(SEPARATION);

    // bar 80
    beep(CROTCHET+SEPARATION,5, d2, d3, ab4, c5, f5);
    rest(SEPARATION);
    beep(QUAVER, 4, d2, d3, c5, eb5);
    rest(SEPARATION);
    beep(CROTCHET+SEPARATION, 4, g1, g2, b4, d5);
    rest(SEPARATION);
    beep(QUAVER, 2, eb5, b4);
    rest(SEPARATION);
    beep(QUAVER, 2, g1, g2);
    rest(SEPARATION);
    rest(QUAVER);

    // bar 81
    beep(QUAVER*3+SEPARATION*2, 6, ab1, ab2, g3, c4, eb4, g4);
    rest(SEPARATION);
    beep(QUAVER*3+SEPARATION*2, 6, g1, g2, bb2, f3, bb3, d4);
    rest(SEPARATION);
    beep(QUAVER*3+SEPARATION*2, 6, ab1, ab2, g3, c4, eb4, g4);
    rest(SEPARATION);
    beep(QUAVER*3+SEPARATION*2, 6, g1, g2, bb2, f3, bb3, d4);
    rest(SEPARATION);
    beep(QUAVER*3+SEPARATION*2, 6, ab1, ab2, g3, c4, eb4, g4);
    rest(SEPARATION);
    beep(QUAVER, 1, bb5);
    rest(SEPARATION);
    beep(QUAVER, 1, c6);
    rest(CROTCHET);
    beep(CROTCHET*3, 4, eb1, eb2, g3, c4, eb4, g4);







    geep_close();
    exit(EXIT_SUCCESS);
}
