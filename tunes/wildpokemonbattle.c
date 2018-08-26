#define BPM 192

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

    //bar1
    beep(SEMIQUAVER, 2, g5,  c5 );
    beep(SEMIQUAVER, 2, gb5, b4 );
    beep(SEMIQUAVER, 2, f5,  bb4);
    beep(SEMIQUAVER, 2, g6,  a4 );
                    
    beep(SEMIQUAVER, 2, g5,  bb4);
    beep(SEMIQUAVER, 2, gb5, a4 );
    beep(SEMIQUAVER, 2, f5,  ab4);
    beep(SEMIQUAVER, 2, g6,  g4 );
                    
    beep(SEMIQUAVER, 2, g5,  ab4);
    beep(SEMIQUAVER, 2, gb5, g4 );
    beep(SEMIQUAVER, 2, f5,  gb4);
    beep(SEMIQUAVER, 2, g6,  f4 );
                    
    beep(SEMIQUAVER, 2, g5,  gb4);
    beep(SEMIQUAVER, 2, gb5, f4 );
    beep(SEMIQUAVER, 2, f5,  e4 );
    beep(SEMIQUAVER, 2, g6,  eb4);
                    
    //bar2                
    beep(SEMIQUAVER, 2, g5,  e4 );
    beep(SEMIQUAVER, 2, gb5, eb4);
    beep(SEMIQUAVER, 2, f5,  d4 );
    beep(SEMIQUAVER, 2, g6,  db4);
                    
    beep(SEMIQUAVER, 2, g5,  d4 );
    beep(SEMIQUAVER, 2, gb5, db4);
    beep(SEMIQUAVER, 2, f5,  c4 );
    beep(SEMIQUAVER, 2, g6,  b3 );
                    
    beep(SEMIQUAVER, 2, g5,  c4 );
    beep(SEMIQUAVER, 2, gb5, b3 );
    beep(SEMIQUAVER, 2, f5,  bb3);
    beep(SEMIQUAVER, 2, g6,  a3 );
                    
    beep(SEMIQUAVER, 2, g5,  as3);
    beep(SEMIQUAVER, 2, gb5, b3 );
    beep(SEMIQUAVER, 2, f5,  c4 );
    beep(SEMIQUAVER, 2, g6,  cs4);

    //bar 3
    beep(QUAVER, 3, c3, g5, g4);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 1, c3);
    beep(QUAVER, 3, g3, e4, g4);
    beep(QUAVER, 2, c3, g4);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 3, c3, eb4, g4);
    beep(QUAVER, 1, g3);

    //bar 4
    beep(QUAVER, 1, c3);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 1, c3);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 3, c3, db4, g4);
    beep(QUAVER, 2, g3, g4);
    beep(QUAVER, 1, c3);
    beep(QUAVER, 1, g3);

    //bar 5
    beep(QUAVER, 1, db3);
    beep(QUAVER, 1, ab3);
    beep(QUAVER, 1, db3);
    beep(QUAVER, 3, db3, e4, g4);
    beep(QUAVER, 2, ab3, g4);
    beep(QUAVER, 1, bb3);
    beep(QUAVER, 3, ab3, eb4, g4);
    beep(QUAVER, 1, g3);

    //bar 6
    beep(QUAVER, 1, db3);
    beep(QUAVER, 1, ab3);
    beep(QUAVER, 1, db3);
    beep(QUAVER, 3, db3, cs4, fs4);
    beep(QUAVER, 3, ab3, cs4, fs4);
    beep(QUAVER, 3, bb3 , cs4, fs4);
    beep(QUAVER, 3, ab3, cs4, fs4);
    beep(QUAVER, 3, g3, cs4, fs4);

    //bar 7
    beep(QUAVER, 2, c3, g4);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 1, c3);
    beep(QUAVER, 3, g3, e4, g4);
    beep(QUAVER, 2, c3, g4);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 3, c3, eb4, g4);
    beep(QUAVER, 1, g3);

    //bar 8
    beep(QUAVER, 1, c3);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 1, c3);
    beep(QUAVER, 1, g3);
    beep(QUAVER, 3, c3, db4, g4);
    beep(QUAVER, 2, g3, g4);
    beep(QUAVER, 1, c3);
    beep(QUAVER, 1, g3);

    //bar 9
    beep(QUAVER, 1, db3);
    beep(QUAVER, 1, ab3);
    beep(QUAVER, 1, db3);
    beep(QUAVER, 3, db3, e4, g4);
    beep(QUAVER, 2, ab3, g4);
    beep(QUAVER, 1, bb3);
    beep(QUAVER, 3, ab3, eb4, g4);
    beep(QUAVER, 1, g3);

    //bar 10
    beep(QUAVER, 1, db3);
    beep(QUAVER, 1, ab3);
    beep(QUAVER, 1, db3);
    beep(QUAVER, 3, db3, db4, g4);
    beep(QUAVER, 2, ab3,  g4);
    beep(QUAVER, 2, bb3,  g4);
    beep(QUAVER, 1, ab3);
    beep(QUAVER, 1, g3);


    //bar 11
    beep(SEMIQUAVER, 3, c3, db4,  g4);
    beep(SEMIQUAVER, 3, c3, d4,  g4);
    beep(SEMIQUAVER, 3, g3, db4, g4);
    beep(SEMIQUAVER, 3, g3, c4,  g4);
    beep(SEMIQUAVER, 3, c3, db4, g4);
    beep(SEMIQUAVER, 3, c3, d4,  g4);
    beep(SEMIQUAVER, 3, g3, db4, fs4);
    beep(SEMIQUAVER, 3, g3, c4,  fs4);
    beep(SEMIQUAVER, 3, c3, db4, fs4);
    beep(SEMIQUAVER, 3, c3, d4,  fs4);
    beep(SEMIQUAVER, 3, g3, eb4, fs4);
    beep(SEMIQUAVER, 3, g3, d4,  fs4);
    beep(SEMIQUAVER, 3, c3, db4,  e4);
    beep(SEMIQUAVER, 3, c3, c4,  e4);
    beep(SEMIQUAVER, 3, g3, b3,  e4);
    beep(SEMIQUAVER, 3, g3, c4,  e4);

    //bar 12
    beep(SEMIQUAVER, 2, d4,  g4);
    beep(SEMIQUAVER, 2, eb4, g4);
    beep(SEMIQUAVER, 2, d4,  g4);
    beep(SEMIQUAVER, 2, cs4, g4);
    beep(SEMIQUAVER, 2, d4,  g4);
    beep(SEMIQUAVER, 2, eb4, g4);
    beep(SEMIQUAVER, 2, d4,  a4);
    beep(SEMIQUAVER, 2, c4,  a4);
    beep(SEMIQUAVER, 2, d4,  a4);
    beep(SEMIQUAVER, 2, eb4, a4);
    beep(SEMIQUAVER, 2, e4,  a4);
    beep(SEMIQUAVER, 2, f4,  a4);
    beep(SEMIQUAVER, 2, e4,  g4);
    beep(SEMIQUAVER, 2, eb4, g4);
    beep(SEMIQUAVER, 2, d4,  g4);
    beep(SEMIQUAVER, 2, cs4, g4);

    //bar 13
    beep(SEMIQUAVER, 2, d4, ab5);
    beep(SEMIQUAVER, 2, ds4, ab5);
    beep(SEMIQUAVER, 2, e4, ab5);
    beep(SEMIQUAVER, 2, f4, ab5);
    beep(SEMIQUAVER, 2, fs4, ab5);
    beep(SEMIQUAVER, 2, g4,  ab5);
    beep(SEMIQUAVER, 2, gs4, ab5);
    beep(SEMIQUAVER, 2, a4,  ab5);
    beep(SEMIQUAVER, 2, ab4, ab5);
    beep(SEMIQUAVER, 2, g4,  ab5);
    beep(SEMIQUAVER, 2, gb4, ab5);
    beep(SEMIQUAVER, 2, f4,  ab5);
    beep(SEMIQUAVER, 2, e4,  g5);
    beep(SEMIQUAVER, 2, eb4, g5);
    beep(SEMIQUAVER, 1, d4);
    beep(SEMIQUAVER, 1, db4);

    //bar 14
    beep(SEMIQUAVER, 2, d4, ab5);
    beep(SEMIQUAVER, 2, ds4, ab5);
    beep(SEMIQUAVER, 2, e4,  g5);
    beep(SEMIQUAVER, 2, f4,  g5);
    beep(SEMIQUAVER, 1, fs4);
    beep(SEMIQUAVER, 1, g4);
    beep(SEMIQUAVER, 1, gb4);
    beep(SEMIQUAVER, 1, f4);
    beep(SEMIQUAVER, 2, e4, db5);
    beep(SEMIQUAVER, 2, eb4, db5);
    beep(SEMIQUAVER, 2, d4, db5);
    beep(SEMIQUAVER, 2, ds4, db5);
    beep(SEMIQUAVER, 3, d4, e4,  db5);
    beep(SEMIQUAVER, 2, f4,  db5);
    beep(SEMIQUAVER, 3, db4, fs4, db5);
    beep(SEMIQUAVER, 2, g4,  db5);

