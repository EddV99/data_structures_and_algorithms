#include "map.h"

#include <stdio.h>

int main() {
  map_t *map = map_new(100);
  char *w = "cap";
  printf("map has %s? %s\n", w, map_has(map, w) ? "true" : "false");
  printf("Setting\n");
  map_set(map, w, (void *)2);
  printf("map has %s? %s\n", w, map_has(map, w) ? "true" : "false");
  printf("Removing\n");
  map_remove(map, w);
  printf("map has %s? %s\n", w, map_has(map, w) ? "true" : "false");
}
