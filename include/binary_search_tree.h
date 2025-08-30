#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "binary_tree.h"

typedef struct {
  binary_tree_t *tree;
  int (*comparator)(void *, void *);
} bst_t;

bst_t bst_create(int (*comparator)(void *, void *));
void bst_free(bst_t *bst);

void bst_insert(bst_t *bst, void *value);
int bst_find(bst_t *bst, void *target);
void bst_delete(bst_t *bst, void *target);
void bst_print_int(const bst_t *bst);

#endif
