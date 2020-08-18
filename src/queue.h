#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct queue_node {
    void *value;
    struct queue_node *next;
};

struct queue {
    struct queue_node *head;
    struct queue_node *tail;
};

struct queue *create_queue();
struct queue *create_queue_from_array();

void enqueue(struct queue *queue, void *value);
void *dequeue(struct queue *queue);
void *queue_peek(struct queue *queue);
bool is_queue_empty(struct queue *queue);

#endif
