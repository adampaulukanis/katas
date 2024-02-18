CC = clang
CFLAGS = -g -Wall

all: test1 stack.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o stack.o
	rm -f test1 test1.core

test1: test1.c stack.o
	$(CC) $(CFLAGS) test1.c stack.o -o test1
