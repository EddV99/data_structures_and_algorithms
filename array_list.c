#include "array_list.h"
#include "common.h"

#include <string.h>

array_list_t create_array_list() {
  array_list_t array = {
      .capacity = 1,
      .size = 0,
      .values = malloc(sizeof(int)),
  };

  return array;
}

void grow_internal_array(array_list_t *array) {
  size_t new_capacity = array->capacity * 2;
  int *new_array = malloc(sizeof(int) * new_capacity);
  memcpy(new_array, array->values, sizeof(int) * array->size);

  free(array->values);
  array->values = new_array;
  array->capacity = new_capacity;
}

void push_back_array_list(array_list_t *array, int value) {
  if (array->size + 1 > array->capacity) {
    grow_internal_array(array);
  }

  array->values[array->size] = value;
  array->size++;
}

void push_at_array_list(array_list_t *array, size_t index, int value) {
  ASSERT(index < array->size, "Array List: Index must be less than size");
  if (array->size + 1 > array->capacity) {
    grow_internal_array(array);
  }

  int tmp = array->values[index];
  for (size_t i = index; i < array->size; i++) {
    int tmp2 = array->values[i + 1];
    array->values[i + 1] = tmp;
    tmp = tmp2;
  }

  array->values[index] = value;
  array->size++;
}

int pop_back_array_list(array_list_t *array) {
  ASSERT(array->size > 0, "Array List: Size must be greater than zero to pop");
  array->size--;
  return array->values[array->size];
}
int pop_at_array_list(array_list_t *array, size_t index) {
  ASSERT(array->size > 0, "Array List: Size must be greater than zero to pop");
  ASSERT(index < array->size, "Array List: Index must be less than size");

  int pop = array->values[index];

  for (size_t i = index; i < array->size - 1; i++) {
    array->values[i] = array->values[i + 1];
  }

  array->size--;
  return pop;
}

int get_array_list(array_list_t *array, size_t index) {
  ASSERT(index < array->size, "Array List: Index must be less than size");

  return array->values[index];
}

void print_array_list(array_list_t *array) {
  print_array(array->values, array->size);
}
