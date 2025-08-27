#include "bubble_sort.h"

#include "common.h"

void bubble_sort(int *array, int size) {
  for (int n = size; n > 0; n--) {
    for (int i = 0; i < n - 1; i++) {
      if (array[i] > array[i + 1]) {
        swap(array, i, i + 1);
      }
    }
  }
}
