#ifndef TREE_H
#define TREE_H

struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *create_tree_from_array(int arr[], int n, int i);

void tree_traverse_pre_order(struct tree_node *node);
void tree_traverse_post_order(struct tree_node *node);
void tree_traverse_in_order(struct tree_node *node);

void tree_traverse_breadth_first(struct tree_node *node);

#endif
