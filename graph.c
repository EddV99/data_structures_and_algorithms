#include "graph.h"
#include "array_list.h"
#include "heap.h"
#include "queue.h"

#include <stddef.h>
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

static int graph_dfs_helper(graph_t *graph, size_t at, size_t target,
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
  int visited[graph->vertex_count] = {};
  for (size_t i = 0; i < graph->vertex_count; i++)
    visited[i] = 0;
  if (graph_dfs_helper(graph, from, to, result, visited)) {
    array_list_insert(result, 0, (void *)from);
  }
  return result;
}

static array_list_t *prev_path(size_t *prev, size_t index) {
  array_list_t *result = array_list_new();
  while (index != ((size_t)-1)) {
    array_list_insert(result, 0, (void *)index);
    index = prev[index];
  }

  return result;
}

array_list_t *graph_bfs(graph_t *graph, size_t from, size_t to) {
  size_t prev[graph->vertex_count] = {};
  int visited[graph->vertex_count] = {};
  for (size_t i = 0; i < graph->vertex_count; i++) {
    visited[i] = 0;
    prev[i] = -1;
  }

  queue_t queue = queue_create();
  queue_enqueue(&queue, (void *)from);
  visited[from] = 1;

  while (queue.size > 0) {
    size_t at = (size_t)queue_peek(&queue);
    queue_dequeue(&queue);
    if (at == to) {
      break;
    }

    for (size_t i = 0; i < graph->edges[at].size; i++) {
      edge_t *edge = (edge_t *)array_list_get(&graph->edges[at], i);
      if (visited[edge->to]) {
        continue;
      }
      visited[edge->to] = 1;
      prev[edge->to] = at;
      queue_enqueue(&queue, (void *)edge->to);
    }
  }

  return prev_path(prev, to);
}

typedef struct {
  size_t vertex;
  size_t dist;
} vertex_dist_t;

static vertex_dist_t *vertex_dist_create(size_t vertex, size_t dist) {
  vertex_dist_t *node = malloc(sizeof(vertex_dist_t));
  node->vertex = vertex;
  node->dist = dist;
  return node;
}

static int MIN_HEAP_NODE_WITH_WEIGHT(void *a, void *b) {
  return ((vertex_dist_t *)a)->dist - ((vertex_dist_t *)b)->dist;
}

array_list_t *graph_find_shortest_path(graph_t *graph, size_t from, size_t to) {
  size_t prev[graph->vertex_count] = {};
  size_t dists[graph->vertex_count] = {};

  for (size_t i = 0; i < graph->vertex_count; i++) {
    prev[i] = -1;
    dists[i] = -1;
  }

  dists[from] = 0;
  heap_t heap = heap_create(MIN_HEAP_NODE_WITH_WEIGHT);
  heap_insert(&heap, vertex_dist_create(from, 0));

  while (heap_has(&heap)) {
    vertex_dist_t *u = heap_peek(&heap);
    heap_delete(&heap);

    for (size_t i = 0; i < graph->edges[u->vertex].size; i++) {
      edge_t *v = (edge_t *)array_list_get(&graph->edges[u->vertex], i);
      if (dists[u->vertex] != (size_t)-1) {
        size_t alt = dists[u->vertex] + v->weight;
        if (alt < dists[v->to]) {
          prev[v->to] = u->vertex;
          dists[v->to] = alt;
          heap_insert(&heap, vertex_dist_create(v->to, alt));
        }
      }
    }
  }

  return prev_path(prev, to);
}
