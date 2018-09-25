CC=gcc
CFLAGS=-Wall -O3 `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

.PHONY : all
all : geepui

default : all

% : %.o
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

%.o : %.c notes.h
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	rm -f *.o
