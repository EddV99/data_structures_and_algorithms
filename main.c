#include "array_list.h"
#include "common.h"

#include <stdio.h>

int main() {
  array_list_t al = create_array_list();
  for (int i = 0; i < 1000; i++) {
    push_back_array_list(&al, i);
  }
  print_array_list(&al);
  printf("capacity: %lu\n", al.capacity);
  printf("size: %lu\n", al.size);
}
