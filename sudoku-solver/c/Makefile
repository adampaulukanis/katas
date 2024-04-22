CC = clang
CFLAGS = -g -Wall -Wextra -pedantic -std=c11 

all: all-solutions

all-solutions: all-solutions.c
	$(CC) $(CFLAGS) all-solutions.c -o all-solutions

clean:
	rm -f main *.core
	rm -f all-solutions
