#include "array_list.h"
#include "graph.h"

#include <stdio.h>

int main() {
  graph_t graph = graph_create(4, 1);
  graph_add_edge(&graph, 0, 3, 0);
  graph_add_edge(&graph, 0, 1, 0);
  graph_add_edge(&graph, 2, 0, 0);
  graph_add_edge(&graph, 3, 1, 0);
  graph_add_edge(&graph, 3, 2, 0);

  array_list_t *array = graph_dfs(&graph, 3, 0);
  array_list_print_size_t(array);
}
