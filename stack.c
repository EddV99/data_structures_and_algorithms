#include "stack.h"
#include "common.h"
#include "linked_list.h"

#include <stdio.h>

stack_t create_stack() { return create_linked_list(); }

void stack_enqueue(stack_t *stack, int value) {
  prepend_to_linked_list(stack, (void*)value);
}

void stack_dequeue(stack_t *stack) {
  ASSERT(stack->size > 0, "Stack: size must be greater than zero to destack");
  remove_at_from_linked_list(stack, 0);
}

int stack_peek(stack_t *stack) {
  ASSERT(stack->size > 0, "Stack: size must be greater than zero to peek");
  return (int)get_from_linked_list(stack, 0);
}

void print_stack(stack_t *stack) {
  printf("FRONT -> BACK\n");
  print_linked_list_int(stack);
}
