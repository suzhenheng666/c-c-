#include "stack.h"

int main()
{
    Stack *stack = create_stack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Is stack empty? %s\n", is_empty(stack) ? "Yes" : "No");
    destroy_stack(stack);
    return 0;
}