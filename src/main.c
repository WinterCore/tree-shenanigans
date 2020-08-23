#include <stdio.h>

#include "tree.h"
#include "arr-min-heap.h"

int main() {
    // int arr[] = {10, 1, 2, 3, 4, 5, 6};
    // int n     = sizeof(arr) / sizeof(arr[0]);

    // struct tree_node *node = create_tree_from_array(arr, n, 0);

    // tree_traverse_breadth_first(node);


    // struct heap *heap = min_heap_create();

    // min_heap_insert(heap, 10);
    // min_heap_insert(heap, 5);
    // min_heap_insert(heap, 2);
    // min_heap_insert(heap, 1);

    // printf("%d\n", min_heap_extract(heap));
    // printf("%d\n", heap->head->value);
    // printf("%d\n", heap->head->left->value);
    // printf("%d\n", heap->head->right->value);


    struct arr_heap *heap = arr_min_heap_create(40);

    arr_min_heap_insert(heap, 7);
    arr_min_heap_insert(heap, 6);
    arr_min_heap_insert(heap, 6);
    arr_min_heap_insert(heap, 5);
    arr_min_heap_insert(heap, 2);
    arr_min_heap_insert(heap, 1);
    arr_min_heap_insert(heap, 1);
    arr_min_heap_insert(heap, 1);

    for (int i = 0; i < heap->size; i += 1) {
        printf("%d - ", heap->arr[i]);
    }

    return 0;
}
