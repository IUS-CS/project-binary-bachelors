OBJS = main.o game.o graphics_component.o graphics_engine.o vector2.o input_engine.o input_component.o movement_engine.o map_engine.o collision_detection_engine.o utils.o health_engine.o ai_engine.o hud_engine.o animation_engine.o wallet_engine.o spawn_engine.o
TEST_OBJS = catch_amalgamated.o unit_tests.o movement_engine.o input_component.o vector2.o utils.o health_engine.o collision_detection_engine.o ai_engine.o animation_engine.o
CFLAGS = -Wall -g -std=c++17
LIBS = `sdl2-config --cflags --libs` -lSDL2_image
CC = g++

.PHONY: all clean test

all: zordo.out test

unit_tests.out: ${TEST_OBJS}
	      ${CC} ${CFLAGS} ${TEST_OBJS} ${LIBS} -o $@

test: unit_tests.out
	 ./unit_tests.out

zordo.out: ${OBJS}
	      ${CC} ${CFLAGS} ${OBJS} ${LIBS} -o $@

.cpp.o:
	${CC} ${CFLAGS} -c -MMD $<

clean:
	rm *.out *.o *.d

-include *.d
