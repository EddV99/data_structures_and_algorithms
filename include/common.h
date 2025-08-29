#ifndef COMMON_H
#define COMMON_H

#define ASSERT(condition, msg)                                                 \
  {                                                                            \
    if (!(condition)) {                                                        \
      printf("[ASSERT FAILED] %s\n", msg);                                     \
      exit(1);                                                                 \
    }                                                                          \
  }

#define MOD(a, b) ((a) % (b)) < 0 ? ((a) % (b)) + b : ((a) % (b));

void swap(int *array, int x1, int x2);
void print_array(int *array, int size);

#endif
