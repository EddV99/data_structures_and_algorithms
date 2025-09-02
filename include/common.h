#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(condition, msg)                                                 \
  {                                                                            \
    if (!(condition)) {                                                        \
      printf("[ASSERT FAILED] %s\n", msg);                                     \
      exit(1);                                                                 \
    }                                                                          \
  }

#define MOD(a, b) ((a) % (b)) < 0 ? ((a) % (b)) + b : ((a) % (b));

void swap(int *array, int x1, int x2);
void array_print_int(int *array, int size);
void array_print_size_t(size_t *array, int size);

#endif
