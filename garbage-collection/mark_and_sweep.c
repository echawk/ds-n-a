#include "../data-structs/linked-stack-queue/sg-linkedlist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define START_SIZE 128

typedef struct gc_linked_list_s {
  node_t *head;
  node_t **nodes_arr;
  bool *keep;
  int num_nodes;
} gc_linked_list_t;

void gc_linked_list_reset_marks(gc_linked_list_t *list) {
  for (int i = 0; i < list->num_nodes; i++) {
    list->keep[i] = false;
  }
}

void gc_linked_list_init(gc_linked_list_t *list) {
  list->head = NULL;
  list->nodes_arr = calloc(START_SIZE, sizeof(node_t *));
  list->keep = calloc(START_SIZE, sizeof(bool));
  list->num_nodes = 0;
}

void gc_linked_list_add(gc_linked_list_t *list,
                        int data) { // just adds to front for ease of use
  node_t *temp;

  temp->data = data;
  temp->next = list->head;
  list->head = temp;
  list->nodes_arr[list->num_nodes++] = temp;

  return;
}

void gc_linked_list_remove(gc_linked_list_t *list) { // remove from front
  list->head = list->head->next;

  return;
}

void mark(gc_linked_list_t *list) {
  gc_linked_list_reset_marks(list);
  node_t *ptr = list->head;

  while (ptr != NULL) {
    for (int i = 0; i < list->num_nodes; i++) {
      if (list->nodes_arr[i] == ptr) {
        list->keep[i] = true;
        break;
      }
    }

    ptr = ptr->next;
  }

  return;
}

void sweep(gc_linked_list_t *list) {
  int removed_nodes = 0;

  for (int i = 0; i < list->num_nodes; i++) {
    if (!list->keep[i]) {
      free(list->nodes_arr[i]);
      removed_nodes++;
    }
  }

  list->num_nodes -= removed_nodes;
}

int main() { return 0; }
