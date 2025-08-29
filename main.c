#include "binary_tree.h"
#include "common.h"
#include <stdio.h>

int main() {
  binary_tree_t a = create_binary_tree();
  a.root = create_tree_node(
      0,
      create_tree_node(0, 0, 0, 3),
      create_tree_node(0, 0, 0, 0x45),
      5
      );
  a.size = 3;
  binary_tree_t b = create_binary_tree();
  b.root = create_tree_node(
      0,
      create_tree_node(0, 0, 0, 3),
      create_tree_node(0, 0, 0, 0x45),
      5
      );
  b.size = 3;
  printf("%s\n", tree_comparison(&a, &b) ? "true" : "false");
}
