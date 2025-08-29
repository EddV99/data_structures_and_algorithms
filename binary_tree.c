#include "binary_tree.h"
#include "common.h"
#include "queue.h"

#include <stdlib.h>

tree_node_t *create_tree_node(tree_node_t *parent, tree_node_t *left,
                              tree_node_t *right, int value) {
  tree_node_t *node = malloc(sizeof(tree_node_t));
  node->parent = parent;
  node->left = left;
  node->right = right;
  node->value = value;
  return node;
}

binary_tree_t create_binary_tree() {
  binary_tree_t tree = {
      .root = 0,
      .size = 0,
  };
  return tree;
}

int *bfs(binary_tree_t *tree) {
  int *result = 0;
  if (tree->root) {
    result = malloc(sizeof(tree->root->value) * tree->size);
    int index = 0;

    queue_t q = create_queue();
    queue_enqueue(&q, tree->root);
    while (q.size) {
      tree_node_t *node = queue_peek(&q);
      queue_dequeue(&q);

      if (node->left) {
        queue_enqueue(&q, node->left);
      }
      if (node->right) {
        queue_enqueue(&q, node->right);
      }

      result[index] = node->value;
      index++;
    }
  }
  return result;
}

void pre_order_traversal_helper(tree_node_t *node, int *array, int *index) {
  if (node == 0)
    return;

  array[*index] = node->value;
  (*index)++;
  pre_order_traversal_helper(node->left, array, index);
  pre_order_traversal_helper(node->right, array, index);
}

void in_order_traversal_helper(tree_node_t *node, int *array, int *index) {
  if (node == 0)
    return;

  in_order_traversal_helper(node->left, array, index);
  array[*index] = node->value;
  (*index)++;
  in_order_traversal_helper(node->right, array, index);
}

void post_order_traversal_helper(tree_node_t *node, int *array, int *index) {
  if (node == 0)
    return;

  post_order_traversal_helper(node->left, array, index);
  post_order_traversal_helper(node->right, array, index);
  array[*index] = node->value;
  (*index)++;
}

int *pre_order_traversal(binary_tree_t *tree) {
  int *result = 0;
  if (tree->root) {
    result = malloc(sizeof(tree->root->value) * tree->size);
    int index = 0;
    pre_order_traversal_helper(tree->root, result, &index);
  }
  return result;
}

int *in_order_traversal(binary_tree_t *tree) {
  int *result = 0;
  if (tree->root) {
    result = malloc(sizeof(tree->root->value) * tree->size);
    int index = 0;
    in_order_traversal_helper(tree->root, result, &index);
  }
  return result;
}

int *post_order_traversal(binary_tree_t *tree) {
  int *result = 0;
  if (tree->root) {
    result = malloc(sizeof(tree->root->value) * tree->size);
    int index = 0;
    post_order_traversal_helper(tree->root, result, &index);
  }
  return result;
}

void print_pre_order_traversal(binary_tree_t *tree) {
  int *array = pre_order_traversal(tree);
  if (array) {
    print_array(array, tree->size);
    free(array);
  }
}

void print_in_order_traversal(binary_tree_t *tree) {
  int *array = in_order_traversal(tree);
  if (array) {
    print_array(array, tree->size);
    free(array);
  }
}

void print_post_order_traversal(binary_tree_t *tree) {
  int *array = post_order_traversal(tree);
  if (array) {
    print_array(array, tree->size);
    free(array);
  }
}
