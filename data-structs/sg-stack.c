#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sg-linkedlist.h"

typedef struct stack_s{
	int size;
	node_t* data;
} stack_t;

int stack_pop(stack_t* stack){
	if(stack->data == NULL){
		fprintf(stderr, "[ERROR] Attempted to pop from an empty stack!\n");
		exit(EXIT_FAILURE);
	}

	int ret = stack->data->data;
	node_delete_at_place(&stack->data, 0);
	stack->size--;

	return ret;
}

void stack_push(stack_t* stack, int data){
	node_add_to_front(&stack->data, data);
	stack->size++;

	return;
}

int stack_peek(stack_t* stack){
	if(stack->data == NULL){
		fprintf(stderr, "[ERROR] Attempted to peek from an empty stack!\n");
		exit(EXIT_FAILURE);
	}

	return stack->data->data;
}

bool stack_is_empty(stack_t* stack){
	return (stack->data == NULL);
}
