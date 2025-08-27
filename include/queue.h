#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef linked_list_t queue_t;

queue_t create_queue();

void queue_enqueue(queue_t* queue, int value);
void queue_dequeue(queue_t* queue);
int queue_peek(queue_t* queue);
void print_queue(queue_t* queue);

#endif
