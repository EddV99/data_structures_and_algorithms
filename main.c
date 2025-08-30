#include "binary_search_tree.h"
#include "common.h"
#include <stdio.h>

int int_asc(void *a, void *b) { return (int)a < (int)b; }

int main() {
  bst_t bst = bst_create(int_asc);
  bst_insert(&bst, (void *)8);
  bst_insert(&bst, (void *)3);
  bst_insert(&bst, (void *)10);
  bst_insert(&bst, (void *)1);
  bst_insert(&bst, (void *)6);
  bst_insert(&bst, (void *)4);
  bst_insert(&bst, (void *)7);
  bst_insert(&bst, (void *)14);
  bst_insert(&bst, (void *)13);

  bst_print_int(&bst);

  bst_delete(&bst, (void *)6);
  bst_print_int(&bst);
}
