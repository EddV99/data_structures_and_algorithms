#include "stack.h"
#include "common.h"
#include "linked_list.h"

#include <stdio.h>

stack_t stack_create() { return linked_list_create(); }

void stack_push(stack_t *stack, void *value) {
  linked_list_prepend(stack, value);
}

void stack_pop(stack_t *stack) {
  ASSERT(stack->size > 0, "Stack: size must be greater than zero to destack");
  linked_list_remove_at(stack, 0);
}

void *stack_top(stack_t *stack) {
  ASSERT(stack->size > 0, "Stack: size must be greater than zero to peek");
  return linked_list_get(stack, 0);
}

void stack_print_int(stack_t *stack) {
  printf("FRONT -> BACK\n");
  linked_list_print_int(stack);
}
