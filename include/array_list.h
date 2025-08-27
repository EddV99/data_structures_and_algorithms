#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
  size_t capacity;
  size_t size;
  int *values;
} array_list_t;

array_list_t create_array_list();

void push_back_array_list(array_list_t *array, int value);
void push_at_array_list(array_list_t *array, size_t index, int value);

int pop_back_array_list(array_list_t *array);
int pop_at_array_list(array_list_t *array, size_t index);

int get_array_list(array_list_t *array, size_t index);

void print_array_list(array_list_t *array);

#endif
