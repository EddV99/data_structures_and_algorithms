#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct node_t {
  void *value;
  struct node_t *next;
  struct node_t *prev;
} node_t;

typedef struct {
  node_t *head;
  node_t *tail;
  size_t size;
} linked_list_t;

linked_list_t create_linked_list();

void remove_from_linked_list(linked_list_t *list, node_t *node);
void remove_at_from_linked_list(linked_list_t *list, size_t index);

void prepend_to_linked_list(linked_list_t *list, void *value);
void append_to_linked_list(linked_list_t *list, void *value);
void insert_to_linked_list(linked_list_t *list, size_t index, void *value);

void *get_from_linked_list(linked_list_t *list, size_t index);

void print_linked_list_int(linked_list_t *list);

#endif
