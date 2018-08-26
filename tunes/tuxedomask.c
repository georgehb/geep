#define BPM 140
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

int main()
{
    console_fd = geep_setup();
    signal(SIGINT, quit);

    // bar 65 (upbeat)
    beep_chord(QUAVER, 2, 1, g3);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, 1, c4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, 1, d4);
    beep(SEPARATION, r);

    // bar 66
    beep_chord(QUAVER, 2, c2, eb4);
    beep_chord(SEPARATION, 2, 1, eb4);
    beep_chord(QUAVER, 2, c2, eb4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, c3, f4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, bb1, d4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, bb3);
    beep_chord(SEPARATION, 2, 1, bb3);
    beep_chord(QUAVER, 2, bb2, bb3);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, ab1, g3);
    beep(SEPARATION, r);

    // bar 67
    beep_chord(QUAVER, 2, ab1, f3);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab2, g3);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, bb1, 1);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, g3);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb2, c4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, d4);
    beep(SEPARATION, r);

    //bar 68
    beep_chord(QUAVER, 2, c2, eb4);
    beep_chord(SEPARATION, 2, 1, eb4);
    beep_chord(QUAVER, 2, c2, eb4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, c3, f4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, bb1, d4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, bb3);
    beep_chord(SEPARATION, 2, 1, bb3);
    beep_chord(QUAVER, 2, bb2, bb3);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 3, ab1, g4, eb4);


    // bar 69
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab1, f4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab2, g4);
    beep_chord(SEPARATION, 2, 1, g4);
    beep_chord(QUAVER, 2, bb1, g4);
    beep_chord(SEPARATION, 2, bb1, 1);
    beep_chord(QUAVER, 2, bb1,  1);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb2, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, g4);
    beep(SEPARATION, r);

    // bar 70
    beep_chord(QUAVER, 4, f2, ab4, eb4, c4);
    beep_chord(SEPARATION, 3, ab4, eb4, c4);
    beep_chord(QUAVER, 4, f2, ab4, eb4, c4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, f3, eb4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, e2, d4, b3);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, e2, ab4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, e3, ab4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, e2, ab4);
    beep(SEPARATION, r);

    //bar 71

    beep_chord(QUAVER, 4, eb2, g4, d4, bb3);
    beep_chord(SEPARATION, 3,  g4, d4, bb3);
    beep_chord(QUAVER, 4, eb2, g4, d4, bb3);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, eb3, d4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, ab1, c4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab1, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab2, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab1, g4);
    beep(SEPARATION, r);

    // bar 72
    beep_chord(QUAVER, 2, d2, f4);
    beep_chord(SEPARATION, 2, 1, f4);
    beep_chord(QUAVER, 2, d2, f4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, d3, c4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, db2, b3);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 4, db2, a4, eb4, b3);
    beep_chord(SEPARATION, 3, a4, eb4, b3);
    beep_chord(QUAVER, 4, db3, a4, eb4, b3);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 5, g1, g2, g4, d4, c4);


    // bar 73
    beep(SEPARATION, r);
    beep_chord(QUAVER, 5, g1, g2, c4, d4, f4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 5, g1, g2, b3, d4, g4);
    beep(SEPARATION, r);
    beep(QUAVER, r);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, 1, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, 1, c5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, 1, d5);
    beep(SEPARATION, r);

    // bar 74
    beep_chord(QUAVER, 3, c2, eb5, c5);
    beep_chord(SEPARATION, 2, eb5, c5);
    beep_chord(QUAVER, 3, c2, eb5, c5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, c3, f5);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, bb1, d5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, bb4);
    beep_chord(SEPARATION, 2, 1, bb4);
    beep_chord(QUAVER, 2, bb2, bb4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 4, ab1, g4, eb4, c4);
    beep(SEPARATION, r);

    // bar 75
    beep_chord(QUAVER, 2, ab1, f4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab2, g4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, bb1, d4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb2, c5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, d5);
    beep(SEPARATION, r);

    //bar 76
    beep_chord(QUAVER, 4, c2, eb5, c5, g4);
    beep_chord(SEPARATION, 3, eb5, c5, g4);
    beep_chord(QUAVER, 4, c2, eb5, c5, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, c3, f5);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 2, bb1, d5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, bb4);
    beep_chord(SEPARATION, 2, 1, bb4);
    beep_chord(QUAVER, 2, bb2, bb4);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 5, ab1, g5, eb5, c5, g4);


    // bar 77
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab1, f5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, ab2, g5);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 3, bb1, d5, bb4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, g5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb2, g5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, bb1, g5);
    beep(SEPARATION, r);

    // bar 78
    beep_chord(CROTCHET+SEPARATION, 5, f2, ab5, eb5, c5, ab4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, f3, eb5);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 4, e2, d5, b4, ab4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, e2, ab5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, e3, ab5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, e2, ab5);
    beep(SEPARATION, r);

    //bar 79

    beep_chord(QUAVER, 5, eb2, g5, d5, bb4, g4);
    beep_chord(SEPARATION, 3,  g5, d5, bb4, g4);
    beep_chord(QUAVER, 5, eb2, g5, d5, bb4, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, eb3, d5);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 3, ab1, c5, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 4, ab1, g5, c5, g4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 4, ab2, g5, c5, g4);
    beep_chord(SEPARATION, 3, g5, c5, g4);
    beep_chord(QUAVER, 4, ab1, g5, c5, g4);
    beep(SEPARATION, r);

    // bar 80
    beep_chord(CROTCHET+SEPARATION,5, d2, d3, ab4, c5, f5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 4, d2, d3, c5, eb5);
    beep(SEPARATION, r);
    beep_chord(CROTCHET+SEPARATION, 4, g1, g2, b4, d5);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, eb5, b4);
    beep(SEPARATION, r);
    beep_chord(QUAVER, 2, g1, g2);
    beep(SEPARATION, r);
    beep(QUAVER+SEPARATION, r);

    // bar 81
    beep_chord(CROTCHET+SEPARATION, 4, c2, c3, g4, c5);
    beep_chord(SEPARATION, 2, g4, c5);
    beep_chord(CROTCHET+SEPARATION, 3, c2, g4, c5);
    beep_chord(SEPARATION, 2, g4, c5);
    beep_chord(CROTCHET+SEPARATION, 3, c2, g4, c5);
    beep_chord(SEPARATION, 2, g4, c5);
    beep_chord(CROTCHET+SEPARATION, 3, c2, g4, c5);
    beep_chord(SEPARATION, 2, g4, c5);

    // bar 82
    beep_chord(CROTCHET*2+SEPARATION*2, 5, c4, e4, g4, bb4, c5);

    geep_close();
    exit(EXIT_SUCCESS);
}
