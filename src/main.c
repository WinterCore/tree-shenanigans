#include <stdio.h>

#include "tree.h"

int main() {
    int arr[] = {10, 1, 2, 3, 4, 5, 6};

    struct tree_node *node = create_tree_from_array(arr, sizeof(arr) / sizeof(arr[0]), 0);

    tree_traverse_in_order(node);

    return 0;
}
