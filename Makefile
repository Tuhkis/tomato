UNAME := $(shell uname)

CFLAGS=-pipe -O0
LOPTIONS=
CC=
AR=ar
LIBS=
OUT=tomato.a

ifeq ($(UNAME), Linux)
	CC+=gcc
endif
ifeq ($(UNAME), Darwin)
	CC+=clang
endif

COMP=${CC} ${CFLAGS} -c

all: tomato.c
	${AR} rc ${OUT} *.o

tomato.o: src/tomato.c
	${COMP} src/tomato.c
