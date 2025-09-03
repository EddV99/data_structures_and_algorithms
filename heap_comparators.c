#include "heap.h"
#include <stddef.h>

int MAX_HEAP_INT(void *a, void *b) { return (int)b - (int)a; }
int MIN_HEAP_INT(void *a, void *b) { return (int)a - (int)b; }

int MAX_HEAP_SIZE_T(void *a, void *b) { return (size_t)b - (size_t)a; }
int MIN_HEAP_SIZE_T(void *a, void *b) { return (size_t)a - (size_t)b; }
