#include "quick_sort.h"
#include "common.h"

#include <stdio.h>

int main() {
  int array[] = {9, 3, 7, 4, 69, 420, 42, 1, 33};
  const int size = 9;

  print_array(array, size);
  quick_sort(array, size);
  print_array(array, size);
}
