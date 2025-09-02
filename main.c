#include "array_list.h"
#include "graph.h"

#include <stdio.h>

int main() {
  graph_t graph = graph_create(8, 0);

  graph_add_edge(&graph, 0, 1, 0);
  graph_add_edge(&graph, 0, 6, 0);

  graph_add_edge(&graph, 1, 2, 0);
  graph_add_edge(&graph, 1, 5, 0);

  graph_add_edge(&graph, 2, 3, 0);
  graph_add_edge(&graph, 2, 7, 0);
  graph_add_edge(&graph, 2, 4, 0);

  array_list_t *array = graph_dfs(&graph, 3, 6);

  array_list_print_size_t(array);

  array_list_t *array2 = graph_bfs(&graph, 3, 6);
  array_list_print_size_t(array2);
}
