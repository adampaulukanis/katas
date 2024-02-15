CC = clang
CFLAGS = -g -Wall

stack: stack.o
	$(CC) $(CFLAGS) stack.o -o stack

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm stack.o stack
