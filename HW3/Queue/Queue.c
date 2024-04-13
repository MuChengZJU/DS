#include "Queue.h"

#include <stdlib.h>
#include <stdio.h>

void initQueue(CircularQueue *queue, int size) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int *)malloc(size * sizeof(int));
    if (queue->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void enqueue(CircularQueue *queue, int item) {
    queue->rear++;
    if (queue->rear == queue->size) {
        queue->rear = 0;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->array[queue->rear] = item;
}

int dequeue(CircularQueue *queue, int *item) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    *item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
        if (queue->front == queue->size) {
            queue->front = 0;
        }
    }
    return 0;
}

void printQueue(CircularQueue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i++;
        if (i == queue->size) {
            i = 0;
        }
    }
    printf("%d\n", queue->array[i]);
}
