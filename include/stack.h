#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

typedef linked_list_t stack_t;

stack_t stack_create();

void stack_push(stack_t *stack, void *value);
void stack_pop(stack_t *stack);
void *stack_top(stack_t *stack);
void stack_print_int(stack_t *stack);

#endif
