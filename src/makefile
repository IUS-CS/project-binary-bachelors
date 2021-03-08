OBJS = main.o game.o graphics_component.o game_object.o graphics_engine.o vector2.o input_engine.o input_component.o
TEST_OBJS = catch_amalgamated.o unit_tests.o
CFLAGS = -Wall -g -std=c++17
LIBS = `sdl2-config --cflags --libs` -lSDL2_image
CC = g++

.PHONY: all clean test

all: zordo.out test

unit_tests.out: ${TEST_OBJS}
	      ${CC} ${CFLAGS} ${TEST_OBJS} -o $@

test: unit_tests.out
	 ./unit_tests.out

zordo.out: ${OBJS}
	      ${CC} ${CFLAGS} ${OBJS} ${LIBS} -o $@

.cpp.o:
	${CC} ${CFLAGS} -c -MMD $<

clean:
	rm *.out *.o

-include *.d
