#include "trie.h"
#include "common.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define char_to_index(ch) ((ch) - 'a')

trie_node_t *trie_node_create(unsigned char is_terminal, char value) {
  trie_node_t *node = malloc(sizeof(trie_node_t));
  node->is_terminal = is_terminal;
  node->value = value;
  return node;
}

void trie_node_free(trie_node_t *node) { free(node); }

trie_t trie_create() {
  trie_t trie = {
      .root = trie_node_create(0, '\0'),
  };
  return trie;
}

int trie_find(trie_t *trie, const char *word) {
  trie_node_t *current = trie->root;

  for (int i = 0; word[i] != '\0'; i++) {
    int index = char_to_index(tolower(word[i]));
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
    char lower_char = tolower(word[i]);
    int index = char_to_index(lower_char);
    ASSERT(index >= 0 && index < 26, "Trie: illegal character");

    if (!current->children[index]) {
      current->children[index] =
          trie_node_create(word[i + 1] == '\0' ? 1 : 0, lower_char);
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

void trie_delete_helper(trie_node_t **node, const char *word, int i) {
  if (!node) {
    return;
  }

  if (word[i] == '\0') {
    if (no_children(*node)) {
      free(*node);
      *node = 0;
    } else {
      (*node)->is_terminal = 0;
    }
    return;
  } else {
    int index = char_to_index(tolower(word[i]));
    trie_delete_helper(&(*node)->children[index], word, i + 1);

    if (no_children(*node)) {
      free(*node);
      *node = 0;
    } else {
      (*node)->is_terminal = 0;
    }
  }
}

void trie_delete(trie_t *trie, const char *word) {
  trie_delete_helper(&trie->root, word, 0);
}
