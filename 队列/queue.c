#include "queue.h"
//初始化队列
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}
//创建新节点
Node* createQNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
//入队操作
void queuePush(Queue* q, int value) {
    assert(q != NULL);
    Node* newNode = createQNode(value);
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
    q->size++;
}
//出队操作
int queuePop(Queue* q) {
    assert(q != NULL);
    assert(q->size > 0);
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return value;
}

//获取队首元素
int queuePeek(Queue* q) {
    assert(q != NULL);
    assert(q->size > 0);
    return q->front->data;
}
//获取队尾元素
int queueBack(Queue* q) {
    assert(q != NULL);
    assert(q->size > 0);
    return q->rear->data;
}
//判断队列是否为空
int queueIsEmpty(Queue* q) {
    assert(q != NULL);
    return q->size == 0;
}
//回收队列内存
void freeQueue(Queue* q) {  
    assert(q != NULL);
    Node* current = q->front;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}
//获取队列大小
int queueSize(Queue* q) {
    assert(q != NULL);
    return q->size;
}