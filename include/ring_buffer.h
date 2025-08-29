#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stddef.h>

typedef struct {
  long head;
  long tail;
  const long capacity;
  long size;
  int *values;
} ring_buffer_t;

ring_buffer_t create_ring_buffer(long capacity);
void push_ring_buffer(ring_buffer_t *ring, int value);
int pop_ring_buffer(ring_buffer_t *ring);

#endif
