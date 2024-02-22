#include "stack.h" /* Includes go there */

retval Stack_push(Stack * stack, retval element)
{
    if (stack->top == MAXSIZE) {
        fprintf(stderr, "Error: stack overflow");
        return -1; /* error */
    } else {
        stack->items[stack->top] = element;
        stack->top++;
        return element;
    }
}

retval Stack_pop(Stack * stack)
{
    if (stack->top == 0) {
        fprintf(stderr, "Error: stack underflow");
        return -1; /* error */
    } else {
        stack->top--;
        return stack->items[stack->top];
    }
}
