#include "binary_search.h"

int binary_search(int *a, int size, int target) {
  int lo = 0;
  int hi = size - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) {
      return 1;
    } else if (a[mid] < target) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return 0;
}
