CC=gcc
FLAGS=-Wall -O3 -ffast-math
COMMON_DEPS=../libgeep.a notes.h ../geep.h

.PHONY : all
all : lavendertown sailormoon tuxedomask wildpokemonbattle zelda

default : all

lavendertown : lavendertown.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

sailormoon : sailormoon.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

tuxedomask : tuxedomask.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

wildpokemonbattle : wildpokemonbattle.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

zelda : zelda.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

clean :
	rm -f *.o
