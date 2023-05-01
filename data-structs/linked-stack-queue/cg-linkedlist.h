#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node_T;

Node_T *createNode(int d) {
  Node_T *newNode = (Node_T *)malloc(sizeof(Node_T));
  newNode->data = d;
  newNode->next = NULL;
  return newNode;
}

Node_T *createNodeP(int d, Node_T *n) {
  Node_T *newNode = (Node_T *)malloc(sizeof(Node_T));
  newNode->data = d;
  newNode->next = n;
  return newNode;
}

typedef struct LinkedList {
  Node_T *head;
  int size;
} LL_T;

LL_T *createList() {
  LL_T *linked = (LL_T *)malloc(sizeof(LL_T));
  return linked;
}

void addToEnd(LL_T *l, int d) {
  Node_T *newNode = createNode(d);
  if (l->head == NULL) {
    l->head = newNode;
  } else {
    Node_T *curr = l->head;
    if (curr != NULL) {
      while (curr->next != NULL) {
        curr = curr->next;
      }
    }
    curr->next = newNode;
  }
  l->size++;
}

void addToFront(LL_T *l, int d) {
  Node_T *newNode = createNode(d);
  if (l->head == NULL) {
    l->head = newNode;
  } else {
    Node_T *temp = l->head;
    newNode = createNodeP(d, temp);
    l->head = newNode;
  }
  l->size++;
}

Node_T *findNode(LL_T *l, int d) {
  Node_T *curr = l->head;
  if (l->head != NULL) {
    while (curr->data != d) {
      if (curr->next != NULL) {
        curr = curr->next;
      }
    }
    return curr;
  } else {
    printf("\nThis node does not exist!\n");
  }
}

void deleteNode(LL_T *l, int d) {
  Node_T *curr = l->head;
  Node_T *prev = NULL;
  if (l->head != NULL) {
    while (curr->data != d) {
      if (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
      }
    }
    if (curr == l->head) {
      l->head = curr->next;
    } else {
      prev->next = curr->next;
    }
    free(curr);
    l->size--;
  } else {
    printf("\nThe list is empty!");
  }
}

void removeFirst(LL_T *l) {
  Node_T *curr = l->head;
  Node_T *newHead = curr->next;
  free(curr);
  l->head = newHead;
  l->size--;
}

void removeLast(LL_T *l) {
  Node_T *curr = l->head;
  Node_T *prev = NULL;
  if (l->head != NULL) {
    while (curr->next != NULL) {
      prev = curr;
      curr = curr->next;
    }
    if (curr->next == NULL) {
      prev->next = NULL;
    }
    free(curr);
  } else {
    printf("\nThe list is empty!\n");
  }
  l->size--;
}

void printList(LL_T *l) {
  printf("Here is the linked list: \n");
  Node_T *curr = l->head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\nThe size of the list is: %d\n\n", l->size);
}