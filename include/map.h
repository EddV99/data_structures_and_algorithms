#ifndef MAP_H
#define MAP_H

#include "array_list.h"
#include <stddef.h>

typedef struct {
  size_t size;
  size_t capacity;
  array_list_t* buckets;
} map_t;

map_t map_create(size_t capacity);
map_t* map_new(size_t capacity);

void* map_get(map_t* map, const char* key);
void map_set(map_t* map, const char* key, void* value);
int map_has(map_t* map, const char* key);

#endif
