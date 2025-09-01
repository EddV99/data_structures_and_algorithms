#include "heap.h"
#include "array_list.h"
#include "common.h"

#include <stdlib.h>

#define PARENT_INDEX(i) ((i - 1) / 2)
#define LEFT_CHILD_INDEX(i) ((i * 2) + 1)
#define RIGHT_CHILD_INDEX(i) ((i * 2) + 2)

void heap_heapify_up(heap_t *heap, int node_index) {
  if (node_index == 0) {
    return;
  }

  size_t parent_index = PARENT_INDEX(node_index);

  void *node_value = array_list_get(&heap->array, node_index);
  void *parent_value = array_list_get(&heap->array, parent_index);

  while (heap->comparator(node_value, parent_value) < 0) {
    array_list_set(&heap->array, node_index, parent_value);
    array_list_set(&heap->array, parent_index, node_value);

    node_index = parent_index;
    parent_index = PARENT_INDEX(parent_index);

    if (node_index == 0)
      break;

    node_value = array_list_get(&heap->array, node_index);
    parent_value = array_list_get(&heap->array, parent_index);
  }
}

void heap_heapify_down(heap_t *heap, size_t node_index) {
  if (node_index >= (heap->array.size - 1)) {
    return;
  }

  size_t left_index = LEFT_CHILD_INDEX(node_index);
  size_t right_index = RIGHT_CHILD_INDEX(node_index);

  while (left_index < heap->array.size) {
    void *node_value = array_list_get(&heap->array, node_index);
    void *left_value = array_list_get(&heap->array, left_index);

    if (right_index < heap->array.size) {
      void *right_value = array_list_get(&heap->array, right_index);
      if (heap->comparator(left_value, right_value) < 0 &&
          heap->comparator(node_value, left_value) > 0) {
        array_list_set(&heap->array, node_index, left_value);
        array_list_set(&heap->array, left_index, node_value);
        node_index = left_index;
      } else if (heap->comparator(right_value, left_value) < 0 &&
                 heap->comparator(node_value, right_value) > 0) {
        array_list_set(&heap->array, node_index, right_value);
        array_list_set(&heap->array, right_index, node_value);
        node_index = right_index;
      }
      left_index = LEFT_CHILD_INDEX(node_index);
      right_index = RIGHT_CHILD_INDEX(node_index);
    } else {
      if (heap->comparator(node_value, left_value) > 0) {
        array_list_set(&heap->array, node_index, left_value);
        array_list_set(&heap->array, left_index, node_value);
      } else {
        break;
      }
    }
  }
}

heap_t heap_create(int (*comparator)(void *, void *)) {
  heap_t heap = {
      .array = array_list_create(),
      .comparator = comparator,
  };
  return heap;
}

void heap_free(heap_t *heap) {
  ASSERT(heap, "Heap: can not free null heap");
  free(heap);
}

void *heap_peek(heap_t *heap) {
  ASSERT(heap->array.size > 0, "Heap: can not peek from an empty heap");
  return array_list_get(&heap->array, 0);
}

void heap_insert(heap_t *heap, void *value) {
  array_list_push_back(&heap->array, value);
  heap_heapify_up(heap, heap->array.size - 1);
}

void heap_delete(heap_t *heap) {
  ASSERT(heap->array.size > 0, "Heap: can not delete from an empty heap");

  if (heap->array.size == 1) {
    array_list_pop_back(&heap->array);
    return;
  }

  size_t index = heap->array.size - 1;
  void *value = array_list_get(&heap->array, index);

  array_list_remove(&heap->array, index);
  array_list_set(&heap->array, 0, value);

  heap_heapify_down(heap, 0);
}

void heap_print_helper_int(char *prefix, int size, heap_t *heap, size_t node,
                           bool is_left) {
  if (node < heap->array.size) {
    printf("%s", prefix);
    printf("%s", is_left ? "├──" : "└──");
    printf("%d\n", (int)array_list_get(&heap->array, node));

    int byte_count = sizeof(void *) * (size + 4);
    char *new_prefix = malloc(byte_count);
    if (is_left) {
      snprintf(new_prefix, byte_count, "%s%s", prefix, "│   ");
    } else {
      snprintf(new_prefix, byte_count, "%s%s", prefix, "    ");
    }
    heap_print_helper_int(new_prefix, size + 4, heap, LEFT_CHILD_INDEX(node),
                          true);
    heap_print_helper_int(new_prefix, size + 4, heap, RIGHT_CHILD_INDEX(node),
                          false);
    free(new_prefix);
  }
}

void heap_print(heap_t *heap) {
  char *prefix = malloc(sizeof(char) * 1);
  prefix[0] = '\0';
  heap_print_helper_int(prefix, 1, heap, 0, false);
  free(prefix);
}
