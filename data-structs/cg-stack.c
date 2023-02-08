#include "cg-linkedlist.c"
#include <stdio.h>
#include <stdlib.h>

node* top;

void init() { top = NULL; }
void push(int d) { top = createNode(d, top); }
void pop() { deleteNode(top->data, &top); }
int getTop() { return top->data; }
int isEmpty() { return top == NULL; }

int peek() {
  int d;
  d = top->data;
  return d;
}

int main() {
  init();
  for (int i = 0; i < 25; i++) {
    push(rand() % 101);
  }
  printf("Here is the stack:\n");
  printList(top);
  printf("\n");
  printf("Here is the number peeked at: %d\n", peek());
  for (int i = 0; i < 5; i++) {
    pop();
  }
  printf("Here is the new stack:\n");
  printList(top);
  return 0;
}
