#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

typedef struct tree_node_t {
  struct tree_node_t *parent;
  struct tree_node_t *left;
  struct tree_node_t *right;
  int value;
} tree_node_t;

tree_node_t *create_tree_node(tree_node_t *parent, tree_node_t *left,
                              tree_node_t *right, int value);

typedef struct {
  tree_node_t *root;
  size_t size;
} binary_tree_t;

binary_tree_t create_binary_tree();

int *pre_order_traversal(binary_tree_t *tree);
int *in_order_traversal(binary_tree_t *tree);
int *post_order_traversal(binary_tree_t *tree);

void print_pre_order_traversal(binary_tree_t *tree);
void print_in_order_traversal(binary_tree_t *tree);
void print_post_order_traversal(binary_tree_t *tree);

#endif
