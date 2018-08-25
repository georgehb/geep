CC=gcc
FLAGS=-Wall -O3 -ffast-math
INSTALL_DIR=/usr/bin
COMMON_DEPS=libgeep.a notes.h geep.h

default : sailormoon

sailormoon : sailormoon.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

libgeep.a : geep.o
	ar rcs $@ $^

gepp.o : geep.c geep.h
	${CC} -c -o $@ $<

clean :
	rm -f *.o *.a
