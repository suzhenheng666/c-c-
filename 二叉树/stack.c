#include "stack.h"

// 创建栈
Stack *create_stack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    assert(stack != NULL);
    stack->data = (int *)malloc(capacity * sizeof(int));
    assert(stack->data != NULL);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}
// 销毁栈
void destroy_stack(Stack *stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}
// 判断栈是否为空
int is_empty(Stack *stack) {
    assert(stack != NULL);
    return stack->top == -1;
}  
// 判断栈是否为满
int is_full(Stack *stack) {
    assert(stack != NULL);
    return stack->top == stack->capacity - 1;
}
// 入栈操作
void push(Stack *stack, int value) {
    assert(stack != NULL);
    assert(!is_full(stack));
    stack->data[++stack->top] = value;
}
// 出栈操作
int pop(Stack *stack) {
    assert(stack != NULL);
    assert(!is_empty(stack));
    return stack->data[stack->top--];
}
// 获取栈顶元素
int peek(Stack *stack) {
    assert(stack != NULL);
    assert(!is_empty(stack));
    return stack->data[stack->top];
}