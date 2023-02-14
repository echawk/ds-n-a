#include "eh-linkedlist.h"

typedef LinkedList_T Queue_T;

Queue_T make_Queue(int v) { return make_LinkedList(v); }
void enqueue(Queue_T *q, int v) { appendTo_LinkedList(q, v); }
int dequeue(Queue_T *q) {
  int v = q->head->val;
  removeFirst_LinkedList(q);
  return v;
}
void print_Queue(Queue_T q) { print_LinkedList(q); }

int main() {
  Queue_T q = make_Queue(10);
  print_Queue(q);
  for (int i = 0; i < 3; i++) {
    enqueue(&q, i);
  }
  print_Queue(q);
  int t;
  t = dequeue(&q);
  t = dequeue(&q);
  print_Queue(q);
}
