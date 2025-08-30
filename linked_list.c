#include "linked_list.h"
#include "common.h"

#include <stdlib.h>

node_t *linked_list_get_helper(linked_list_t *list, size_t index);

linked_list_t linked_list_create() {

  linked_list_t list = {
      .head = 0,
      .tail = 0,
      .size = 0,
  };
  return list;
}

void linked_list_remove(linked_list_t *list, node_t *node) {
  node_t *P = node->prev;
  node_t *N = node->next;

  if (!P && !N) {
    list->head = 0;
    list->tail = 0;
    list->size--;
    free(node);
    return;
  }

  if (P) {
    P->next = N;
    if (N) {
      N->prev = P;
    } else {
      list->tail = P;
    }
  } else if (N) {
    N->prev = 0;
    list->head = N;
  }

  node->next = 0;
  node->prev = 0;
  list->size--;
  free(node);
}

void linked_list_remove_at(linked_list_t *list, size_t index) {
  ASSERT(index < list->size,
         "Remove At Linked List: Index must be less than size of list");

  node_t *node = linked_list_get_helper(list, index);

  linked_list_remove(list, node);
}

void linked_list_prepend(linked_list_t *list, void *value) {
  node_t *node = malloc(sizeof(node_t));
  node->value = value;

  if (list->head) {
    node->next = list->head;
    node->prev = 0;

    list->head->prev = node;
    list->head = node;
  } else {
    node->next = 0;
    node->prev = 0;

    list->head = node;
    list->tail = node;
  }

  list->size++;
}

void linked_list_append(linked_list_t *list, void *value) {
  node_t *node = malloc(sizeof(node_t));
  node->value = value;

  if (list->tail) {
    node->next = 0;
    node->prev = list->tail;

    list->tail->next = node;
    list->tail = node;
  } else {
    node->next = 0;
    node->prev = 0;

    list->head = node;
    list->tail = node;
  }

  list->size++;
}

void linked_list_insert(linked_list_t *list, size_t index, void *value) {
  ASSERT(index <= list->size,
         "Inserting Linked List: Index must be less than size of list");

  if (index == 0) {
    linked_list_prepend(list, value);
    return;
  }
  if (index == list->size) {
    linked_list_append(list, value);
    return;
  }

  node_t *node = malloc(sizeof(node_t));
  node->value = value;

  node_t *current = linked_list_get_helper(list, index);

  node->next = current;
  node->prev = current->prev;

  current->prev->next = node;

  if (current == list->tail) {
    list->tail = node;
  }
  if (current == list->head) {
    list->head = node;
  }

  list->size++;
}

void linked_list_print_int(linked_list_t *list) {
  if (list->head) {
    node_t *current = list->head;
    while (current) {
      printf("(%d)", (*(int *)current->value));
      current = current->next;
      if (current) {
        printf("->");
      }
    }
    printf("\n");
  } else {
    printf("(EMPTY)\n");
  }
}

node_t *linked_list_get_helper(linked_list_t *list, size_t index) {
  node_t *current = 0;

  if ((list->size - index) < (list->size / 2)) {
    current = list->tail;
    index = list->size - index - 1;
    while (index) {
      index--;
      current = current->prev;
    }
  } else {
    current = list->head;
    while (index) {
      index--;
      current = current->next;
    }
  }

  return current;
}

void *linked_list_get(linked_list_t *list, size_t index) {
  ASSERT(index < list->size,
         "Getting From Linked List: Index must be less than size of list");

  return linked_list_get_helper(list, index)->value;
}
