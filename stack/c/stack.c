#include "stack.h" /* Include there everything */

retval Stack_push(Stack * stack, retval element)
{
    if (stack->top == MAXSIZE) {
        assert(false && "stack overflow");
    } else {
        stack->items[stack->top] = element;
        stack->top++;
    }
    return element;
}

retval Stack_pop(Stack * stack)
{
    if (stack->top == 0) {
        assert(false && "stack underflow");
    } else {
        stack->top--;
        return stack->items[stack->top];
    }
}
