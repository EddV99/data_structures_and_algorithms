#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

typedef linked_list_t stack_t;

stack_t create_stack();

void stack_enqueue(stack_t* stack, int value);
void stack_dequeue(stack_t* stack);
int stack_peek(stack_t* stack);
void print_stack(stack_t* stack);

#endif
