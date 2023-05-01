#include "cg-linkedlist.h"

typedef struct Queue {
  LL_T *list;
} Queue_T;

Queue_T *createQueue() {
  Queue_T *queue = (Queue_T *)malloc(sizeof(Queue_T));
  queue->list = createList();
  return queue;
}

void enqueue(Queue_T *q, int d) { addToEnd(q->list, d); }
void dequeue(Queue_T *q) { removeFirst(q->list); }
void printQueue(Queue_T *q) { printList(q->list); }

int main() {
  srand((unsigned)time(NULL));
  clock_t start, end;
  double duration;
  Queue_T *queue = createQueue();
  start = clock();
  enqueue(queue, 49);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to add an element to a queue is: %10f\n\n", duration);
  for (int i = 0; i < 20; i++) {
    enqueue(queue, rand() % 50);
  }
  printQueue(queue);
  start = clock();
  dequeue(queue);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to delete an element from a queue is: %10f\n\n",
         duration);
  dequeue(queue);
  printQueue(queue);
  return 0;
}