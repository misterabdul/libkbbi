BIN := test

SRC := test.c

CFLAGS := ${shell pkg-config --libs --cflags libkbbi}

all: ${SRC}
	${CC} -o ${BIN} $< ${CFLAGS}
