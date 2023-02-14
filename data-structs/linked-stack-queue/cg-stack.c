#include "cg-linkedlist.c"
#include <stdio.h>
#include <stdlib.h>

node *top;

void init() { top = NULL; }
void push(char *s) { top = createNode(s, top); }
void pop() { deleteNode(top->data, &top); }
char *getTop() { return top->data; }
int isEmpty() { return top == NULL; }

char *peek() {
  char *s = top->data;
  return s;
}

int main() {
  init();
  push("Windows");
  push("MacOS");
  push("Ubuntu");
  push("Debian");
  push("Mint");
  push("Fedora");
  push("Arch");
  push("Manjaro");
  printf("Here is the stack:\n");
  printList(top);
  printf("\n");
  printf("Here is the value peeked at: %s\n", peek());
  for (int i = 0; i < 3; i++) {
    pop();
  }
  printf("Here is the new stack:\n");
  printList(top);
  return 0;
}
