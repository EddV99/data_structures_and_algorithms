#include "array_list.h"
#include "graph.h"

#include <stdio.h>

int main() {
  graph_t graph = graph_create(5, 1);

  graph_add_edge(&graph, 0, 1, 1);
  graph_add_edge(&graph, 0, 2, 5);

  graph_add_edge(&graph, 1, 2, 7);
  graph_add_edge(&graph, 1, 3, 3);

  graph_add_edge(&graph, 2, 4, 1);

  graph_add_edge(&graph, 3, 2, 1);
  graph_add_edge(&graph, 3, 1, 1);

  size_t from = 0;
  size_t to = 4;
  array_list_t *array = graph_dfs(&graph, from, to);
  array_list_print_size_t(array);

  array_list_t *array2 = graph_bfs(&graph, from, to);
  array_list_print_size_t(array2);

  array_list_t *array3 = graph_find_shortest_path(&graph, from, to);
  array_list_print_size_t(array3);
}


