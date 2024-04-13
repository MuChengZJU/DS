#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
 * @struct CircularQueue
 * @brief A structure representing a circular queue, using an array.
 * 
 * The CircularQueue struct contains information about the rear, front, size, and array of the queue.
 */
typedef struct CircularQueue{
    int rear, front, size;
    int *array;
}CircularQueue;

/**
 * @brief Initalizes the queue with the given size. Font and Rear are init to -1.
 * 
 * @param queue The pointer to the queue to be initialized.
 * @param size The size of the queue, to input.
 */
void initQueue(CircularQueue *queue, int size);

void enqueue(CircularQueue *queue, int item);

int dequeue(CircularQueue *queue, int *item);

void printQueue(CircularQueue *queue);

#endif // _QUEUE_H_