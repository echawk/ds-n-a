// Nicholas Koeppen
#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
  int data;
  struct Data *next;
} Node;

Node *createNode(int newData, Node *newNext) {
  Node *new = (Node *)(malloc(sizeof(struct Data)));
  new->data = newData;
  new->next = newNext;
  return new;
}

void printList(Node *current) {
  int i = 1;
  while (current != NULL) {
    printf("Data #%d: %d\n", i, current->data);
    current = current->next;
    i += 1;
  }
}

int main() {
    Node* head = createNode(1, NULL);
    head->next = createNode(2, NULL);
    printList(head);
}
