OBJS = employee_database.o user_interface.o
TEST_OBJS = catch_amalgamated.o unit_tests.o
CFLAGS = -std=c++17
CC = g++

.PHONY: all clean

all: employee_database.out test

unit_tests.out: ${TEST_OBJS}
	      ${CC} ${CFLAGS} ${TEST_OBJS} -o $@

test: unit_tests.out
	 ./unit_tests.out

employee_database.out: ${OBJS}
	      ${CC} ${CFLAGS} ${OBJS} -o $@

.cpp.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm *.out *.o
