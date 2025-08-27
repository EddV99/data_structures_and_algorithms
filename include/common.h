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

void swap(int *array, int x1, int x2);
void print_array(int *array, int size);

#endif
