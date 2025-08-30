#include "queue.h"
#include "common.h"
#include "linked_list.h"

#include <stdio.h>

queue_t queue_create() { return linked_list_create(); }

void queue_enqueue(queue_t *queue, void *value) {
  linked_list_append(queue, value);
}

void queue_dequeue(queue_t *queue) {
  ASSERT(queue->size > 0, "Queue: size must be greater than zero to dequeue");
  linked_list_remove_at(queue, 0);
}

void *queue_peek(queue_t *queue) {
  ASSERT(queue->size > 0, "Queue: size must be greater than zero to peek");
  return linked_list_get(queue, 0);
}

void queue_print_int(queue_t *queue) {
  printf("FRONT -> BACK\n");
  linked_list_print_int(queue);
}
