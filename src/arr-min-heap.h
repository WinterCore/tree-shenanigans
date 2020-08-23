#ifndef ARR_MIN_HEAP_H
#define ARR_MIN_HEAP_H

#include <stdbool.h>

struct arr_heap {
    int size;
    int max;
    int arr[];
};

struct arr_heap *arr_min_heap_create(int size);

void arr_min_heapify(struct arr_heap *heap, int i);
void arr_reverse_min_heapify(struct arr_heap *heap, int i);
void arr_min_heap_insert(struct arr_heap *heap, int value);
int arr_min_heap_peek(struct arr_heap *heap);
int arr_min_heap_extract(struct arr_heap *heap);
bool arr_min_heap_empty(struct arr_heap *heap);

#endif
