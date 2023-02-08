#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sg-linkedlist.h"

#define DEBUG_STATEMENTS 1

node_t* node_init(int _data, node_t* _next){
	node_t* ret = (node_t*)calloc(1, sizeof(node_t));

	ret->data = _data; 
	ret->next = _next;

	return ret;
}
//if instance is 0, deletes the first, so on so forth for other integers. If -1, deletes the last instance
node_t* node_search(node_t** head_ref, int data, int instance){
	if(instance < -1){
		fprintf(stderr, "[ERROR] Instance has to be greater than or equal to -1!\n");
		exit(EXIT_FAILURE);
	}

	node_t* ptr = *head_ref;
	node_t* ret = NULL;
	int instances_passed = 0;

	while(ptr != NULL){
		if(ptr->data == data){
			if(instance == instances_passed){
				return ptr;
			}
			ret = ptr;
			instances_passed++;
		}
		ptr = ptr->next;
	}

	return ret;	//this will return the last instance or NULL which is valid
}
// returns 
bool node_delete(node_t** head_ref, node_t* key){
	node_t* ptr = *head_ref;
	node_t* last_node = NULL;

	while(ptr != NULL){
		if(ptr == key){
			if(last_node != NULL){
				last_node->next = ptr->next;
				ptr->next = NULL;
				free(ptr);	//free the node we're no longer using
			}
			else{
				*head_ref = ptr->next;
			}
			return true;
		}
		last_node = ptr;
		ptr = ptr->next;
	}

	return false;
}

bool node_delete_at_place(node_t** head_ref, int index){
	node_t* ptr = *head_ref;
	node_t* last_node = NULL;
	int current_index = 0;

	while(ptr != NULL){
		if(current_index == index){
			if(last_node != NULL){
				last_node->next = ptr->next;
				ptr->next = NULL;
				free(ptr);	//free the node we're no longer using
			}
			else{
				*head_ref = ptr->next;
			}
			return true;
		}
		last_node = ptr;
		ptr = ptr->next;
		current_index++;
	}

	return false;
}

void node_add_to_front(node_t** head_ref, int new_data){
	node_t* new_node = node_init(new_data, *head_ref);
	*head_ref = new_node;

	return;
}

void node_add_to_end(node_t** head_ref, int new_data){
	node_t* new_node = node_init(new_data, NULL);
	node_t* ptr = *head_ref;

	while(ptr->next != NULL){
		ptr = ptr->next;
	}

	ptr->next = new_node;

	return;
}

int node_get_at_end(node_t** head_ref){
	if(*head_ref == NULL){
		fprintf(stderr, "[ERROR] Cannot get data at end of an empty linked list!\n");
		exit(EXIT_FAILURE);
	}

	node_t* ptr = *head_ref;

	while(ptr->next != NULL)
		ptr = ptr->next;

	return ptr->data;
}

void node_print(node_t* head){
	node_t* ptr = head;
	
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	return;
}

// int main(void){
// 	node_t* head = calloc(1, sizeof(node_t));

// 	node_add_to_front(&head, 2);
// 	node_add_to_front(&head, 2);
// 	node_add_to_front(&head, 3);
// 	node_add_to_front(&head, 2);
// 	node_add_to_front(&head, 4);
// 	node_add_to_front(&head, 0);
// 	node_add_to_end(&head, 0);
// 	node_print(head);
// 	node_delete_at_place(&head, 1);
// 	node_print(head);

// 	exit(EXIT_SUCCESS);
// }
