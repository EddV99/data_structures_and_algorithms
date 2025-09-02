#include "common.h"
#include <stdio.h>

void swap(int *array, int x1, int x2) {
  int tmp = array[x1];
  array[x1] = array[x2];
  array[x2] = tmp;
}

void array_print_int(int *array, int size) {
  printf("[");
  for (int i = 0; i < size - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d", array[size - 1]);
  printf("]\n");
}

void array_print_size_t(size_t *array, int size) {
  printf("[");
  for (int i = 0; i < size - 1; i++) {
    printf("%lu, ", array[i]);
  }
  printf("%lu", array[size - 1]);
  printf("]\n");
}
