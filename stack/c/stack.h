#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#define MAXSIZE 10

typedef int retval;

typedef struct Stack {
    ssize_t top;
    retval items[MAXSIZE];
} Stack;

retval Stack_push(Stack * stack, retval element);
retval Stack_pop(Stack * stack);
