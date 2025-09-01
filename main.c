#include "trie.h"
#include <stdio.h>

int main() {
  trie_t trie = trie_create();
  char *word = "ca";

  printf("Entering: %s\n", word);
  trie_insert(&trie, word);
  printf("Looking for %s: %s\n", word,
         trie_find(&trie, word) ? "true" : "false");

  word = "cats";
  printf("Entering: %s\n", word);
  trie_insert(&trie, word);
  printf("Looking for %s: %s\n", word,
         trie_find(&trie, word) ? "true" : "false");

  word = "catz";
  printf("Entering: %s\n", word);
  trie_insert(&trie, word);
  printf("Looking for %s: %s\n", word,
         trie_find(&trie, word) ? "true" : "false");

  word = "c";
  printf("Looking for %s: %s\n", word,
         trie_find(&trie, word) ? "true" : "false");

  word = "catz";
  printf("Removing: %s\n", word);
  trie_delete(&trie, word);
  printf("Looking for %s: %s\n", word,
         trie_find(&trie, word) ? "true" : "false");

  word = "cats";
  printf("Looking for %s: %s\n", word,
         trie_find(&trie, word) ? "true" : "false");
}
