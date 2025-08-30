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

linked_list_t linked_list_create();

void linked_list_remove(linked_list_t *list, node_t *node);
void linked_list_remove_at(linked_list_t *list, size_t index);

void linked_list_prepend(linked_list_t *list, void *value);
void linked_list_append(linked_list_t *list, void *value);
void linked_list_insert(linked_list_t *list, size_t index, void *value);

void *linked_list_get(linked_list_t *list, size_t index);

void linked_list_print_int(linked_list_t *list);

#endif
