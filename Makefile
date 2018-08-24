CC=gcc
FLAGS=-Wall -O3 -ffast-math
EXEC_NAME=geep
INSTALL_DIR=/usr/bin

default : geep

clean :
	rm ${EXEC_NAME}

geep : geep.c
	${CC} ${FLAGS} -o ${EXEC_NAME} geep.c

install :
	cp ${EXEC_NAME} ${INSTALL_DIR}
