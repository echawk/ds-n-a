#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sg-linkedlist.h"

typedef struct queue_s {
  int size;
  node_t *data;
} queue_t;

bool queue_is_empty(queue_t *queue) { return (queue->data == NULL || queue->size == 0); }

int queue_dequeue(queue_t *queue) {
  if (queue_is_empty(queue)) {
    fprintf(stderr, "[ERROR] Attempted to dequeue from an empty queue!\n");
    exit(EXIT_FAILURE);
  }

  int ret = node_get_at_end(&queue->data);
  node_delete_at_place(&queue->data, queue->size - 1);
  queue->size--;

  return ret;
}

void queue_enqueue(queue_t *queue, int data) {
  node_add_to_front(&queue->data, data);
  queue->size++;

  return;
}

int queue_peek(queue_t *queue) {
  if (queue_is_empty(queue)) {
    fprintf(stderr, "[ERROR] Attempted to peek from an empty queue!\n");
    exit(EXIT_FAILURE);
  }

  return node_get_at_end(&queue->data);
}

void queue_print(queue_t *queue){
	if(queue == NULL || queue_is_empty(queue)){
		printf("Empty!\n");
		return;
	}
	node_print(queue->data);
	return;
}

void queue_print_status(queue_t* queue){
	printf("Current queue: ");
	queue_print(queue);
	if(queue)
		printf("Queue size: %d\n", queue->size);
	else
		printf("Queue size: 0\n");
}

int main(void){
	queue_t* queue = NULL;
	// Test: nothing
	queue_print_status(queue);
	// Test: allocation
	queue = malloc(sizeof(queue_t));
	queue_print_status(queue);
	// Test: adding one element
	queue_enqueue(queue, 6);
	queue_print_status(queue);
	// Test: adding many elements
	queue_enqueue(queue, 8);
	queue_enqueue(queue, 9);
	queue_enqueue(queue, 5);
	queue_print_status(queue);
	// Test: remove one element
	queue_dequeue(queue);
	queue_print_status(queue);
	// Test: remove all elements
	queue_dequeue(queue);
	queue_dequeue(queue);
	queue_dequeue(queue);
	queue_print_status(queue);

	free(queue);

	return EXIT_SUCCESS;
}
