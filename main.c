#include "common.h"
#include "linked_list.h"

#include <stdio.h>

int main() { 
  linked_list_t ll = create_linked_list();
  
  prepend_to_linked_list(&ll, 0);
  prepend_to_linked_list(&ll, 48);
  prepend_to_linked_list(&ll, 0);
  print_linked_list_int(&ll);

  printf("@ 0 is %d\n", get_from_linked_list(&ll, 0)); 
  printf("@ 1 is %d\n", get_from_linked_list(&ll, 1)); 
  printf("@ 2 is %d\n", get_from_linked_list(&ll, 2)); 
}
