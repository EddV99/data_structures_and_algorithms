#include "linear_search.h"

int linear_search(int *a, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (a[i] == target) {
      return 1;
    }
  }
  return 0;
}
