CC=gcc
CFLAGS=-Wall -g `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

.PHONY : all
all : geepui

default : all

geepui : geepui.o drawing.o notes.o note_grid.o
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

%.o : %.c *.h Makefile
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	rm -f geepui *.o
