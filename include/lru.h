#ifndef LRU_H
#define LRU_H

#include "map.h"
#include <stddef.h>

typedef struct lru_node_t {
  const char *key;
  void *value;
  struct lru_node_t *next;
  struct lru_node_t *prev;
} lru_node_t;

lru_node_t lru_node_create(const char *key, void *value, lru_node_t *next,
                           lru_node_t *prev);
lru_node_t *lru_node_new(const char *key, void *value, lru_node_t *next,
                         lru_node_t *prev);
void lru_node_free(lru_node_t *node);

typedef struct {
  map_t lookup;
  lru_node_t *head;
  lru_node_t *tail;
} lru_t;

lru_t lru_create(size_t capacity);
lru_t *lru_new(size_t capacity);
void lru_free(lru_t *lru);

void *lru_get(lru_t *lru, const char *key);

void lru_update(lru_t *lru, const char *key, void *value);

#endif
