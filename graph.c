#include "graph.h"
#include "array_list.h"
#include "queue.h"

#include <stdlib.h>

edge_t edge_create(size_t to, float weight) {
  edge_t edge = {.to = to, .weight = weight};
  return edge;
}

edge_t *edge_new(size_t to, float weight) {
  edge_t *edge = malloc(sizeof(edge_t));
  edge->to = to;
  edge->weight = weight;
  return edge;
}

graph_t graph_create(int vertex_count, unsigned char is_directed) {
  array_list_t *edges = malloc(sizeof(array_list_t) * vertex_count);
  for (int i = 0; i < vertex_count; i++) {
    edges[i] = array_list_create();
  }

  graph_t graph = {
      .edges = edges,
      .vertex_count = vertex_count,
      .is_directed = is_directed,

  };
  return graph;
}

void graph_free(graph_t *graph) {
  for (size_t i = 0; i < graph->vertex_count; i++) {
    for (size_t j = 0; j < graph->edges[i].size; j++) {
      free(array_list_pop_back(&graph->edges[i]));
    }
  }
  free(graph);
}

void graph_add_edge(graph_t *graph, size_t from, size_t to, float weight) {
  array_list_push_back(&graph->edges[from], edge_new(to, weight));
  if (!graph->is_directed) {
    array_list_push_back(&graph->edges[to], edge_new(from, weight));
  }
}

int graph_dfs_helper(graph_t *graph, size_t at, size_t target,
                     array_list_t *result, int *visited) {
  if (at == target) {
    return 1;
  }

  for (size_t i = 0; i < graph->edges[at].size; i++) {
    edge_t *edge = (edge_t *)array_list_get(&graph->edges[at], i);
    if (!visited[edge->to]) {
      array_list_push_back(result, (void *)edge->to);
      visited[edge->to] = 1;
      if (!graph_dfs_helper(graph, edge->to, target, result, visited)) {
        array_list_pop_back(result);
      } else {
        return 1;
      }
    }
  }

  return 0;
}

array_list_t *graph_dfs(graph_t *graph, size_t from, size_t to) {
  array_list_t *result = array_list_new();
  int *visited = malloc(sizeof(int) * graph->vertex_count);
  for (size_t i = 0; i < graph->vertex_count; i++)
    visited[i] = 0;
  array_list_push_back(result, (void *)from);
  graph_dfs_helper(graph, from, to, result, visited);
  return result;
}

array_list_t *graph_bfs(graph_t *graph, size_t from, size_t to) {
  size_t* prev = malloc(sizeof(long) * graph->vertex_count);
  int *visited = malloc(sizeof(int) * graph->vertex_count);
  for (size_t i = 0; i < graph->vertex_count; i++){
    visited[i] = 0;
    prev[i] = -1;
  }

  queue_t queue = queue_create();
  queue_enqueue(&queue, (void*)from);
  visited[from] = 1;

  while(queue.size > 0) {
    size_t at = (size_t)queue_peek(&queue);
    queue_dequeue(&queue);
    if(at == to) {
      break;
    }

    for(size_t i = 0; i < graph->edges[at].size; i++) {
      edge_t *edge = (edge_t *)array_list_get(&graph->edges[at], i);
      if(visited[edge->to]) {
        continue;
      }
      visited[edge->to] = 1;
      prev[edge->to] = at;
      queue_enqueue(&queue, (void*)edge->to);
    }
  }

  long c = to;
  array_list_t *result = array_list_new();
  array_list_insert(result, 0, (void*)c);
  while(prev[c] != ((size_t)-1)) {
    array_list_insert(result, 0, (void*)prev[c]);
    c = prev[c];
  }
  return result;
}
