#include "array_list.h"
#include "common.h"

#include <string.h>

array_list_t *array_list_new() {
  array_list_t *array = malloc(sizeof(array_list_t));
  array->capacity = 1;
  array->size = 0;
  array->values = malloc(sizeof(void *));
  return array;
}

array_list_t array_list_create() {
  array_list_t array = {
      .capacity = 1,
      .size = 0,
      .values = malloc(sizeof(void *)),
  };

  return array;
}

void grow_internal_array(array_list_t *array) {
  size_t new_capacity = array->capacity * 2;
  void **new_array = malloc(sizeof(void *) * new_capacity);
  memcpy(new_array, array->values, sizeof(void *) * array->size);

  free(array->values);
  array->values = new_array;
  array->capacity = new_capacity;
}

void array_list_push_back(array_list_t *array, void *value) {
  if (array->size > array->capacity) {
    grow_internal_array(array);
  }

  array->values[array->size] = value;
  array->size++;
}

void array_list_insert(array_list_t *array, size_t index, void *value) {
  ASSERT(index <= array->size, "Array List: Index must be less than size");
  if (array->size > array->capacity) {
    grow_internal_array(array);
  }

  size_t i = index;
  void *next = array->values[i];
  void *now = value;

  while (i <= array->size) {
    array->values[i] = now;
    now = next;
    next = array->values[i + 1];
    i++;
  }

  array->size++;
}

void array_list_set(array_list_t *array, size_t index, void *value) {
  ASSERT(index < array->size, "Array List: Index must be less than size");
  array->values[index] = value;
}

void *array_list_pop_back(array_list_t *array) {
  ASSERT(array->size > 0, "Array List: Size must be greater than zero to pop");
  array->size--;
  return array->values[array->size];
}
void *array_list_remove(array_list_t *array, size_t index) {
  ASSERT(array->size > 0, "Array List: Size must be greater than zero to pop");
  ASSERT(index < array->size, "Array List: Index must be less than size");

  void *pop = array->values[index];

  for (size_t i = index; i < array->size - 1; i++) {
    array->values[i] = array->values[i + 1];
  }

  array->size--;
  return pop;
}

void *array_list_get(array_list_t *array, size_t index) {
  ASSERT(index < array->size, "Array List: Index must be less than size");

  return array->values[index];
}

void array_list_print_int(array_list_t *array) {
  array_print_int((int *)array->values, array->size);
}

void array_list_print_size_t(array_list_t *array) {
  array_print_size_t((size_t *)array->values, array->size);
}
