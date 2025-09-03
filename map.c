#include "map.h"
#include "array_list.h"
#include "linked_list.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

map_t map_create(size_t capacity) {
  array_list_t *buckets = array_list_new();
  for (size_t i = 0; i < capacity; i++) {
    array_list_push_back(buckets, linked_list_new());
  }
  map_t map = {
      .capacity = capacity,
      .size = 0,
      .buckets = buckets,
  };
  return map;
}

map_t *map_new(size_t capacity) {
  array_list_t *buckets = array_list_new();
  for (size_t i = 0; i < capacity; i++) {
    array_list_push_back(buckets, linked_list_new());
  }
  map_t *map = malloc(sizeof(map_t));
  map->capacity = capacity;
  map->size = 0;
  map->buckets = buckets;
  return map;
}

void map_free(map_t *map) {
  if (map) {
    for (size_t i = 0; i < map->buckets->size; i++) {
      linked_list_t *bucket = array_list_get(map->buckets, i);
      for (size_t j = 0; j < bucket->size; j++) {
        free(linked_list_get(bucket, j));
      }
      free(bucket);
    }
  }
}

static size_t hash(const char *key) {
  // FNV-1 hash
  size_t hash = 0xcbf29ce484222325;
  while (key[0]) {
    hash *= 0x100000001b3;
    hash ^= key[0];
    key++;
  }
  return hash;
}

struct key_value {
  const char *key;
  void *value;
};
static struct key_value *key_value_new(const char *key, void *value) {
  struct key_value *kv = malloc(sizeof(struct key_value));
  kv->key = key;
  kv->value = value;
  return kv;
}

static struct key_value *get_key_helper(map_t *map, const char *key) {
  size_t index = hash(key) % map->capacity;
  linked_list_t *bucket = array_list_get(map->buckets, index);
  for (size_t i = 0; i < bucket->size; i++) {
    struct key_value *kv = linked_list_get(bucket, i);
    if (strcmp(kv->key, key) == 0) {
      return kv;
    }
  }
  return 0;
}

void *map_get(map_t *map, const char *key) {
  struct key_value *kv = get_key_helper(map, key);
  if (kv) {
    return kv->value;
  }
  return 0;
}

void map_set(map_t *map, const char *key, void *value) {
  struct key_value *kv = get_key_helper(map, key);
  if (kv) {
    kv->value = value;
  } else {
    size_t index = hash(key) % map->capacity;
    linked_list_t *bucket = array_list_get(map->buckets, index);
    linked_list_append(bucket, key_value_new(key, value));
  }
}

int map_has(map_t *map, const char *key) {
  return get_key_helper(map, key) != 0;
}

void map_remove(map_t *map, const char *key) {
  if (map_has(map, key)) {
    size_t index = hash(key) % map->capacity;
    linked_list_t *bucket = array_list_get(map->buckets, index);
    for (size_t i = 0; i < bucket->size; i++) {
      struct key_value *kv = linked_list_get(bucket, i);
      if (strcmp(kv->key, key) == 0) {
        linked_list_remove_at(bucket, i);
      }
    }
  }
}
