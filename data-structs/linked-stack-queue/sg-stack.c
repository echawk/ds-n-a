#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sg-linkedlist.h"

#define DEFAULT_MAX_SIZE 16

typedef struct stack_s {
  int size;
  node_t *data;
} stack_t;

bool stack_is_empty(stack_t *stack) { return (stack->data == NULL || stack->size == 0); }

int stack_pop(stack_t *stack) {
  if (stack_is_empty(stack)) {
    fprintf(stderr, "[ERROR] Attempted to pop from an empty stack!\n");
    exit(EXIT_FAILURE);
  }

  int ret = stack->data->data;
  node_delete_at_place(&stack->data, 0);
  stack->size--;

  return ret;
}

void stack_push(stack_t *stack, int data) {
  node_add_to_front(&stack->data, data);
  stack->size++;

  return;
}

int stack_peek(stack_t *stack) {
  if (stack_is_empty(stack)) {
    fprintf(stderr, "[ERROR] Attempted to peek from an empty stack!\n");
    exit(EXIT_FAILURE);
  }

  return stack->data->data;
}

void stack_print(stack_t *stack){
	if(stack == NULL || stack_is_empty(stack)){
		printf("Empty!\n");
		return;
	}
	node_print(stack->data);
	return;
}

void stack_print_status(stack_t* stack){
	printf("Current stack: ");
	stack_print(stack);
	if(stack)
		printf("Stack size: %d\n", stack->size);
	else
		printf("Stack size: 0\n");
}

int main(void){
	stack_t* stack = NULL;
	// Test: nothing
	stack_print_status(stack);
	// Test: allocation
	stack = malloc(sizeof(stack_t));
	stack_print_status(stack);
	// Test: adding one element
	stack_push(stack, 6);
	stack_print_status(stack);
	// Test: adding many elements
	stack_push(stack, 8);
	stack_push(stack, 9);
	stack_push(stack, 5);
	stack_print_status(stack);
	// Test: remove one element
	stack_pop(stack);
	stack_print_status(stack);
	// Test: remove all elements
	stack_pop(stack);
	stack_pop(stack);
	stack_pop(stack);
	stack_print_status(stack);

	free(stack);

	return EXIT_SUCCESS;
}
