// Nicholas Koeppen
#include "nk-linkedlist.c"
#include <stdio.h>
#include <stdlib.h>

void push(Node **head, int newData) { // Adds to front
  Node *newNode = createNode(newData, *head);
  *head = newNode;
}

int pop(Node **headPointer) { // Removes from front
  if (*headPointer == NULL) {
    return -1;
  } else {
    Node *head = *headPointer;
    int data = head->data;
    (*headPointer) = (*headPointer)->next;
    free(head);
    return data;
  }
}

int peek(Node *head) { // Removes from front
  if (head == NULL) {
    return -1;
  } else {
    return head->data;
  }
}

int main() {
  Node *head = createNode(1, NULL);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  printList(head);
  printf("Head is %d\n", peek(head));
  printf("Removing %d\n", pop(&head));
  printList(head);
}
