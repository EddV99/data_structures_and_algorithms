#include "queue.h"
#include "linked_list.h"
#include "common.h"

#include <stdio.h>

queue_t create_queue() {
  return create_linked_list();
}

void enqueue(queue_t* queue, int value){
  append_to_linked_list(queue, value);
}

void dequeue(queue_t* queue){
  ASSERT(queue->size > 0, "Queue: size must be greater than zero to dequeue");
  remove_at_from_linked_list(queue, 0);
}

int queue_peek(queue_t* queue){
  ASSERT(queue->size > 0, "Queue: size must be greater than zero to peek");
  return get_from_linked_list(queue, 0);
}

void print_queue(queue_t* queue) {
  printf("FRONT -> BACK\n");
  print_linked_list_int(queue); 
}
