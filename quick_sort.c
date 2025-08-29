#include "quick_sort.h"
#include "common.h"

int partition(int *array, int lo, int hi) {
  int pivot = array[hi];

  int si = lo;
  for (int i = lo; i < hi; i++) {
    if (array[i] <= pivot) {
      swap(array, si, i);
      si++;
    }
  }
  swap(array, si, hi);

  return si;
}

void quick_sort_helper(int *array, int lo, int hi) {
  if (lo >= hi) {
    return;
  }

  int pivot_index = partition(array, lo, hi);
  quick_sort_helper(array, lo, pivot_index - 1);
  quick_sort_helper(array, pivot_index + 1, hi);
}

void quick_sort(int *array, int size) { quick_sort_helper(array, 0, size - 1); }
