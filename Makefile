CC=gcc
FLAGS=-Wall -O3 -ffast-math
COMMON_DEPS=libgeep.a tunes/notes.h geep.h

.PHONY : all
all : tunes libgeep.a

default : all

.PHONY : tunes
tunes :
	$(MAKE) -C $@

libgeep.a : geep.o
	ar rcs $@ $^

geep.o : geep.c geep.h
	${CC} -c -o $@ $<

clean :
	rm -f *.o *.a
