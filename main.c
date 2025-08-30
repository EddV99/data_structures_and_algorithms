#include "binary_search_tree.h"
#include "common.h"
#include <stdio.h>

int main() {
  bst_t bst = create_bst();
  bst_insert(&bst, 8);
  bst_insert(&bst, 3);
  bst_insert(&bst, 10);
  bst_insert(&bst, 1);
  bst_insert(&bst, 6);
  bst_insert(&bst, 4);
  bst_insert(&bst, 7);
  bst_insert(&bst, 14);
  bst_insert(&bst, 13);

  bst_print(&bst);

  bst_delete(&bst, 6);
  bst_print(&bst);
}
