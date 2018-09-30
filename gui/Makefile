CC=gcc
CFLAGS=-Wall -O3  `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

.PHONY : all
all : geepui

default : all

geepui : *.o
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

%.o : %.c *.h Makefile
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	rm -f geepui *.o
