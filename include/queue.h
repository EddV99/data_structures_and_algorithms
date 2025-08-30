#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef linked_list_t queue_t;

queue_t queue_create();

void queue_enqueue(queue_t *queue, void *value);
void queue_dequeue(queue_t *queue);
void *queue_peek(queue_t *queue);
void queue_print_int(queue_t *queue);

#endif
