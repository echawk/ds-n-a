#ifndef SG_LINKEDLIST_H
#define SG_LINKEDLIST_H

#include <stdbool.h>

typedef struct node_s {
  int data;
  struct node_s *next;
} node_t;

node_t *node_init(int _data, node_t *_next);

node_t *node_search_data(node_t **head_ref, int data, int instance);

bool node_delete(node_t **head_ref, node_t *key);

bool node_delete_at_place(node_t **head_ref, int index);

node_t *node_add_to_front(node_t **head_ref, int new_data);

node_t *node_add_to_end(node_t **head_ref, int new_data);

int node_get_at_end(node_t **head_ref);

void node_print(node_t *head);

void node_reverse_list(node_t **head_ref);

#endif
