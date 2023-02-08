#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sg-linkedlist.h"

typedef struct queue_s{
	int size;
	node_t* data;
} queue_t;

int queue_dequeue(queue_t* queue){
	if(queue->data == NULL){
		fprintf(stderr, "[ERROR] Attempted to dequeue from an empty queue!\n");
		exit(EXIT_FAILURE);
	}

	int ret = node_get_at_end(&queue->data);
	node_delete_at_place(&queue->data, queue->size - 1);
	queue->size--;

	return ret;
}

void queue_enqueue(queue_t* queue, int data){
	node_add_to_front(&queue->data, data);
	queue->size++;

	return;
}

int queue_peek(queue_t* queue){
	if(queue->data == NULL){
		fprintf(stderr, "[ERROR] Attempted to peek from an empty queue!\n");
		exit(EXIT_FAILURE);
	}

	return node_get_at_end(&queue->data);
}

bool queue_is_empty(queue_t* queue){
	return (queue->data == NULL);
}
