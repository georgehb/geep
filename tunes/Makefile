CC=gcc
FLAGS=-Wall -O3 -ffast-math
COMMON_DEPS=../libgeep.a notes.h ../geep.h Makefile
BUILD_DEPS=../libgeep.a

.PHONY : all
all : lavendertown turnaboutsisters pursuitcornered sailormoon tuxedomask wildpokemonbattle zelda

default : all

% : %.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $< ${BUILD_DEPS}

clean :
	rm -f *.o
