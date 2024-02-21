#include <stdbool.h>
#include <assert.h>

#include "stack.h"

void test_stack_overflow()
{
    struct Stack s = {0};
    // First, I would have tested push()
    Stack_push(&s, 1);
    Stack_push(&s, 2);
    Stack_push(&s, 3);
    Stack_push(&s, 4);
    Stack_push(&s, 5);
    Stack_push(&s, 6);
    Stack_push(&s, 7);
    Stack_push(&s, 8);
    Stack_push(&s, 9);
    Stack_push(&s, 10);
    Stack_push(&s, 11);
}

int main2(void)
{
    test_stack_overflow();
    return 0;
}

int main(void)
{
    Stack s = {0}; /* init */

    assert(s.top <= 0 && "should be empty");

    assert(Stack_push(&s, 1) == 1 && "should it be 1");
    assert(s.top == 1 && "should top be 1");

    assert(Stack_push(&s, 2) == 2 && "should it be 2");
    assert(s.top == 2 && "should top be 2");

    Stack_push(&s, 3);
    assert(s.top == 3 && "should top be 3");
    assert(s.items[3-1] == 3 && "should be 3");

    assert(Stack_pop(&s) == 3 && "should return 3");
    assert(Stack_pop(&s) == 2 && "should return 2");
    assert(Stack_pop(&s) == 1 && "should return 1");

    // It will throw error
//    Stack_pop(&s);

    for (size_t i = 0; i < MAXSIZE; ++i) {
        Stack_push(&s, i);
    }

    printf("%s\n", "Everything's OK.");

    return 0;
}
