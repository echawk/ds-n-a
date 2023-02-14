#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO: Maybe make this generic? (void* anyone??) */
typedef struct Node {
  int val;
  struct Node *next;
} Node_T;

Node_T *make_Node(int v) {
  Node_T *nn = (Node_T *)malloc(sizeof(Node_T));
  nn->val = v;
  nn->next = NULL;
  return nn;
}

typedef struct LinkedList {
  Node_T *head;
  int size;
} LinkedList_T;

LinkedList_T make_LinkedList(int v) {
  return (LinkedList_T){
      .head = make_Node(v),
      .size = 1,
  };
}

void appendTo_LinkedList(LinkedList_T *ll, int v) {
  Node_T *curr = ll->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = make_Node(v);
  ll->size += 1;
}

void prependTo_LinkedList(LinkedList_T *ll, int v) {
  Node_T *nn = make_Node(v);
  nn->next = ll->head;
  ll->head = nn;
  ll->size += 1;
}

void insertAt_LinkedList(LinkedList_T *ll, int ind, int v) {
  if (ind > ll->size || ind < 0)
    return;
  Node_T *curr = ll->head;
  int curr_ind = 0;
  while (curr_ind < (ind - 1)) {
    curr = curr->next;
    curr_ind += 1;
  }
  Node_T *new_next = curr->next->next;
  curr->next = make_Node(v);
  curr->next->next = new_next;
  ll->size += 1;
}
void print_LinkedList(LinkedList_T ll) {
  Node_T *curr = ll.head;
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}

void removeFirst_LinkedList(LinkedList_T *ll) {
  Node_T *new_head = ll->head->next;
  free(ll->head);
  ll->head = new_head;
  ll->size -= 1;
}

void removeLast_LinkedList(LinkedList_T *ll) {
  Node_T *curr = ll->head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  free(curr->next);
  curr->next = NULL;
  ll->size -= 1;
}

void removeAt_LinkedList(LinkedList_T *ll, int ind) {
  if (ind > ll->size || ind < 0)
    return;
  Node_T *curr = ll->head;
  int curr_ind = 0;
  while (curr_ind < (ind - 1)) {
    curr = curr->next;
    curr_ind += 1;
  }
  Node_T *new_next = curr->next->next;
  free(curr->next);
  curr->next = new_next;
  ll->size -= 1;
}

/* Roughly works? */
/* void free_LinkedList(LinkedList_T *ll) { */
/*   while (ll->head != NULL) { */
/*     removeFirst_LinkedList(ll); */
/*   } */
/* } */
