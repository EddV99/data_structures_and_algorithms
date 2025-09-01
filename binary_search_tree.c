#include "binary_search_tree.h"
#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

bst_t bst_create(int (*comparator)(void *, void *)) {
  binary_tree_t *tree = malloc(sizeof(binary_tree_t));
  tree->root = 0;
  tree->size = 0;
  bst_t bst = {
      .tree = tree,
      .comparator = comparator,
  };
  return bst;
}

void bst_free(bst_t *bst) {
  if (bst) {
    binary_tree_free(bst->tree);
    free(bst);
  }
}

void bst_insert_helper(bst_t *bst, tree_node_t *node, void *value) {
  if (bst->comparator(value, node->value) < 0) {
    if (node->left) {
      bst_insert_helper(bst, node->left, value);
    } else {
      node->left = tree_node_create(node, 0, 0, value);
    }
  } else {
    if (node->right) {
      bst_insert_helper(bst, node->right, value);
    } else {
      node->right = tree_node_create(node, 0, 0, value);
    }
  }
}

void bst_insert(bst_t *bst, void *value) {
  if (bst->tree->root) {
    bst_insert_helper(bst, bst->tree->root, value);
  } else {
    bst->tree->root = tree_node_create(0, 0, 0, value);
  }
}

int bst_find_helper(bst_t *bst, tree_node_t *node, void *target) {
  if (!node) {
    return 0;
  }
  if (node->value == target) {
    return 1;
  }
  if (bst->comparator(target, node->value) < 0) {
    return bst_find_helper(bst, node->left, target);
  }
  return bst_find_helper(bst, node->right, target);
}

int bst_find(bst_t *bst, void *target) {
  return bst_find_helper(bst, bst->tree->root, target);
}

void bst_delete_helper(bst_t *bst, tree_node_t *node, void *target) {
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
  } else if (bst->comparator(target, node->value) < 0) {
    return bst_delete_helper(bst, node->left, target);
  } else {
    return bst_delete_helper(bst, node->right, target);
  }
}

void bst_delete(bst_t *bst, void *target) {
  if (bst->tree->root) {
    bst_delete_helper(bst, bst->tree->root, target);
  }
}

void bst_print_helper_int(char *prefix, int size, const tree_node_t *node,
                          bool is_left) {
  if (node != nullptr) {
    printf("%s", prefix);
    printf("%s", is_left ? "├──" : "└──");
    printf("%d\n", (int)node->value);

    int byte_count = sizeof(char) * (size + 4);
    char *new_prefix = malloc(byte_count);
    if (is_left) {
      snprintf(new_prefix, byte_count, "%s%s", prefix, "│   ");
    } else {
      snprintf(new_prefix, byte_count, "%s%s", prefix, "    ");
    }
    bst_print_helper_int(new_prefix, size + 4, node->left, true);
    bst_print_helper_int(new_prefix, size + 4, node->right, false);
    free(new_prefix);
  }
}

void bst_print_int(const bst_t *bst) {
  char *prefix = malloc(sizeof(char) * 1);
  prefix[0] = '\0';
  bst_print_helper_int(prefix, 1, bst->tree->root, false);
  free(prefix);
}
