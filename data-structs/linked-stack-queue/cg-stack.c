#include "cg-linkedlist.h"

typedef struct Stack {
  LL_T *list;
} Stack_T;

Stack_T *createStack() {
  Stack_T *stack = (Stack_T *)malloc(sizeof(Stack_T));
  stack->list = createList();
  return stack;
}

void push(Stack_T *s, int d) { addToFront(s->list, d); }
int pop(Stack_T *s) {
  int d = s->list->head->data;
  removeFirst(s->list);
  return d;
}
int peek(Stack_T *s) { return s->list->head->data; }
int isEmpty(Stack_T *s) { return s->list->head == NULL; }
void printStack(Stack_T *s) { printList(s->list); }

int main() {
  srand((unsigned)time(NULL));
  clock_t start, end;
  double duration;
  Stack_T *stack = createStack();
  start = clock();
  push(stack, 49);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to add an element to a stack is: %10f\n\n", duration);
  for (int i = 0; i < 20; i++) {
    push(stack, rand() % 50);
  }
  printStack(stack);
  printf("The element that was peeked at is: %d\n", peek(stack));
  start = clock();
  int d = pop(stack);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to delete an element from a stack is: %10f\n",
         duration);
  printf("\nThe element that was popped is: %d\n\n", d);
  printStack(stack);
  return 0;
}