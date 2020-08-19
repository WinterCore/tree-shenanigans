#ifndef MIN_HEAP_H
#define MIN_HEAP_H

struct heap_node {
    int value;
    struct heap_node *parent;
    struct heap_node *left;
    struct heap_node *right;
};

void min_heap_insert(struct heap_node *node, int value);
void min_heap_peek(struct heap_node *node);
int min_heap_extract(struct heap_node *node);

#endif
