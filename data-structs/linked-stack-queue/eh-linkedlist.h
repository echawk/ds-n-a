#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define DEBUG_STATEMENTS 0

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
  ll->size++;
}

void prependTo_LinkedList(LinkedList_T *ll, int v) {
  Node_T *nn = make_Node(v);
  nn->next = ll->head;
  ll->head = nn;
  ll->size++;
}

// FIXME: This does not work correctly.
void insertAt_LinkedList(LinkedList_T *ll, int ind, int v) {
  if (ind > ll->size || ind < 0)
    return;
  /* Ensure we don't follow null pointers. */
  if (ll->head == NULL)
    return;
  Node_T *curr = ll->head;
  int curr_ind = 0;
  while (curr_ind < (ind - 1)) {
    curr = curr->next;
    curr_ind++;
  }
  Node_T *new_next = curr->next->next;
  curr->next = make_Node(v);
  curr->next->next = new_next;
  ll->size++;
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
  /* Ensure we don't follow null pointers. */
  if (ll->head == NULL)
    return;
  Node_T *new_head = ll->head->next;
  free(ll->head);
  ll->head = new_head;
  ll->size -= 1;
}

void removeLast_LinkedList(LinkedList_T *ll) {
  /* Ensure we don't follow null pointers. */
  if (ll->head == NULL)
    return;
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
  /* Ensure we don't follow null pointers. */
  if (ll->head == NULL)
    return;
  Node_T *curr = ll->head;
  int curr_ind = 0;
  while (curr_ind < (ind - 1)) {
    curr = curr->next;
    curr_ind++;
  }
  Node_T *new_next = curr->next->next;
  free(curr->next);
  curr->next = new_next;
  ll->size -= 1;
}

Node_T *nodeAt_LinkedList(LinkedList_T *ll, int ind) {
  /* Return NULL in the error case. */
  if (ind < 0 || ind > ll->size)
    return NULL;
  if (ll->head == NULL)
    return NULL;
  Node_T *curr = ll->head;
  int curr_ind = 0;
  while (curr_ind < ind) {
    curr = curr->next;
    curr_ind++;
  }
  return curr;
}

Node_T *parentOf_LinkedList(LinkedList_T *ll, Node_T *node) {
  if (ll->head == NULL || ll->head == node)
    return NULL;
  Node_T *curr = ll->head;
  while (curr->next != node) {
    curr = curr->next;
  }
  return curr;
}

void swap_LinkedList(LinkedList_T *ll, int ind1, int ind2) {
  if (ind1 < 0 || ind1 > ll->size)
    return;
  if (ind2 < 0 || ind2 > ll->size)
    return;
  if (ind1 == ind2)
    return;
	
	
  Node_T *node1 = nodeAt_LinkedList(ll, ind1);
  Node_T *node2 = nodeAt_LinkedList(ll, ind2);

	if (node1->val != node2->val){
		node1->val = node1->val ^ node2->val;
		node2->val = node1->val ^ node2->val;
		node1->val = node1->val ^ node2->val;
	}
}

/* Roughly works? */
void free_LinkedList(LinkedList_T *ll) {
  while (ll->head != NULL) {
    removeFirst_LinkedList(ll);
  }
  ll->size = 0;
}

int quickSort_partition(LinkedList_T *ll, int low, int high) {
  Node_T *pivot_Node = nodeAt_LinkedList(ll, high);
  int pivot = pivot_Node->val;
  int i = low - 1;
  int j;
  for (j = low; j <= high - 1; j++) {
    Node_T *n = nodeAt_LinkedList(ll, j);
    if (n->val < pivot) {
      i++;
      swap_LinkedList(ll, i, j);
    }
  }
  swap_LinkedList(ll, i + 1, high);
  return i + 1;
}

void quickSort_driver(LinkedList_T *ll, int low, int high) {
  if (low < high) {
    int pi = quickSort_partition(ll, low, high);
    quickSort_driver(ll, low, pi - 1);
    quickSort_driver(ll, pi + 1, high);
  }
}

void quickSort_LinkedList(LinkedList_T *ll) {
  quickSort_driver(ll, 0, ll->size - 1);
}
