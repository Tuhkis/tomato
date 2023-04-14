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

all: tomato.o
	${AR} rc ${OUT} *.o

tomato.o: src/tomato.c
	${COMP} src/tomato.c

test: all
	${CC} -c test/test.c
	${CC} test.o tomato.a -o test_exe
	./test_exe

clean:
	rm *.o
	rm *.a
	rm test_exe
