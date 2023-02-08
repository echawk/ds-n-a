#include "cg-linkedlist.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  node *front, *rear;
} queue;

queue *createQueue() {
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = q->rear = NULL;
  return q;
}

void queueAdd(queue *q, int d) {
  node *link = createNode(d, NULL);
  if (q->front == NULL) {
    q->front = q->rear = link;
    return;
  }
  q->rear->next = link;
  q->rear = link;
}

void queueRemove(queue *q) {
  if (q->front == NULL) {
    return;
  }
  node *link = q->front;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
}

int main() {
  queue *q = createQueue();
  for (int i = 0; i < 25; i++) {
    queueAdd(q, rand() % 101);
  }
  printf("Here is the queue:\n");
  printList(q->front);
  printf("\n");
  for (int i = 0; i < 5; i++) {
    queueRemove(q);
  }
  printf("Here is the new queue:\n");
  printList(q->front);
  printf("\n");
  return 0;
}
