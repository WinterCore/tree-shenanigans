#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "queue.h"

struct tree_node *create_tree_from_array(int arr[], int n, int i) {
    if (i >= n || arr[i] == 0) return NULL;

    struct tree_node *new_node = malloc(sizeof(struct tree_node));

    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    new_node->value = arr[i];
    new_node->left  = create_tree_from_array(arr, n, i * 2 + 1);
    new_node->right  = create_tree_from_array(arr, n, i * 2 + 2);

    return new_node;
}

void tree_traverse_pre_order(struct tree_node *node) {
    if (node == NULL) return;

    printf("%d\n", node->value);
    tree_traverse_pre_order(node->left);
    tree_traverse_pre_order(node->right);
}

void tree_traverse_post_order(struct tree_node *node) {
    if (node == NULL) return;

    tree_traverse_post_order(node->left);
    tree_traverse_post_order(node->right);
    printf("%d\n", node->value);
}

void tree_traverse_in_order(struct tree_node *node) {
    if (node == NULL) return;

    tree_traverse_in_order(node->left);
    printf("%d\n", node->value);
    tree_traverse_in_order(node->right);
}

void tree_traverse_breadth_first(struct tree_node *node) {
    struct queue *queue = create_queue();

    enqueue(queue, node);

    while (!is_queue_empty(queue)) {
        struct tree_node *tn = dequeue(queue);

        if (tn->left != NULL) enqueue(queue, tn->left);
        if (tn->right != NULL) enqueue(queue, tn->right);
    }
}



