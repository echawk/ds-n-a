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

void queueAdd(queue *q, char* s) {
  node *link = createNode(s, NULL);
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
  queueAdd(q, "Windows");
  queueAdd(q, "MacOS");
  queueAdd(q, "Ubuntu");
  queueAdd(q, "Debian");
  queueAdd(q, "Mint");
  queueAdd(q, "Fedora");
  queueAdd(q, "Arch");
  queueAdd(q, "Manjaro");
  printf("Here is the queue:\n");
  printList(q->front);
  printf("\n");
  printf("\tList size: %d\n", listSize(q->front));
  for (int i = 0; i < 3; i++) {
    queueRemove(q);
  }
  printf("Here is the new queue:\n");
  printList(q->front);
  printf("\n");
  printf("\tList size: %d\n", listSize(q->front));
  return 0;
}
