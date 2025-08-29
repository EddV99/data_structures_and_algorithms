#include "binary_tree.h"
#include "common.h"
#include <stdio.h>

int main() {
  /*
   *             1
   *           /   \
   *          2     3
   *        /   \ /   \
   *       4   5  6   7
   *     /   \     \
   *    8    9     10
   */
  binary_tree_t tree = create_binary_tree();
  int pre_order[] = {1, 2, 4, 8, 9, 5, 3, 6, 10, 7};
  int in_order[] = {8, 4, 9, 2, 5, 1, 6, 10, 3, 7};
  int post_order[] = {8, 9, 4, 5, 2, 10, 6, 7, 3, 1};
  int bfs_order[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  tree.root = create_tree_node(
      0,
      create_tree_node(0,
                       create_tree_node(0, create_tree_node(0, 0, 0, 8),
                                        create_tree_node(0, 0, 0, 9), 4),
                       create_tree_node(0, 0, 0, 5), 2),
      create_tree_node(0,
                       create_tree_node(0, 0, create_tree_node(0, 0, 0, 10), 6),
                       create_tree_node(0, 0, 0, 7), 3),
      1);

  tree.size = 10;
  printf("pre order traversal\n");
  printf("by hand\n");
  print_array(pre_order, 10);
  printf("calculated\n");
  print_pre_order_traversal(&tree);

  printf("\nin order traversal\n");
  printf("by hand\n");
  print_array(in_order, 10);
  printf("calculated\n");
  print_in_order_traversal(&tree);

  printf("\npost order traversal\n");
  printf("by hand\n");
  print_array(post_order, 10);
  printf("calculated\n");
  print_post_order_traversal(&tree);

  printf("bfs traversal\n");
  printf("by hand\n");
  print_array(bfs_order, 10);
  printf("calculated\n");
  print_array(bfs(&tree), 10);
}
