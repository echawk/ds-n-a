#include "eh-linkedlist.h"

typedef LinkedList_T Stack_T;

Stack_T make_Stack(int v) { return make_LinkedList(v); }

int peek_Stack(Stack_T s) { return s.head->val; }
int pop_Stack(Stack_T *s) {
  int v = s->head->val;
  removeFirst_LinkedList(s);
  return v;
}
void push_Stack(Stack_T *s, int v) { prependTo_LinkedList(s, v); }
void print_Stack(Stack_T s) { print_LinkedList(s); }

int main() {
  Stack_T s = make_Stack(10);
  print_Stack(s);
  for (int i = 0; i < 3; i++) {
    push_Stack(&s, i);
  }
  print_Stack(s);
}
