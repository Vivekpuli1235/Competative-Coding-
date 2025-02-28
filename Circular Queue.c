

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

int isFull(CircularQueue* cq) {
    return (cq->rear + 1) % SIZE == cq->front;
}

int isEmpty(CircularQueue* cq) {
    return cq->front == -1;
}

void enqueue(CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % SIZE;
    cq->items[cq->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = cq->items[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

int front(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return cq->items[cq->front];
}

int rear(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return cq->items[cq->rear];
}

void display(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = cq->front;
    while (1) {
        printf("%d ", cq->items[i]);
        if (i == cq->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue cq;
    initializeQueue(&cq);

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);
    display(&cq);

    printf("Front: %d\n", front(&cq));
    printf("Rear: %d\n", rear(&cq));

    dequeue(&cq);
    dequeue(&cq);
    display(&cq);

    enqueue(&cq, 60);
    enqueue(&cq, 70);
    display(&cq);

    printf("Front: %d\n", front(&cq));
    printf("Rear: %d\n", rear(&cq));

    return 0;
}
