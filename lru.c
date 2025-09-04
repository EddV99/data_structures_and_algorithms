#include "lru.h"
#include "map.h"

#include <stdlib.h>

lru_node_t lru_node_create(const char *key, void *value, lru_node_t *next,
                           lru_node_t *prev) {
  lru_node_t node = {
      .key = key,
      .value = value,
      .next = next,
      .prev = prev,
  };
  return node;
}

lru_node_t *lru_node_new(const char *key, void *value, lru_node_t *next,
                         lru_node_t *prev) {
  lru_node_t *node = malloc(sizeof(lru_node_t));
  node->key = key;
  node->value = value;
  node->next = next;
  node->prev = prev;
  return node;
}

void lru_node_free(lru_node_t *node) {
  if (node) {
    free(node);
  }
}

lru_t lru_create(size_t capacity) {
  lru_t lru = {
      .lookup = map_create(capacity),
      .head = 0,
      .tail = 0,
  };
  return lru;
}

lru_t *lru_new(size_t capacity) {
  lru_t *lru = malloc(sizeof(lru_t));
  lru->lookup = map_create(capacity);
  lru->head = 0;
  lru->tail = 0;
  return lru;
}

void lru_free(lru_t *lru) {
  if (lru) {
  }
}

static void lru_move_to_front_helper(lru_t *lru, lru_node_t *node) {
  if (node == lru->head) {
    return;
  }

  if (node == lru->tail) {
    lru->tail = node->prev;
  }

  if (node->prev) {
    node->prev->next = node->next;
  }

  if (node->next) {
    node->next->prev = node->prev;
  }

  node->next = lru->head;
  node->prev = 0;

  lru->head->prev = node;
  lru->head = node;
}

void *lru_get(lru_t *lru, const char *key) {
  lru_node_t *node = map_get(&lru->lookup, key);
  if (node) {
    lru_move_to_front_helper(lru, node);
    return node->value;
  }

  return 0;
}

void lru_update(lru_t *lru, const char *key, void *value) {
  lru_node_t *node = map_get(&lru->lookup, key);
  if (node) {
    lru_move_to_front_helper(lru, node);
    node->value = value;
  } else {
    node = lru_node_new(key, value, 0, 0);
    lru_move_to_front_helper(lru, node);

    if (lru->lookup.size + 1 > lru->lookup.capacity) {
      lru_node_t *r = lru->tail;
      r->prev->next = 0;
      lru->tail = r->prev;
      r->prev = 0;
      map_remove(&lru->lookup, r->key);
    }

    map_set(&lru->lookup, key, node);
  }
}
