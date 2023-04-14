UNAME := $(shell uname)

CFLAGS=-pipe -O3
LOPTIONS=
CC=
AR=ar
LIBS=
OUT=tomato.a

ifeq ($(UNAME), Linux)
	CC+=gcc
	LIBS+=-lGL -ldl -lm -lglfw
endif
# WARN: MacOS support completely and utterly untested!
ifeq ($(UNAME), Darwin)
	CC+=clang
	LIBS+=-lglfw -framework Metal -framework Cocoa -framework MetalKit -framework Quartz
endif

COMP=${CC} ${CFLAGS} -c

all: tomato.o sokol-impl.o window.o
	${AR} rc ${OUT} *.o

tomato.o: src/tomato.c
	${COMP} src/tomato.c

window.o: src/window.c
	${COMP} src/window.c

sokol-impl.o: src/sokol-impl.c
	${COMP} src/sokol-impl.c

test: all
	${CC} -c test/test.c
	${CC} test.o tomato.a -o test_exe ${LIBS}
	./test_exe

clean:
	rm *.o
	rm *.a
	rm test_exe
