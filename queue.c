#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_LENGTH 10

typedef struct  {
    int array[QUEUE_LENGTH];
    int head;
    int tail;
} queue_t;

queue_t *newqueue() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = queue->tail = -1;
    return queue;
}

bool enqueue(queue_t *queue, int value) {
    if (queue->tail == QUEUE_LENGTH - 1) return false;
    if (queue->head == -1) queue->head++;
    queue->array[++queue->tail] = value;
    return true;
}

int dequeue(queue_t *queue) {
    if (queue->head == -1) return INT_MIN;
    int head = queue->array[queue->head++];
    if (queue->head > queue->tail) queue->head = queue->tail = -1;
    return head;
}

void printqueue(queue_t *queue) {
    for (int i = queue->head; i <= queue->tail; i++)
        printf("%d ", queue->array[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    queue_t *queue = newqueue();
    enqueue(queue, 5);
    enqueue(queue, 8);
    enqueue(queue, 1);
    int head = dequeue(queue);
    printf("Head = %d\n", head);
    printqueue(queue);
}
