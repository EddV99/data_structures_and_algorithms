#ifndef GRAPH_H
#define GRAPH_H

#include "array_list.h"

#include <stddef.h>

typedef struct {
  size_t to;
  float weight;
} edge_t;

edge_t edge_create(size_t to, float weight);
edge_t *edge_new(size_t to, float weight);

typedef struct {
  array_list_t *edges;
  size_t vertex_count;
  unsigned char is_directed;
} graph_t;

graph_t graph_create(int vertex_count, unsigned char is_directed);
void graph_free(graph_t *graph);

void graph_add_edge(graph_t *graph, size_t from, size_t to, float weight);

array_list_t *graph_dfs(graph_t *graph, size_t from, size_t to);
array_list_t *graph_bfs(graph_t *graph, size_t from, size_t to);
array_list_t *graph_find_shortest_path(graph_t *graph, size_t from, size_t to);

#endif
