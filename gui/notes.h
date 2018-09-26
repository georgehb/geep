#ifndef NOTES_H
#define NOTES_H

/* 
 * #define NANOSECONDS 1000000000lu
 * #define CROTCHET (NANOSECONDS * 60lu / BPM)
 * #define QUAVER (CROTCHET / 2)
 * #define SEMIQUAVER (CROTCHET / 4)
 * #define DEMISEMIQUAVER (CROTCHET / 8)
 * #define SIXTH (CROTCHET / 6)
 * #define SEPARATION (CROTCHET / 50)
 */
#define NUM_NOTES 108

/* Array of all notes from c0 to b8 */

static const int notes[NUM_NOTES] = {
	16,   17,   18,   19,   21,   22,   23,   25,   26,   28,   29,   31, 
	33,   35,   37,   39,   41,   44,   46,   49,   52,   55,   58,   62, 
	65,   69,   73,   78,   82,   87,   93,   98,   104,  110,  117,  123,
       	131,  139,  147,  156,  165,  175,  185,  196,  208,  220,  233,  247,
       	262,  277,  294,  311,  330,  349,  370,  392,  415,  440,  466,  494,
       	523,  554,  587,  622,  659,  698,  740,  784,  831,  880,  932,  988,
       	1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
       	2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951,
       	4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902
};

static const char *note_names[NUM_NOTES] = {
	"c0", "db0", "d0", "eb0", "e0", "f0", "gb0", "g0", "ab0", "a0", "bb0", "b0",
	"c1", "db1", "d1", "eb1", "e1", "f1", "gb1", "g1", "ab1", "a1", "bb1", "b1",
	"c2", "db2", "d2", "eb2", "e2", "f2", "gb2", "g2", "ab2", "a2", "bb2", "b2",
       	"c3", "db3", "d3", "eb3", "e3", "f3", "gb3", "g3", "ab3", "a3", "bb3", "b3",
       	"c4", "db4", "d4", "eb4", "e4", "f4", "gb4", "g4", "ab4", "a4", "bb4", "b4",
       	"c5", "db5", "d5", "eb5", "e5", "f5", "gb5", "g5", "ab5", "a5", "bb5", "b5",
       	"c6", "db6", "d6", "eb6", "e6", "f6", "gb6", "g6", "ab6", "a6", "bb6", "b6",
       	"c7", "db7", "d7", "eb7", "e7", "f7", "gb7", "g7", "ab7", "a7", "bb7", "b7",
       	"c8", "db8", "d8", "eb8", "e8", "f8", "gb8", "g8", "ab8", "a8", "bb8", "b8"
};

#endif /* NOTES_H */