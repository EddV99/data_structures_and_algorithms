#include "ring_buffer.h"
#include "common.h"

#include <stddef.h>
#include <stdlib.h>

ring_buffer_t create_ring_buffer(long capacity) {
  ASSERT(capacity > 0, "Ring Buffer: capacity must be greater than 0");

  ring_buffer_t ring = {
    .head = 0,
    .tail = 0,
    .capacity = capacity,
    .size = 0,
    .values = malloc(sizeof(int) * capacity),
  };

  return ring;
}

void push_ring_buffer(ring_buffer_t* ring, int value) {
  ring->values[ring->tail] = value;
  ring->tail = MOD(ring->tail + 1,  ring->capacity);
}

int pop_ring_buffer(ring_buffer_t* ring) {
  int pop = ring->values[ring->head];
  ring->head = MOD(ring->head - 1, ring->capacity);
  return pop;
}
