#ifndef TRIE_H
#define TRIE_H

typedef struct trie_node_t {
  unsigned char is_terminal;
  char value;
  struct trie_node_t *children[26];
} trie_node_t;

trie_node_t *trie_node_create(unsigned char is_terminal, char value);
void trie_node_free(trie_node_t *node);

typedef struct {
  trie_node_t *root;
} trie_t;

trie_t trie_create();

int trie_find(trie_t *trie, const char *word);
void trie_insert(trie_t *trie, const char *word);
void trie_delete(trie_t *trie, const char *word);

#endif
