#include "../data-structs/linked-stack-queue/sg-linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define START_SIZE 128

#define ARR_SHIFT(arr, index, length) for(int i = index; i < length - 1; i++) arr[i] = arr[i + 1];

typedef struct gc_linked_list_t{
	node_t*  head;
	node_t** nodes_addrs;
	bool*    keep;
	int			 num_nodes;
} gc_linked_list_t;

void gc_linked_list_reset_marks(gc_linked_list_t* list){
	assert(list);	//makes sure that list is not nullptr

	for(int i = 0; i < list->num_nodes; i++){
		list->keep[i] = false;
	}
}

void gc_linked_list_init(gc_linked_list_t* list){
	assert(list);	//makes sure that list is not nullptr

	list->head = NULL;
	list->nodes_addrs = calloc(START_SIZE, sizeof(node_t*));
	list->keep = calloc(START_SIZE, sizeof(bool));
	list->num_nodes = 0;

	gc_linked_list_reset_marks(list);
}

void gc_linked_list_add(gc_linked_list_t* list, int data){	//just adds to front for ease of use
	assert(list);	//makes sure that list is not nullptr

	list->nodes_addrs[list->num_nodes++] = node_add_to_front(&list->head, data);

	return;
}

void gc_linked_list_remove(gc_linked_list_t* list){	//remove from front
	assert(list && (list->num_nodes > 0));	//makes sure that list is not nullptr

	node_delete_at_place(&list->head, 0);

	return;
}

void gc_linked_list_remove_at_index(gc_linked_list_t* list, int index){
	assert((index >= 0) && (index < list->num_nodes));

	node_delete_at_place(&list->head, index);

	return;
}

void mark(gc_linked_list_t* list){
	assert(list);	//makes sure that list is not nullptr
	gc_linked_list_reset_marks(list);
	node_t* ptr = list->head;

	while(ptr != NULL){
		for(int i = 0; i < list->num_nodes; i++){
			if(list->nodes_addrs[i] == ptr){
				list->keep[i] = true;
				break;
			}
		}

		ptr = ptr->next;
	}

	return;
}

void sweep(gc_linked_list_t* list){
	assert(list);	//makes sure that list is not nullptr
	int removed_nodes = 0;

	for(int i = 0; i < list->num_nodes; i++){
		if(!list->keep[i]){
			node_delete(&list->head, list->nodes_addrs[i]);
			removed_nodes++;
			ARR_SHIFT(list->keep, i, list);
		}
	}

	list->num_nodes -= removed_nodes;
}

int main(){
	gc_linked_list_t list;
	gc_linked_list_init(&list);



	mark(&list);
	sweep(&list);
	return 0;
}