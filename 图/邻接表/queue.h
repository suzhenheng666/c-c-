#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q);//初始化队列
void queuePush(Queue* q, int value);//入队操作
int queuePop(Queue* q);//出队操作
int queuePeek(Queue* q);//获取队首元素
int queueBack(Queue* q);//获取队尾元素
int queueIsEmpty(Queue* q);//判断队列是否为空
int queueSize(Queue* q);//获取队列大小
void freeQueue(Queue* q);//回收队列内存

#endif