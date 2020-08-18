#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct queue *create_queue() {
    struct queue *queue = malloc(sizeof(struct queue));

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
};

struct queue *create_queue_from_array(void *arr, size_t size, size_t n) {
    struct queue *queue = create_queue();

    char *carr = arr;

    for (int i = 0; i < n; i += 1) {
        enqueue(queue, carr + i * size);
    }
    return queue;
}

void enqueue(struct queue *queue, void *value) {
    struct queue_node *node = malloc(sizeof(struct queue_node));
    node->value = value;
    node->next  = NULL;

    if (queue->head == NULL || queue->tail == NULL) {
        queue->head = queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

void *dequeue(struct queue *queue) {
    if (queue->head == NULL) {
        printf("Error: The queue is empty");
        exit(EXIT_FAILURE);
    }

    void *value = queue->head->value;
    struct queue_node *next_node = queue->head->next;
    free(queue->head);
    queue->head = next_node;

    return value;
}

void *queue_peek(struct queue *queue) {
    if (queue->head == NULL) {
        printf("Error: The queue is empty");
        exit(EXIT_FAILURE);
    }
    return queue->head->value;
}

bool is_queue_empty(struct queue *queue) {
    return queue->head == NULL || queue->tail == NULL;
}
