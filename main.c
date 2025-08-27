#include "common.h"
#include "queue.h"

#include <stdio.h>

int main() {
  queue_t q = create_queue();
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  printf("Peeking: %d\n", queue_peek(&q));
  print_queue(&q);
}
