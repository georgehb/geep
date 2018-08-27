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
    beep(SEPARATION,              1,                 c4                );
    beep(SEMIQUAVER,              4,  c2,  c3,       c4,    eb5        );  
    beep(SEMIQUAVER,              3,                 c4,    eb5,    bb4);
    beep(SEMIQUAVER,              1,                                ab4);
    beep(SEMIQUAVER,              4, db2, db3,       c4,    eb5        );  
    beep(SEMIQUAVER,              5, db2, db3,       c4,    eb5,    bb4);  
    beep(SEMIQUAVER-SEPARATION,   5, db2, db3,       c4,    eb5,    bb4);  
    beep(SEPARATION,              4, db2, db3,       c4,    eb5        );  
    beep(SEMIQUAVER,              5, db2, db3,       c4,    eb5,    bb4);  
    beep(SEMIQUAVER,              5, db2, db3,       c4,    db5,    bb4);  
    beep(SEMIQUAVER,              5, db2, db3,       c4,    db5,    ab4);  
    beep(QUAVER-SEPARATION,       5, db2, db3,       c4,     c5,    bb4);  
    rest(SEPARATION);
    beep(SEMIQUAVER,              5, db2, db3,       c4,    bb4,    ab4);  
    beep(SEMIQUAVER,              5, db2, db3,       c4,    ab4,    ab4);  







    geep_close();
    exit(EXIT_SUCCESS);
}