loop:
    //bar 15
    beep(QUAVER, 2, c3, c5);
    beep(QUAVER, 2, g3, c5);
    beep(QUAVER, 2, c3, c5);
    beep(QUAVER, 2, g3, bb4);
    beep(QUAVER, 2, c3, bb4);
    beep(QUAVER, 2, g3, bb4);
    beep(QUAVER, 2, c3, ab4);
    beep(QUAVER, 2, g3, ab4);
	
    //bar 16
    beep(QUAVER, 2, c3, db5);
    beep(QUAVER, 2, g3, db5);
    beep(QUAVER, 2, c3, db5);
    beep(QUAVER, 2, g3, c5);
    beep(QUAVER, 2, c3, c5);
    beep(QUAVER, 2, g3, c5);
    beep(QUAVER, 2, c3, bb4);
    beep(QUAVER, 2, g3, bb4);

    //bar 17
    beep(QUAVER, 2, c3, f5);
    beep(QUAVER, 2, g3, f5);
    beep(QUAVER, 2, c3, f5);
    beep(QUAVER, 2, g3, e5);
    beep(QUAVER, 2, c3, e5);
    beep(QUAVER, 2, g3, e5);
    beep(QUAVER, 2, c3, d5);
    beep(QUAVER, 2, g3, d5);

    //bar 18
    beep(QUAVER, 2, c3, bb4);
    beep(QUAVER, 2, g3, bb4);
    beep(QUAVER, 2, c3, c5);
    beep(QUAVER, 2, g3, c5);
    beep(QUAVER, 2, c3, d5);
    beep(QUAVER, 2, g3, d5);
    beep(QUAVER, 2, c3, f5);
    beep(QUAVER, 2, g3, f5);

    //bar 19
    beep(SEMIQUAVER, 2, db3, ab5);
    beep(SEMIQUAVER, 3, db3, d4,  ab5);
    beep(SEMIQUAVER, 3, ab3, ds4, ab5);
    beep(SEMIQUAVER, 3, ab3, e4,  ab5);
    beep(SEMIQUAVER, 3, db3, f4,  ab5);
    beep(SEMIQUAVER, 3, db3, fs4, ab5);
    beep(SEMIQUAVER, 3, ab3, g4,  ab5);
    beep(SEMIQUAVER, 3, ab3, gs4, ab5);
    beep(SEMIQUAVER, 3, db3, a4,  ab5);
    beep(SEMIQUAVER, 3, db3, ab4, ab5);
    beep(SEMIQUAVER, 3, ab3, g4,  ab5);
    beep(SEMIQUAVER, 3, ab3, gb4, ab5);
    beep(SEMIQUAVER, 3, db3, f4,  ab5);
    beep(SEMIQUAVER, 3, db3, e4,  ab5);
    beep(SEMIQUAVER, 3, ab3, eb4, ab5);
    beep(SEMIQUAVER, 3, ab3, d4,  ab5);

    //bar 20
    beep(SEMIQUAVER, 3, db3, cs4, ab5);
    beep(SEMIQUAVER, 3, db3, d4,  ab5);
    beep(SEMIQUAVER, 3, ab3, ds4, ab5);
    beep(SEMIQUAVER, 3, ab3, e4,  ab5);
    beep(SEMIQUAVER, 3, db3, f4,  ab5);
    beep(SEMIQUAVER, 3, db3, fs4, ab5);
    beep(SEMIQUAVER, 3, ab3, g4,  ab5);
    beep(SEMIQUAVER, 3, ab3, gs4, ab5);
    beep(SEMIQUAVER, 3, db3, a4,  ab5);
    beep(SEMIQUAVER, 3, db3, ab4, ab5);
    beep(SEMIQUAVER, 3, ab3, g4,  ab5);
    beep(SEMIQUAVER, 3, ab3, gb4, ab5);
    beep(SEMIQUAVER, 3, db3, f4,  ab5);
    beep(SEMIQUAVER, 3, db3, e4,  ab5);
    beep(SEMIQUAVER, 3, ab3, eb4, ab5);
    beep(SEMIQUAVER, 3, ab3, d4,  ab5);

    //bar 21
    beep(SEMIQUAVER, 2, c3,      g5);
    beep(SEMIQUAVER, 3, c3, d4,  g5);
    beep(SEMIQUAVER, 3, g3, ds4, g5);
    beep(SEMIQUAVER, 3, g3, e4,  g5);
    beep(SEMIQUAVER, 3, c3, f4,  g5);
    beep(SEMIQUAVER, 3, c3, fs4, g5);
    beep(SEMIQUAVER, 3, g3, g4,  g5);
    beep(SEMIQUAVER, 3, g3, gs4, g5);
    beep(SEMIQUAVER, 3, c3, a4,  g5);
    beep(SEMIQUAVER, 3, c3, ab4, g5);
    beep(SEMIQUAVER, 3, g3, g4,  g5);
    beep(SEMIQUAVER, 3, g3, gb4, g5);
    beep(SEMIQUAVER, 3, c3, f4,  g5);
    beep(SEMIQUAVER, 3, c3, e4,  g5);
    beep(SEMIQUAVER, 3, g3, eb4, g5);
    beep(SEMIQUAVER, 3, g3, d4,  g5);

    //bar 22
    beep(SEMIQUAVER, 3, c3, cs4, g5);
    beep(SEMIQUAVER, 3, c3, d4 ,  g5);
    beep(SEMIQUAVER, 3, g3, ds4, g5);
    beep(SEMIQUAVER, 3, g3, e4 ,  g5);
    beep(SEMIQUAVER, 3, c3, f4 ,  g5);
    beep(SEMIQUAVER, 3, c3, gb4, g5);
    beep(SEMIQUAVER, 3, g3, f4 ,  g5);
    beep(SEMIQUAVER, 3, g3, e4 , g5);
    beep(SEMIQUAVER, 3, c3, eb4,  g5);
    beep(SEMIQUAVER, 3, c3, d4 , g5);
    beep(SEMIQUAVER, 3, g3, cs4 ,  g5);
    beep(SEMIQUAVER, 3, g3, d4 , g5);
    beep(SEMIQUAVER, 3, c3, ds4,  g5);
    beep(SEMIQUAVER, 3, c3, e4 ,  g5);
    beep(SEMIQUAVER, 3, g3, f4 , g5);
    beep(SEMIQUAVER, 3, g3, fs4,  g5);

    //bar 23
    beep(QUAVER, 3, bb2, d4, f4); 
    beep(QUAVER, 3, f3 , d4, f4); 
    beep(QUAVER, 3, bb2, c4, f4); 
    beep(QUAVER, 3, f3 , c4, f4); 
    beep(QUAVER, 3, bb2, d4, bb4); 
    beep(QUAVER, 3, f3 , d4, bb4); 
    beep(QUAVER, 3, bb2, f4, bb4); 
    beep(QUAVER, 3, f3 , f4, bb4); 

    //bar 24
    beep(QUAVER, 3, bb2, e4, d5); 
    beep(QUAVER, 3, f3 , e4, d5); 
    beep(QUAVER, 3, bb2, e4, d5); 
    beep(QUAVER, 3, f3 , d4, d5); 
    beep(QUAVER, 3, bb2, d4, f5); 
    beep(QUAVER, 3, f3 , d4, f5); 
    beep(QUAVER, 3, bb2, f4, f5); 
    beep(QUAVER, 3, f3 , f4, f5); 


    //bar 25
    beep(QUAVER, 3, c3, a4, e5); 
    beep(QUAVER, 3, g3, a4, e5); 
    beep(QUAVER, 3, c3, a4, e5); 
    beep(QUAVER, 3, g3, a4, e5); 
    beep(QUAVER, 3, c3, a4, e5); 
    beep(QUAVER, 3, g3, a4, e5); 
    beep(QUAVER, 3, c3, a4, e5); 
    beep(QUAVER, 3, g3, a4, e5); 

    //bar 26
    beep(QUAVER, 3, c3, g4, e5); 
    beep(QUAVER, 3, g3, g4, e5); 
    beep(QUAVER, 3, c3, g4, e5); 
    beep(QUAVER, 3, g3, g4, e5); 
    beep(QUAVER, 3, c3, g4, e5); 
    beep(QUAVER, 3, g3, g4, e5); 
    beep(QUAVER, 3, c3, g4, e5); 
    beep(QUAVER, 3, g3, g4, e5); 

    //bar 27
    beep(QUAVER, 3, c3, d4, f4); 
    beep(QUAVER, 3, f3, d4, f4); 
    beep(QUAVER, 3, c3, c4, f4); 
    beep(QUAVER, 3, f3, c4, f4); 
    beep(QUAVER, 3, c3, d4, bb4); 
    beep(QUAVER, 3, f3, d4, bb4); 
    beep(QUAVER, 3, c3, f4, bb4); 
    beep(QUAVER, 3, f3, f4, bb4); 
                      
    //bar 28          
    beep(QUAVER, 3, c3, g4, d5); 
    beep(QUAVER, 3, f3, g4, d5); 
    beep(QUAVER, 3, c3, g4, d5); 
    beep(QUAVER, 3, f3, a4, d5); 
    beep(QUAVER, 3, c3, a4, f5); 
    beep(QUAVER, 3, f3, a4, f5); 
    beep(QUAVER, 3, c3, b4, f5); 
    beep(QUAVER, 3, f3, b4, f5); 


    //bar 29
    beep(QUAVER, 3, c3, c5, g5); 
    beep(QUAVER, 3, g3, c5, g5); 
    beep(QUAVER, 3, c3, c5, g5); 
    beep(QUAVER, 3, g3, c5, g5); 
    beep(QUAVER, 3, c3, c5, g5); 
    beep(QUAVER, 3, g3, c5, g5); 
    beep(QUAVER, 3, c3, c5, g5); 
    beep(QUAVER, 3, g3, c5, g5); 

    //bar 30
    beep(QUAVER, 3, c3, g5, c6); 
    beep(QUAVER, 3, g3, g5, c6); 
    beep(QUAVER, 3, c3, g5, c6); 
    beep(QUAVER, 3, g3, g5, c6); 
    beep(QUAVER, 3, c3, g5, c6); 
    beep(QUAVER, 3, g3, g5, c6); 
    beep(QUAVER, 3, c3, g5, c6); 
    beep(QUAVER, 3, g3, g5, c6); 

    //bar 31
    beep(QUAVER, 3, c3, c5, e5); 
    beep(QUAVER, 3, g3, c5, e5); 
    beep(QUAVER, 3, c3, c5, e5); 
    beep(QUAVER, 3, g3, c5, e5); 
    beep(QUAVER, 1, c3); 
    beep(QUAVER, 1, g3); 
    beep(QUAVER, 3, c3, c5, e5); 
    beep(QUAVER, 1, g3); 

    //bar 32
    beep(QUAVER, 3, c3, d5, f5); 
    beep(QUAVER, 3, g3, c5, e5); 
    beep(QUAVER, 1, c3); 
    beep(QUAVER, 1, g3); 
    beep(QUAVER, 1, c3); 
    beep(QUAVER, 1, g3); 
    beep(QUAVER, 1, c3); 
    beep(QUAVER, 1, g3); 

    //bar 33
    beep(QUAVER, 3, db3, db5, f5); 
    beep(QUAVER, 3, ab3, db5, f5); 
    beep(QUAVER, 3, db3, db5, f5); 
    beep(QUAVER, 3, ab3, db5, f5); 
    beep(QUAVER, 1, db3); 
    beep(QUAVER, 1, ab3); 
    beep(QUAVER, 3, db3, db5, f5); 
    beep(QUAVER, 1, ab3); 

    //bar 34
    beep(QUAVER, 3, db3, f5, ab5); 
    beep(QUAVER, 3, ab3, eb5, g5); 
    beep(QUAVER, 3, db3, eb5, g5); 
    beep(QUAVER, 1, ab3); 
    beep(QUAVER, 3, db3, db5, f5); 
    beep(QUAVER, 3, ab3, db5, f5); 
    beep(QUAVER, 3, db3, db5, f5); 
    beep(QUAVER, 3, ab3, db5, f5); 

    //bar 35
    beep(QUAVER, 2, c3, g5);
    beep(QUAVER, 2, g3, g5);
    beep(QUAVER, 2, c3, g5);
    beep(QUAVER, 2, g3, fs5);
    beep(QUAVER, 2, c3, fs5);
    beep(QUAVER, 2, g3, fs5);
    beep(QUAVER, 2, c3, e5);
    beep(QUAVER, 2, g3, e5);
	
    //bar 36
    beep(QUAVER, 2, c3, g5);
    beep(QUAVER, 2, g3, g5);
    beep(QUAVER, 2, c3, g5);
    beep(QUAVER, 2, g3, a5);
    beep(QUAVER, 2, c3, a5);
    beep(QUAVER, 2, g3, a5);
    beep(QUAVER, 2, c3, g5);
    beep(QUAVER, 2, g3, g5);

    //bar 37
    beep(SEMIQUAVER, 2, d4, ab5);
    beep(SEMIQUAVER, 2, ds4, ab5);
    beep(SEMIQUAVER, 2, e4, ab5);
    beep(SEMIQUAVER, 2, f4, ab5);
    beep(SEMIQUAVER, 2, fs4, ab5);
    beep(SEMIQUAVER, 2, g4,  ab5);
    beep(SEMIQUAVER, 2, gs4, ab5);
    beep(SEMIQUAVER, 2, a4,  ab5);
    beep(SEMIQUAVER, 2, ab4, ab5);
    beep(SEMIQUAVER, 2, g4,  ab5);
    beep(SEMIQUAVER, 2, gb4, ab5);
    beep(SEMIQUAVER, 2, f4,  ab5);
    beep(SEMIQUAVER, 2, e4,  g5);
    beep(SEMIQUAVER, 2, eb4, g5);
    beep(SEMIQUAVER, 1, d4);
    beep(SEMIQUAVER, 1, db4);

    //bar 38
    beep(SEMIQUAVER, 2, d4, ab5);
    beep(SEMIQUAVER, 2, ds4, ab5);
    beep(SEMIQUAVER, 2, e4,  g5);
    beep(SEMIQUAVER, 2, f4,  g5);
    beep(SEMIQUAVER, 1, fs4);
    beep(SEMIQUAVER, 1, g4);
    beep(SEMIQUAVER, 1, gb4);
    beep(SEMIQUAVER, 1, f4);
    beep(SEMIQUAVER, 2, e4, db5);
    beep(SEMIQUAVER, 2, eb4, db5);
    beep(SEMIQUAVER, 2, d4, db5);
    beep(SEMIQUAVER, 2, ds4, db5);
    beep(SEMIQUAVER, 3, d4, e4,  db5);
    beep(SEMIQUAVER, 2, f4,  db5);
    beep(SEMIQUAVER, 3, db4, fs4, db5);
    beep(SEMIQUAVER, 2, g4,  db5);

    goto loop;
    geep_close();
    exit(EXIT_SUCCESS);
}
