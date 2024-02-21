CC = clang
CFLAGS = -g -Wall

all: tests stack.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o stack.o
	rm -f tests tests.core

tests: tests.c stack.o
	$(CC) $(CFLAGS) tests.c stack.o -o tests
