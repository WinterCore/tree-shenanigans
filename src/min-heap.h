#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdbool.h>

struct heap {
    int size;
    struct heap_node *head;
};

struct heap_node {
    int value;
    struct heap_node *parent;
    struct heap_node *left;
    struct heap_node *right;
};

struct heap *min_heap_create();
struct heap_node *min_heap_get_node(struct heap *heap, int i);

void min_heapify(struct heap *heap, struct heap_node *node);
void reverse_min_heapify(struct heap *heap, struct heap_node *node);
void min_heap_insert(struct heap *heap, int value);
int min_heap_peek(struct heap *heap);
int min_heap_extract(struct heap *heap);
bool min_heap_empty(struct heap *heap);

#endif
