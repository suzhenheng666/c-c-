#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Stack {
    int *data;
    int top;
    int capacity;
} Stack;

Stack *create_stack(int capacity);// 创建栈
void destroy_stack(Stack *stack);// 销毁栈
int is_empty(Stack *stack);// 判断栈是否为空
int is_full(Stack *stack);// 判断栈是否为满
void push(Stack *stack, int value);// 入栈
int pop(Stack *stack);// 出栈
int peek(Stack *stack);// 取栈顶元素

#endif