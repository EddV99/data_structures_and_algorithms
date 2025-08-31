#include "ring_buffer.h"
#include "common.h"

#include <stddef.h>
#include <stdlib.h>

ring_buffer_t ring_buffer_create(long capacity) {
  ASSERT(capacity > 0, "Ring Buffer: capacity must be greater than 0");

  ring_buffer_t ring = {
      .head = 0,
      .tail = 0,
      .capacity = capacity,
      .size = 0,
      .values = malloc(sizeof(void *) * capacity),
  };

  return ring;
}

void ring_buffer_push(ring_buffer_t *ring, void *value) {
  ring->values[ring->tail] = value;
  ring->tail = MOD(ring->tail + 1, ring->capacity);
}

void *ring_buffer_pop(ring_buffer_t *ring) {
  void *pop = ring->values[ring->head];
  ring->head = MOD(ring->head - 1, ring->capacity);
  return pop;
}
