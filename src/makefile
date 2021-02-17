OBJS = employee_database.o
CFLAGS = -std=c++17
CC = g++

all: employee_database.out

employee_database.out: ${OBJS}
	      ${CC} ${CFLAGS} ${OBJS} -o $@

.cpp.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm *.out *.o
