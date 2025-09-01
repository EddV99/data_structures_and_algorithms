#ifndef HEAP_H
#define HEAP_H

#include "array_list.h"

int MAX_HEAP(void *a, void *b) { return (int)b - (int)a; }
int MIN_HEAP(void *a, void *b) { return (int)a - (int)b; }

typedef struct {
  array_list_t array;
  int (*comparator)(void *, void *);
} heap_t;

heap_t heap_create(int (*comparator)(void *, void *));
void heap_free(heap_t *heap);

void *heap_peek(heap_t *heap);
void heap_insert(heap_t *heap, void *value);
void heap_delete(heap_t *heap);

void heap_print(heap_t *heap);

#endif
