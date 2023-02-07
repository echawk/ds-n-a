#include "cg-linkedlist.c"
#include <stdio.h>
#include <stdlib.h>

node top;

void init() { top = NULL; }

void push(int d) {
  node temp = createNode(d, top);
  top = temp;
}

int pop() {
  int d;
  node temp;
  temp = top;
  d = temp->data;
  top = temp->next;
  free(temp);
  return d;
}

int peek() {
  int d;
  node temp;
  temp = top;
  d = top->data;
  return d;
}

int getTop() { return top->data; }
int isEmpty() { return top == NULL; }

void printStack(node h) {
  if (h == NULL) {
    printf("The stack is empty!\n");
  } else {
    printf("%d\n", h->data);
    printStack(h->next);
  }
}

int main() {
  init();
  for (int i = 0; i < 25; i++) {
    push(rand() % 101);
  }
  printf("Here is the stack:\n");
  printList(top);
  printf("\n");
  for (int i = 0; i < 2; i++) {
    pop();
  }
  printf("Here is the new stack:\n");
  printList(top);
  return 0;
}
