#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stddef.h>

typedef struct {
  long head;
  long tail;
  const long capacity;
  long size;
  void **values;
} ring_buffer_t;

ring_buffer_t ring_buffer_create(long capacity);
void ring_buffer_push(ring_buffer_t *ring, void *value);
void *ring_buffer_pop(ring_buffer_t *ring);

#endif
