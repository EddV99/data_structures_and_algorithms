#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
  size_t capacity;
  size_t size;
  void **values;
} array_list_t;

array_list_t array_list_create();

void array_list_push_back(array_list_t *array, void *value);
void array_list_insert(array_list_t *array, size_t index, void *value);

void *array_list_pop_back(array_list_t *array);
void *array_list_remove(array_list_t *array, size_t index);

void *array_list_get(array_list_t *array, size_t index);

void array_list_print_int(array_list_t *array);

#endif
