#include "binary_search_tree.h"
#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

bst_t create_bst() {
  bst_t bst = create_binary_tree();
  return bst;
}

void bst_insert_helper(tree_node_t *node, int value) {
  if (value <= node->value) {
    if (node->left) {
      bst_insert_helper(node->left, value);
    } else {
      node->left = create_tree_node(node, 0, 0, value);
    }
  } else {
    if (node->right) {
      bst_insert_helper(node->right, value);
    } else {
      node->right = create_tree_node(node, 0, 0, value);
    }
  }
}

void bst_insert(bst_t *bst, int value) {
  if (bst->root) {
    bst_insert_helper(bst->root, value);
  } else {
    bst->root = create_tree_node(0, 0, 0, value);
  }
}

int bst_find_helper(tree_node_t *node, int target) {
  if (!node) {
    return 0;
  }
  if (node->value == target) {
    return 1;
  }
  if (node->value > target) {
    return bst_find_helper(node->left, target);
  }
  return bst_find_helper(node->right, target);
}

int bst_find(bst_t *bst, int target) {
  return bst_find_helper(bst->root, target);
}

void bst_delete_helper(tree_node_t *node, int target) {
  if (!node) {
    return;
  }
  if (node->value == target) {
    if (!node->left && !node->right) {
      tree_node_t *parent = node->parent;
      if (parent->left == node) {
        parent->left = 0;
      } else {
        parent->right = 0;
      }
      free(node);
    } else if (!node->left || !node->right) {
      tree_node_t *move = node->left ? node->left : node->right;
      tree_node_t *parent = node->parent;
      if (parent->left == node) {
        parent->left = move;
      } else {
        parent->right = move;
      }
      free(node);
    } else {
      tree_node_t *parent = node->parent;
      tree_node_t *move = node->left;
      while (move->right) {
        move = move->right;
      }

      if (move->parent->left == move) {
        move->parent->left = 0;
      } else {
        move->parent->right = 0;
      }

      move->right = node->right;
      move->left = node->left;
      if (parent->left == node) {
        parent->left = move;
      } else {
        parent->right = move;
      }

      free(node);
    }
  }
  if (node->value > target) {
    return bst_delete_helper(node->left, target);
  }
  return bst_delete_helper(node->right, target);
}

void bst_delete(bst_t *bst, int target) {
  if (bst->root) {
    bst_delete_helper(bst->root, target);
  }
}

void bst_print_helper(char *prefix, int size, const tree_node_t *node,
                      bool is_left) {
  if (node != nullptr) {
    printf("%s", prefix);
    printf("%s", is_left ? "├──" : "└──");
    printf("%d\n", node->value);

    int byte_count = sizeof(char) * (size + 4);
    char *new_prefix = malloc(byte_count);
    if (is_left) {
      snprintf(new_prefix, byte_count, "%s%s", prefix, "│   ");
    } else {
      snprintf(new_prefix, byte_count, "%s%s", prefix, "    ");
    }
    bst_print_helper(new_prefix, size + 4, node->left, true);
    bst_print_helper(new_prefix, size + 4, node->right, false);
    free(new_prefix);
  }
}

void bst_print(const bst_t *bst) {
  char *prefix = malloc(sizeof(char) * 1);
  prefix[0] = '\0';
  bst_print_helper(prefix, 1, bst->root, false);
  free(prefix);
}
