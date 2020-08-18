#ifndef QUEUE_H
#define QUEUE_H

struct queue_node {
    int value;
    struct queue_node *next;
};

struct queue {
    struct queue_node *head;
    struct queue_node *tail;
};

struct queue *create_queue();

void enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
int peek(struct queue *queue);

#endif
