#include <stdio.h>
#include <stdlib.h>

#include "arr-min-heap.h"

struct arr_heap *arr_min_heap_create(int size) {
    struct arr_heap *heap = malloc(sizeof(struct arr_heap) + (sizeof(int) * size));
    heap->size = 0;
    heap->max  = size;

    for (int i = 0; i < size; i += 1) heap->arr[i] = 0;

    if (heap == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return heap;
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arr_min_heapify(struct arr_heap *heap, int i) {
    int parent = i % 2 ? (i - 1) / 2 : (i - 2) / 2;
    if (parent < 0) return;

    if (heap->arr[i] < heap->arr[parent]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent];
        heap->arr[parent] = temp;

        arr_min_heapify(heap, parent);
    }
}

void arr_reverse_min_heapify(struct arr_heap *heap, int i) {
    int left = i * 2 + 1, right = i * 2 + 2;
    if (left < heap->size && heap->arr[i] > heap->arr[left]) {
        swap(&heap->arr[left], &heap->arr[i]);
        arr_reverse_min_heapify(heap, left);
    } else if (right < heap->size && heap->arr[i] > heap->arr[right]) {
        swap(&heap->arr[right], &heap->arr[i]);
        arr_reverse_min_heapify(heap, right);
    }
}

void arr_min_heap_insert(struct arr_heap *heap, int value) {
    if (heap->max == heap->size) {
        fprintf(stderr, "The heap is full");
        exit(EXIT_FAILURE);
    }

    heap->arr[heap->size]  = value;
    arr_min_heapify(heap, heap->size);
    heap->size            += 1;
}


int arr_min_heap_peek(struct arr_heap *heap) {
    return heap->arr[0];
}

int arr_min_heap_extract(struct arr_heap *heap) {
    int value = heap->arr[0];
    heap->size -= 1;
    heap->arr[0] = heap->arr[heap->size];
    arr_reverse_min_heapify(heap, 0);
    return value;
}
