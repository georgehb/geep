CC=gcc
FLAGS=-Wall -O3 -ffast-math
COMMON_DEPS=../libgeep.a notes.h ../geep.h

.PHONY : all
all : sailormoon tuxedomask zelda

default : all

sailormoon : sailormoon.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

tuxedomask : tuxedomask.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

zelda : zelda.c ${COMMON_DEPS}
	${CC} ${FLAGS} -o $@ $^

clean :
	rm -f *.o
