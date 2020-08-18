#include <stdio.h>

#include "tree.h"
#include "queue.h"

int main() {
    int arr[] = {10, 1, 2, 3, 4, 5, 6};
    int n     = sizeof(arr) / sizeof(arr[0]);

    struct tree_node *node = create_tree_from_array(arr, n, 0);

    tree_traverse_breadth_first(node);


    return 0;
}
