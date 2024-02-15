#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct Stack {
    int top;
    int items[MAXSIZE];
};

void Stack_push(struct Stack * stack, int element)
{
    if (stack->top == MAXSIZE) {
        printf("stack overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top] = element;
    }
}

void Stack_pop(struct Stack * stack)
{
    if (stack->top < 0) {
        printf("stack underflow\n");
    } else {
        stack->top--;
        /*
        int ret = stack->items[stack->top];
        printf("%d\n", ret);
        */
    }
}

void Stack_print(struct Stack * stack)
{
    int i = 0;
    if (stack->top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = 0; i <= stack->top; ++i) {
            printf("%d : %d\n", i, stack->items[i]);
        }
    }
}

int main(void)
{
    struct Stack s = { -1 }; /* init */

    Stack_print(&s);

    Stack_push(&s, 1);
    Stack_push(&s, 2);
    Stack_push(&s, 3);
    Stack_pop(&s);
    Stack_pop(&s);
    Stack_pop(&s);
    Stack_pop(&s);

    Stack_print(&s);

    return 0;
}
