CC=gcc
FLAGS=-Wall -O3 -ffast-math
COMMON_DEPS=../libgeep.a notes.h ../geep.h

.PHONY : all
all : sailormoon zelda

default : all

sailormoon : sailormoon.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

zelda : zelda.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

clean :
	rm -f *.o
