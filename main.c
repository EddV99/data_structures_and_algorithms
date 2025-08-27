#include "common.h"
#include "queue.h"
#include "stack.h"

#include <stdio.h>

int main() {
  queue_t q = create_queue();
  queue_enqueue(&q, 1);
  queue_enqueue(&q, 2);
  queue_enqueue(&q, 3);
  queue_enqueue(&q, 4);
  printf("Peeking: %d\n", queue_peek(&q));
  print_queue(&q);

  stack_t s = create_stack();
  stack_enqueue(&s, 1);
  stack_enqueue(&s, 2);
  stack_enqueue(&s, 3);
  stack_enqueue(&s, 4);
  printf("Peeking: %d\n", stack_peek(&s));
  print_stack(&s);
}
