#include "common.h"
#include "heap.h"
#include <stdio.h>

int MAX_HEAP(void *a, void *b) { return (int)b - (int)a; }
int MIN_HEAP(void *a, void *b) { return (int)a - (int)b; }

int main() {
  heap_t heap = heap_create(MAX_HEAP);

  heap_insert(&heap, (void *)4);
  heap_insert(&heap, (void *)1);
  heap_insert(&heap, (void *)2);
  heap_insert(&heap, (void *)9);
  heap_insert(&heap, (void *)3);
  heap_insert(&heap, (void *)100);
  heap_insert(&heap, (void *)10);

  printf("Before\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);

  heap_delete(&heap);

  printf("After\n");
  heap_print(&heap);
}
