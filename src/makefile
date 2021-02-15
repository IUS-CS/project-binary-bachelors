OBJS = main.o
CFLAGS = -std=c++17
LIBS = 
CC = g++

all: database.out

database.out: ${OBJS}
	      ${CC} ${CFLAGS} ${OBJS} ${LIBS} -o $@

.cpp.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm *.out *.o
