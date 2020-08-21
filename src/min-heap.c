#include <stdio.h>
#include <stdlib.h>

#include "min-heap.h"

struct heap *min_heap_create() {
    struct heap *heap = malloc(sizeof(struct heap));
    heap->size = 0;
    heap->head = NULL;
    if (heap == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return heap;
}

struct heap_node *min_heap_get_node(struct heap *heap, int i) {
    if (i == 1) {
        return heap->head;
    } else {
        int b = i;

        while (b & (b - 1)) b &= b - 1;

        b >>= 1;

        struct heap_node *node = heap->head;

        while (b) {
            if (i & b) {
                node = node->right;
            } else {
                node = node->left;
            }

            b >>= 1;
        }

        return node;
    }
}

void min_heapify(struct heap *heap, struct heap_node *node) {
    if (node->parent) {
        if (node->value < node->parent->value) {
            // Swap values as there's no point in swapping nodes
            int temp = node->value;
            node->value = node->parent->value;
            node->parent->value = temp;
            min_heapify(heap, node->parent);
        }
    }
}

void reverse_min_heapify(struct heap *heap, struct heap_node *node) {
    struct heap_node *lowest = node;
    if (node->left && node->left->value < node->value) {
        lowest = node->left;
    } else if (node->right && node->right->value < node->value) {
        lowest = node->right;
    }

    if (lowest != node) {
        int temp = node->value;
        node->value = lowest->value;
        lowest->value = temp;

        reverse_min_heapify(heap, lowest);
    }
}

bool min_heap_empty(struct heap *heap) {
    return heap->size == 0;
}

int min_heap_peek(struct heap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "The min heap is empty.");
        exit(EXIT_FAILURE);
    }
    return heap->head->value;
}

int min_heap_extract(struct heap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "The min heap is empty.");
        exit(EXIT_FAILURE);
    }

    int value = heap->head->value;
    struct heap_node *last = min_heap_get_node(heap, heap->size);

    if (heap->size % 2 == 0) {
        last->parent->left = NULL;
    } else {
        last->parent->right = NULL;
    }
    last->left = heap->head->left;
    last->right = heap->head->right;
    free(heap->head);
    heap->head = last;
    reverse_min_heapify(heap, last);

    return value;
}

void min_heap_insert(struct heap *heap, int value) {
    struct heap_node *new_node = malloc(sizeof (struct heap_node));
    new_node->value = value;
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    struct heap_node *parent = min_heap_get_node(heap, (heap->size + 1) / 2);
    if (parent == NULL) {
        heap->head = new_node;
    } else {
        if ((heap->size + 1) & 1) {
            parent->right = new_node;
        } else {
            parent->left = new_node;
        }
        new_node->parent = parent;
    }
    heap->size += 1;
    min_heapify(heap, new_node);
}
