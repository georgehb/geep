#define BPM 105

#include "notes.h"
#include "../geep.h"
#include <linux/kd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define GRACE (QUAVER / 8)

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

loop:

    beep(SEMIQUAVER, 2, c4, c5);
    beep(SEMIQUAVER, 2, db4, db5);

    //bar 1
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3,      bb3,      eb4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c2,  c3,      bb3,      eb4, eb5);
    rest(QUAVER);
    beep(CROTCHET,                5, db2, db3,       c4,      ab3, ab4);
    beep(QUAVER,                  5, db2, db3,      ab3,       c4,  c5);
    beep(QUAVER,                  5, db2, db3,      bb3,      bb3, bb4);
    beep(QUAVER,                  5, db2, db3,      eb4,      ab3, ab4);

    //bar 2
    beep(SEMIQUAVER, 7,    eb2, eb3,     bb3,     g3,  g4,     ab5, ab4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,     g3,  g4);
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    ab3, ab4,     eb5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     e2,  e3,     bb3,    bb3, bb4,     ab5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    bb3, bb4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     eb5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                           bb4);
    beep(SEMIQUAVER, 2,     f2,  f3);
    beep(SEMIQUAVER, 5,     f2,  f3,              c4,  c5,     ab4);
    beep(SEMIQUAVER, 4,     f2,  f3,             db4, db5);

    //bar 3
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3, bb3, eb4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c2,  c3, bb3, eb4, eb5);
    rest(QUAVER);
    beep(CROTCHET,                5, db2, db3,  c4, ab3, ab4);
    beep(QUAVER,                  5, db2, db3, ab3,  c4,  c5);
    beep(QUAVER,                  5, db2, db3, bb3, bb3, bb4);
    beep(QUAVER,                  5, db2, db3, eb4, ab3, ab4);

    //bar 4
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    bb3, bb4,     ab5);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,    bb3, bb4);
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    bb3, bb4,     eb5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    eb4, eb5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,                  ab5);
    beep(SEMIQUAVER, 3,     e2,  e3,     bb3);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     c4,  c5,     ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     c4,  c5,     eb5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,     c4,  c5);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     c4,  c5,     ab5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,     c4,  c5);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     c4,  c5,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                           db5);
    beep(SEMIQUAVER, 2,     f2,  f3);
    beep(SEMIQUAVER, 4,    ab1, ab2,              c4,  c5);
    beep(SEMIQUAVER, 4,    bb1, bb2,             db4, db5);

    //bar 5
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3, bb3, eb4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c2,  c3, bb3, eb4, eb5);
    rest(QUAVER);
    beep(CROTCHET,                5, db2, db3,  c4, ab3, ab4);
    beep(QUAVER,                  5, db2, db3, ab3,  c4,  c5);
    beep(QUAVER,                  5, db2, db3, bb3, bb3, bb4);
    beep(QUAVER,                  5, db2, db3, eb4, ab3, ab4);

    //bar 6
    beep(SEMIQUAVER, 7,    eb2, eb3,     bb3,     g3,  g4,     ab5, ab4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,     g3,  g4);
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    ab3, ab4,     eb5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     e2,  e3,     bb3,    bb3, bb4,     ab5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    bb3, bb4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     eb5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                           bb4);
    beep(SEMIQUAVER, 2,     f2,  f3);
    beep(SEMIQUAVER, 5,     f2,  f3,              c4,  c5,     ab4);
    beep(SEMIQUAVER, 4,     f2,  f3,             db4, db5);

    //bar 7
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3, bb3, eb4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c2,  c3, bb3, eb4, eb5);
    rest(QUAVER);
    beep(CROTCHET,                5, db2, db3,  c4, ab4, ab5);
    beep(QUAVER,                  5, db2, db3, ab3, db4, db5);
    beep(QUAVER,                  5, db2, db3, bb3,  c4,  c5);
    beep(QUAVER,                  5, db2, db3, eb4, ab3, ab4);

    //bar 8
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    eb3, eb4,     ab5);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,    eb3, eb4);
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    ab3, ab4,     eb5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    ab3, ab4);
    beep(SEMIQUAVER, 6,     e2,  e3,     bb3,     g3,  g4,     ab5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,     g3,  g4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,    ab3, ab4,     eb5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,    ab3, ab4);
    beep(SEMIQUAVER, 6,    eb2, eb3,     eb3,    ab3, ab4,     ab5);
    beep(SEMIQUAVER, 5,    ab2, ab3,     ab3,    ab3, ab4);
    beep(SEMIQUAVER, 6,    bb2, bb3,     bb3,    ab3, ab4,     ab4);
    beep(SEMIQUAVER, 3,    eb3, eb4,                           db5);
    beep(SEMIQUAVER, 2,    eb3, eb4                               );
    beep(SEMIQUAVER, 5,    ab2, ab3,     ab4,     c4,  c5);
    beep(SEMIQUAVER, 5,    ab2, ab3,      c5,    db4, db5);

    //bar 9
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3,      bb3,       g4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c3,  c4,      bb3,       g4, eb5);
    beep(SEMIQUAVER,              2,  c2,  c3);
    rest(SEMIQUAVER);
    beep(CROTCHET,                5, db2, db3,       c4,       f4, ab4);
    beep(GRACE,                   3, db2, db3,                     bb4);
    beep(QUAVER-GRACE,            5, db2, db3,      ab3,       f4,  c5);
    beep(QUAVER,                  5, db2, db3,      bb3,       f4, bb4);
    beep(QUAVER,                  5, ab2, ab3,      eb4,       f4, ab4);

    //bar 10
    beep(SEMIQUAVER, 7,    eb2, eb3,     bb3,    eb4,  g4,     ab5, ab4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,    eb4,  g4);
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,    eb4, ab4,     eb5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,    eb4, ab4);
    beep(SEMIQUAVER, 6,     e2,  e3,     bb3,     g4, bb4,     ab5);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,     g4, bb4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     f4, ab4,     ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     f4, ab4,     eb5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,     f4, ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     f4, ab4,     ab5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,     f4, ab4);
    beep(SEMIQUAVER, 6,     f2,  f3,     ab3,     f4, ab4,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                           bb4);
    beep(SEMIQUAVER, 2,     f2,  f3);
    beep(SEMIQUAVER, 4,     f2,  f3,                   c5,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                  db5);

    //bar 11
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3,      bb3,       g4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c3,  c4,      bb3,       g4, eb5);
    beep(SEMIQUAVER,              2,  c2,  c3);
    rest(SEMIQUAVER);
    beep(CROTCHET,                5, db2, db3,       c4,       f4, ab4);
    beep(GRACE,                   3, db2, db3,                     bb4);
    beep(QUAVER-GRACE,            4, db2, db3,      ab3,            c5);
    beep(QUAVER,                  4, db2, db3,      bb3,           bb4);
    beep(SEMIQUAVER,              4, ab2, ab3,      eb4,           ab4);
    beep(SEMIQUAVER,              4, db2, db3,      eb4,           ab4);

    //bar 12
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,         bb4,     ab5);
    beep(SEMIQUAVER, 4,    eb2, eb3,     bb3,         bb4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,         bb4,     eb5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,         eb5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,                  ab5);
    beep(SEMIQUAVER, 3,     e2,  e3,     bb3);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,          c5,     ab4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,          c5,     eb5);
    beep(SEMIQUAVER, 4,     f2,  f3,     ab3,          c5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,          c5,     ab5);
    beep(SEMIQUAVER, 4,     f2,  f3,     ab3,          c5);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,          c5,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                           db5);
    beep(SEMIQUAVER, 2,     f2,  f3);
    beep(SEMIQUAVER, 3,    ab1, ab2,                   c5);
    beep(SEMIQUAVER, 3,    bb1, bb2,                  db5);

    //bar 13
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3,      bb3,       g4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c3,  c4,      bb3,       g4, eb5);
    beep(SEMIQUAVER,              2,  c2,  c3);
    rest(SEMIQUAVER);
    beep(CROTCHET,                5, db2, db3,       c4,       f4, ab4);
    beep(GRACE,                   3, db2, db3,                     bb4);
    beep(QUAVER-GRACE,            4, db2, db3,      ab3,            c5);
    beep(QUAVER,                  4, db2, db3,      bb3,           bb4);
    beep(SEMIQUAVER,              4, ab2, ab3,      eb4,           ab4);
    beep(SEMIQUAVER,              4, db2, db3,      eb4,           ab4);

    //bar 14
    beep(SEMIQUAVER, 6,    eb2, eb3,     bb3,          g4,     ab5, ab4);
    beep(SEMIQUAVER, 4,    eb2, eb3,     bb3,          g4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,         ab4,     eb5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,         ab4);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,         bb4,     ab5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,         bb4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,         ab4,     ab4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,         ab4,     eb5);
    beep(SEMIQUAVER, 4,     f2,  f3,     ab3,         ab4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,         ab4,     ab5);
    beep(SEMIQUAVER, 4,     f2,  f3,     ab3,         ab4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,         ab4,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                           bb4);
    beep(SEMIQUAVER, 2,     f2,  f3);
    beep(SEMIQUAVER, 4,     f2,  f3,                   c5,     ab4);
    beep(SEMIQUAVER, 3,     f2,  f3,                  db5);

    //bar 15
    beep(SEMIQUAVER*3-SEPARATION, 5,  c2,  c3,       c4,       g4, eb5);
    rest(SEPARATION);
    beep(SEMIQUAVER,              5,  c3,  c4,       c4,       g4, eb5);
    beep(SEMIQUAVER,              4,  c2,  c3,                 g4, eb5);
    rest(SEMIQUAVER);
    beep(GRACE,                   4, db2, db3,      db4,            g5);
    beep(CROTCHET-GRACE,          5, db2, db3,      db4,      db5, ab5);
    beep(GRACE,                   3, db2, db3,                      c5);
    beep(QUAVER-GRACE,            4, db2, db3,      ab3,           db5);
    beep(QUAVER,                  4, db2, db3,      ab3,            c5);
    beep(SEMIQUAVER,              4, ab2, ab3,      ab3,           ab4);
    beep(SEMIQUAVER,              4, db2, db3,      ab3,           ab4);

    //bar 16
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,         eb4,     ab5);
    beep(SEMIQUAVER, 4,    eb2, eb3,     bb3,         eb4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     bb3,         ab4,     eb5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,         ab4);
    beep(SEMIQUAVER, 5,     e2,  e3,     bb3,          g4,     ab5);
    beep(SEMIQUAVER, 4,     e2,  e3,     bb3,          g4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,         ab4,     ab4);
    beep(SEMIQUAVER, 5,     f2,  f3,     ab3,         ab4,     eb5);
    beep(SEMIQUAVER, 4,     f2,  f3,     ab3,         ab4);
    beep(SEMIQUAVER, 5,    eb2, eb3,     ab3,         ab4,     ab5);
    beep(SEMIQUAVER, 4,    ab2, ab3,     ab3,         ab4);
    beep(SEMIQUAVER, 5,    bb2, bb3,     ab3,         ab4,     ab4);
    beep(SEMIQUAVER, 4,    eb3, eb4,                  ab4,     db5);
    beep(SEMIQUAVER, 3,    eb3, eb4,                  ab4         );
    beep(SEMIQUAVER, 3,    eb2, eb3,                            c5);
    beep(SEMIQUAVER, 2,    eb2, eb3                               );

    //bar 17
    beep(QUAVER,                  5,  c2,  c3,       c4,    eb5,    ab4);
    beep(SEMIQUAVER-SEPARATION,   5,  c2,  c3,       c4,    eb5,    bb4);
    beep(SEPARATION,              2,                 c4,            bb4);
    beep(SEMIQUAVER,              4,  c2,  c3,       c4,    eb5        );
    beep(SEMIQUAVER,              3,                 c4,    eb5,    bb4);
    beep(SEMIQUAVER,              1,                                ab4);
    beep(SEMIQUAVER,              4,  f2,  f3,       c4,    eb5        );
    beep(QUAVER-SEPARATION,       5,  f2,  f3,       c4,    eb5,    bb4);
    beep(SEPARATION,              4,  f2,  f3,       c4,    eb5        );
    beep(SEMIQUAVER,              5,  f2,  f3,       c4,    eb5,    bb4);
    beep(SEMIQUAVER,              5,  f2,  f3,       c4,    db5,    bb4);
    beep(SEMIQUAVER,              5,  f2,  f3,       c4,    db5,    ab4);
    beep(QUAVER-SEPARATION,       5,  f2,  f3,       c4,     c5,    bb4);
    beep(SEPARATION,              2,                         c5,    bb4);
    beep(SEMIQUAVER,              5,  f2,  f3,       c4,    bb4,    ab4);
    beep(SEMIQUAVER,              5,  f2,  f3,       c4,    ab4,    ab4);

    //bar 18
    beep(3*SEMIQUAVER-SEPARATION, 4,    eb2, eb3,     bb3,         bb4         );
    beep(SEPARATION,              1,                               bb4         );
    beep(3*SEMIQUAVER,            4,    eb2, eb3,     bb3,          c5         );
    beep(GRACE     ,              5,    ab2, ab3,     ab3,         ab4,      c6);
    beep(QUAVER-GRACE,            5,    ab2, ab3,     ab3,         ab4,     db6);
    beep(QUAVER,                  5,    ab2, ab3,     ab3,         bb4,      c6);
    beep(QUAVER,                  5,    eb2, eb3,     eb4,         bb4,     ab5);
    beep(CROTCHET,                5,    bb1, bb2,     ab3,          c5,     eb5);

    //bar 19
    beep(QUAVER,                  5,  c2,  c3,       c4,    eb5,    ab4);
    beep(SEMIQUAVER-SEPARATION,   5,  c2,  c3,       c4,    eb5,    bb4);
    beep(SEPARATION,              2,                 c4,            bb4);
    beep(SEMIQUAVER,              4,  c2,  c3,       c4,    eb5        );
    beep(SEMIQUAVER,              3,                 c4,    eb5,    bb4);
    beep(SEMIQUAVER,              1,                                ab4);
    beep(GRACE,                   4, db2, db3,      db4,     g5        );
    beep(SEMIQUAVER-GRACE,        4, db2, db3,      db4,    ab5        );
    beep(QUAVER-SEPARATION,       5, db2, db3,      db4,    ab5,    bb4);
    beep(SEPARATION,              4, db2, db3,      db4,    ab5        );
    beep(SEMIQUAVER,              5, db2, db3,      db4,    ab5,    bb4);
    beep(SEMIQUAVER,              5, db2, db3,      db4,    ab4,    bb4);
    beep(SEMIQUAVER,              5, db2, db3,      db4,    ab4,    ab4);
    beep(QUAVER-SEPARATION,       5, db2, db3,      db4,    ab4,    bb4);
    beep(SEPARATION,              4, db2, db3,      db4,    ab4        );
    beep(GRACE,                   5, eb2, eb3,      ab3,     c5,    bb4);
    beep(QUAVER-GRACE,            5, eb2, eb3,      ab3,    db5,    bb4);

    //bar 20
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    db5        );
    beep(CROTCHET,       4,	     eb2, eb3,      ab3,     c5        );
    beep(GRACE,          4,	     eb2, eb3,      ab3,    ab4,     g5);
    beep(QUAVER-GRACE,   4,	     eb2, eb3,      ab3,    ab4,    ab5);
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    ab4,     g5);
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    bb4,    eb5);
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    bb4,    bb4);
    beep(SEMIQUAVER,     4,	     eb2, eb3,      ab3,     c5,    bb4);
    beep(SEMIQUAVER,     4,	     eb2, eb3,      ab3,    db5,    bb4);

    //bar 21
    beep(QUAVER,                  5,     c2,  c3,      c4,         eb5,     ab4);
    beep(SEMIQUAVER-SEPARATION,   5,     c2,  c3,      c4,         eb5,     bb4);
    beep(SEPARATION,              2,                   c4,                  bb4);
    beep(SEMIQUAVER,              4,     c2,  c3,      c4,         eb5         );
    beep(SEMIQUAVER,              3,                   c4,         eb5,     bb4);
    beep(SEMIQUAVER,              1,                                        ab4);
    beep(SEMIQUAVER,              4,     f2,  f3,      c4,         eb5         );
    beep(QUAVER-SEPARATION,       5,     f2,  f3,      c4,         eb5,     bb4);
    beep(SEPARATION,              2,                   c4,         eb5         );
    beep(SEMIQUAVER,              5,     f2,  f3,      c4,         eb5,     bb4);
    beep(SEMIQUAVER,              3,                   c4,         db5,     bb4);
    beep(SEMIQUAVER,              5,     f2,  f3,      c4,         db5,     ab4);
    beep(QUAVER-SEPARATION,       5,     f2,  f3,      c4,          c5,     bb4);
    beep(SEPARATION,              3,     f2,  f3,                   c5         );
    beep(SEMIQUAVER,              5,     f2,  f3,      c4,         bb4,     ab4);
    beep(SEMIQUAVER,              5,     f2,  f3,      c4,         ab4,     ab4);

    //bar 22
    beep(3*SEMIQUAVER-SEPARATION, 4,    eb2, eb3,     bb3,         bb4         );
    beep(SEPARATION,              1,                               bb4         );
    beep(SEMIQUAVER,              4,    eb2, eb3,     bb3,          c5         );
    beep(QUAVER,                  2,                  bb3,          c5         );
    beep(GRACE     ,              5,    eb2, eb3,     ab3,         ab4,      c6);
    beep(QUAVER-GRACE,            5,    eb2, eb3,     ab3,         ab4,     db6);
    beep(QUAVER,                  5,    ab2, ab3,     ab3,         bb4,      c6);
    beep(QUAVER-SEPARATION,       5,    ab2, ab3,     eb4,         bb4,     ab5);
    beep(SEPARATION,              3,                  eb4,         bb4,     ab5);
    beep(QUAVER,                  5,    ab1, ab2,     ab3,          c5,     eb5);
    beep(QUAVER,                  5,    bb1, bb2,     ab3,          c5,     eb5);

    //bar 23
    beep(QUAVER,                  5,  c2,  c3,       c4,    eb5,    ab4);
    beep(SEMIQUAVER-SEPARATION,   5,  c2,  c3,       c4,    eb5,    bb4);
    beep(SEPARATION,              2,                 c4,            bb4);
    beep(SEMIQUAVER,              4,  c2,  c3,       c4,    eb5        );
    beep(SEMIQUAVER,              3,                 c4,    eb5,    bb4);
    beep(SEMIQUAVER,              1,                                ab4);
    beep(GRACE,                   4, db2, db3,      db4,     g5        );
    beep(SEMIQUAVER-GRACE,        4, db2, db3,      db4,    ab5        );
    beep(QUAVER-SEPARATION,       5, db2, db3,      db4,    ab5,    bb4);
    beep(SEPARATION,              4, db2, db3,      db4,    ab5        );
    beep(SEMIQUAVER,              5, db2, db3,      db4,    ab5,    bb4);
    beep(SEPARATION,              2,                db4,            bb4);
    beep(SEMIQUAVER,              5, db2, db3,      db4,    ab4,    bb4);
    beep(SEMIQUAVER,              5, db2, db3,      db4,    ab4,    ab4);
    beep(QUAVER-SEPARATION,       5, db2, db3,      db4,    ab4,    bb4);
    beep(SEPARATION,              4, db2, db3,      db4,            bb4);
    beep(QUAVER,                  5, eb2, eb3,      ab3,    db5,    ab4);

    //bar 24
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    db5        );
    beep(CROTCHET,       4,	     eb2, eb3,      ab3,     c5        );
    beep(GRACE,          4,	     eb2, eb3,      ab3,    ab4,     g5);
    beep(QUAVER-GRACE,   4,	     eb2, eb3,      ab3,    ab4,    ab5);
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    ab4,     g5);
    beep(QUAVER,         4,	     eb2, eb3,      ab3,    bb4,    eb5);
    beep(QUAVER,         4,	      f2,  f3,      ab3,    bb4,    bb4);
    beep(SEMIQUAVER,     4,	      f2,  f3,      ab3,    ab4,     c5);
    beep(SEMIQUAVER,     4,	      f2,  f3,      ab3,    bb4,    db5);

    //key change
    //bar 25
    beep(SEMIQUAVER,            9, gb2, gb3,  gb4,bb4,db5,   ab4, eb4,  eb5,ab5);
    beep(SEMIQUAVER,            7, gb2, gb3,  gb4,bb4,db5,   ab4, eb4        );
    beep(SEMIQUAVER-SEPARATION, 7, gb2, gb3,  gb4,bb4,db5,   ab4,       ab5  );
    beep(SEPARATION,            2,                           ab4,       ab5  );
    beep(SEMIQUAVER,            6, gb2, gb3,  gb4,bb4,db5,   ab4             );
    beep(SEMIQUAVER,            3,                           ab4, eb5,  eb6  );
    beep(SEMIQUAVER,            2,                           ab4, eb5        );
    beep(SEMIQUAVER,            8, gb2, gb3,  gb4,bb4,db5,   ab4, eb4,  eb5  );
    beep(SEMIQUAVER,            7, gb2, gb3,  gb4,bb4,db5,   ab4,       ab5  );
    beep(SEMIQUAVER-SEPARATION, 6, gb2, gb3,  gb4,bb4,db5,   ab4             );
    beep(SEPARATION,            4,            gb4,bb4,db5,   ab4             );
    beep(SEMIQUAVER-SEPARATION, 8, gb3, gb4,  gb4,bb4,db5,   ab4, eb5,  eb6  );
    beep(SEPARATION,            6,            gb4,bb4,db5,   ab4, eb5,  eb6  );
    beep(SEMIQUAVER,            7, gb2, gb3,  gb4,bb4,db5,   ab4, eb5        );
    beep(SEMIQUAVER,            8, gb2, gb3,  gb4,bb4,db5,   ab4, eb4,  eb5  );
    beep(SEMIQUAVER,            7, db3, db4,  gb4,bb4,db5,   ab4,       ab5  );
    beep(SEMIQUAVER,            6, db3, db4,  gb4,bb4,db5,   ab4             );
    beep(SEMIQUAVER,            8, gb3, gb4,  gb4,bb4,db5,   ab4, eb5,  eb6  );
    beep(SEMIQUAVER,            7, gb3, gb4,  gb4,bb4,db5,   ab4, eb5        ); 

    //bar 26
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         eb4,  eb5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         eb4        );
    beep(SEMIQUAVER-SEPARATION, 7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEPARATION,            2,                                  ab4,  ab5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         ab4        );
    beep(SEMIQUAVER,            2,                                  eb4,  eb5  );
    beep(SEMIQUAVER-SEPARATION, 1,                                  eb4        );
    rest(SEPARATION);                                  
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         eb4,  eb5  );
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 6,  f2,  f3,    f4,ab4, c5,         ab4        );
    beep(SEPARATION,            5,  f2,  f3,    f4,ab4, c5                     );
    beep(SEMIQUAVER-SEPARATION, 7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEPARATION,            5,              f4,ab4, c5,         ab4,  ab5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         ab4        );
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         db5,  db6  );
    beep(SEMIQUAVER,            6,  f3,  f4,    f4,ab4, c5,                c6  );
    beep(SEMIQUAVER,            5,  f3,  f4,    f4,ab4, c5                     );
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         ab4        ); 

    //bar 27
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            6, gb2, gb3,   gb4,bb4,db5,         eb4        );
    beep(SEMIQUAVER-SEPARATION, 7, gb2, gb3,   gb4,bb4,db5,         ab4,  ab5  );
    beep(SEPARATION,            2,                                  ab4,  ab5  );
    beep(SEMIQUAVER,            6, gb2, gb3,   gb4,bb4,db5,         ab4        );
    beep(SEMIQUAVER,            2,                                  eb5,  eb6  );
    beep(SEMIQUAVER,            1,                                  eb5        );
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 6, gb2, gb3,   gb4,bb4,db5,         ab4        );
    beep(SEPARATION,            4,             gb4,bb4,db5,         ab4        );
    beep(SEMIQUAVER-SEPARATION, 7, gb3, gb4,   gb4,bb4,db5,         eb5,  eb6  );
    beep(SEPARATION,            5,             gb4,bb4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            6, gb2, gb3,   gb4,bb4,db5,         eb5        );
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            7, db3, db4,   gb4,bb4,db5,         ab4,  ab5  );
    beep(SEMIQUAVER,            6, db3, db4,   gb4,bb4,db5,         ab4        );
    beep(SEMIQUAVER,            7, gb3, gb4,   gb4,bb4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            6, gb3, gb4,   gb4,bb4,db5,         eb5        ); 

    //bar 28
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         eb4,  eb5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         eb4        );
    beep(SEMIQUAVER-SEPARATION, 7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEPARATION,            2,                                  ab4,  ab5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         ab4        );
    beep(SEMIQUAVER,            2,                                  eb5,  eb6  );
    beep(SEMIQUAVER,            1,                                  eb5        );
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         eb4,  eb5  );
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 6,  f2,  f3,    f4,ab4, c5,         ab4        );
    beep(SEPARATION,            5,  f2,  f3,    f4,ab4, c5                     );
    beep(SEMIQUAVER-SEPARATION, 7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEPARATION,            5,              f4,ab4, c5,         ab4,  ab5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         ab4        );
    beep(SEMIQUAVER-SEPARATION, 7,  f2,  f3,    f4,ab4, c5,         bb4,  bb5  );
    beep(SEPARATION,            5,  f2,  f3,    f4,ab4, c5                     );
    beep(SEMIQUAVER,            7,  f3,  f4,    f4,ab4, c5,         bb4,  bb5  );
    beep(SEMIQUAVER,            6,  f3,  f4,    f4,ab4, c5,         bb4        );
    beep(SEMIQUAVER,            7,  f2,  f3,    f4,ab4, c5,         ab4,  ab5  );
    beep(SEMIQUAVER,            6,  f2,  f3,    f4,ab4, c5,         ab4        ); 

    //bar 29
    beep(SEMIQUAVER,            7,  e2,  e3,   gb4, b4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            6,  e2,  e3,   gb4, b4,db5,         eb4        );
    beep(SEMIQUAVER-SEPARATION, 7,  e2,  e3,   gb4, b4,db5,         ab4,  ab5  );
    beep(SEPARATION,            2,                                  ab4,  ab5  );
    beep(SEMIQUAVER,            6,  e2,  e3,   gb4, b4,db5,         ab4        );
    beep(SEMIQUAVER,            2,                                  eb5,  eb6  );
    beep(SEMIQUAVER,            1,                                  eb5        );
    beep(SEMIQUAVER,            7,  e2,  e3,   gb4, b4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            7,  e2,  e3,   gb4, b4,db5,         ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 6,  e2,  e3,   gb4, b4,db5,         ab4        );
    beep(SEPARATION,            6,  e2,  e3,   gb4, b4,db5,         ab4        );
    beep(SEMIQUAVER-SEPARATION, 7,  e2,  e3,   gb4, b4,db5,         eb5,  eb6  );
    beep(SEPARATION,            7,  e2,  e3,   gb4, b4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            6,  b2,  b3,   gb4, b4,db5,         eb5        );
    beep(SEMIQUAVER,            7,  b2,  b3,   gb4, b4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            7,  e3,  e4,   gb4, b4,db5,         ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 6,  e3,  e4,   gb4, b4,db5,         ab4        );
    beep(SEPARATION,            4,             gb4, b4,db5,         ab4        );
    beep(SEMIQUAVER,            7,  e2,  e3,   gb4, b4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            6,  e2,  e3,   gb4, b4,db5,         eb5        ); 

    //bar 30
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb4,  eb5  );
    beep(SEMIQUAVER,            6, gb2, gb3,   gb4,bb4,db5,         eb4        );
    beep(SEMIQUAVER,            2,                                  ab4,  ab5  );
    beep(SEMIQUAVER,            1,                                  ab4        );
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            6, gb2, gb3,   gb4,bb4,db5,         eb5        );
    beep(SEMIQUAVER,            1,                                  eb5        );
    beep(SEMIQUAVER,            1,                                  eb5        );
    rest(QUAVER);
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER-SEPARATION, 5, gb2, gb3,   gb4,bb4,db5                     );
    rest(SEPARATION);
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            7, gb2, gb3,   gb4,bb4,db5,         eb5,  eb6  );
    beep(SEMIQUAVER,            2,                                  eb5,  eb6  );
    beep(SEMIQUAVER,            2,                                  eb5,  eb6  ); 

    //bar 31
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 5, gb2, gb3,    bb4, db5,        ab4        );
    beep(SEPARATION,            4, gb2, gb3,    bb4, db5                    );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            5, gb2, gb3,    bb4, db5,        ab4        );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            5, gb2, gb3,    bb4, db5,        ab4        );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER-SEPARATION, 5, gb2, gb3,    bb4, db5,        bb4        );
    beep(SEPARATION,            4, gb2, gb3,    bb4, db5                    );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            5, gb2, gb3,    bb4, db5,        bb4        );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            6, gb2, gb3,    bb4, db5,        ab4,  ab5  ); 

    //bar 32
    beep(SEMIQUAVER,            4,              bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER-SEPARATION, 4,              bb4, db5,        ab4,  ab5  );
    beep(SEPARATION,            2,              bb4, db5                    );
    beep(SEMIQUAVER,            4,              bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            3,              bb4, db5,        ab4        );
    beep(SEMIQUAVER,            4,              bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            4,              bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            3,              bb4, db5,        ab4        );
    beep(SEMIQUAVER,            4,              bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER-SEPARATION, 3,              bb4, db5,        bb4        );
    beep(SEPARATION,            2,              bb4, db5                    );
    beep(SEMIQUAVER,            4,              bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            4,              bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            4,              bb4, db5,        ab4,  ab5  );
    beep(SEMIQUAVER,            4,              bb4, db5,        bb4,  bb5  );
    beep(SEMIQUAVER,            3,              bb4, db5,        bb4        );

    goto loop;
    geep_close();
    exit(EXIT_SUCCESS);
}
