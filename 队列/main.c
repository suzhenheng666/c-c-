#include "queue.h"
int main() {
    Queue q;
    initQueue(&q);

    queuePush(&q, 10);
    queuePush(&q, 20);
    queuePush(&q, 30);

    printf("Front element: %d\n", queuePeek(&q));
    printf("Back element: %d\n", queueBack(&q));
    printf("Queue size: %d\n", queueSize(&q));

    while (!queueIsEmpty(&q)) {
        printf("Popped element: %d\n", queuePop(&q));
    }

    freeQueue(&q);
    return 0;
}