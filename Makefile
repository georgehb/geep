CC=gcc
FLAGS=-Wall -O3 -ffast-math
COMMON_DEPS=libgeep.a tunes/notes.h geep.h

.PHONY : all
all : libgeep.a tunes

default : all

.PHONY : tunes
tunes : libgeep.a
	$(MAKE) -C $@

libgeep.a : geep.o
	ar rcs $@ $^

geep.o : geep.c geep.h
	${CC} -c -o $@ $<

clean :
	rm -f *.o *.a
