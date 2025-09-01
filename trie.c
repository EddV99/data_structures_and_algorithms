#include "trie.h"
#include "common.h"

#include <ctype.h>
#include <stdlib.h>

#define char_to_index(char) (char)-'a'

trie_node_t *trie_node_create(char is_terminal, char value) {
  trie_node_t *node = malloc(sizeof(trie_node_t));
  node->is_terminal = is_terminal;
  node->value = value;
  return node;
}

void trie_node_free(trie_node_t *node) { free(node); }

trie_t trie_create() {
  trie_t trie = {
      .root = trie_node_create(false, '\0'),
  };
  return trie;
}

int trie_find(trie_t *trie, const char *word) {
  trie_node_t *current = trie->root;

  for (int i = 0; word[i] != '\0'; i++) {
    int index = tolower(word[i]) - 'a';
    ASSERT(index >= 0 && index < 26, "Trie: illegal character");
    current = current->children[index];

    if (!current) {
      return 0;
    }
  }

  return current->is_terminal;
}

void trie_insert(trie_t *trie, const char *word) {
  trie_node_t *current = trie->root;

  for (int i = 0; word[i] != '\0'; i++) {
    char lower_char = tolower(char_to_index(word[i]));
    int index = lower_char - 'a';
    ASSERT(index >= 0 && index < 26, "Trie: illegal character");

    if (!current->children[index]) {
      current->children[index] =
          trie_node_create(word[i + 1] == '\0' ? false : true, lower_char);
    }

    current = current->children[index];
  }
}

int no_children(trie_node_t *node) {
  for (int i = 0; i < 26; i++) {
    if (node->children[i])
      return 0;
  }
  return 1;
}

void trie_delete_helper(trie_node_t *node, const char *word, int index,
                        int depth) {
  ASSERT(index >= 0 && index < 26, "Trie: illegal character");

  if (!node) {
    return;
  }

  trie_delete_helper(node->children[index], word,
                     char_to_index(tolower(word[0])), depth + 1);
  if (no_children(node)) {
    trie_node_free(node);
  } else if (word[depth + 1] == '\0') {
    node->is_terminal = false;
  }
}

void trie_delete(trie_t *trie, const char *word) {
  trie_delete_helper(trie->root, word, char_to_index(tolower(word[0])), 0);
}
