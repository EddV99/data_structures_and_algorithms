#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "binary_tree.h"

typedef binary_tree_t bst_t;

bst_t create_bst();

void bst_insert(bst_t *bst, int value);
int bst_find(bst_t *bst, int target);
void bst_delete(bst_t *bst, int target);
void bst_print(const bst_t *bst);

#endif
