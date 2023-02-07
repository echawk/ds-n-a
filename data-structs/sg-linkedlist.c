#include <stdio.h>
#include <stdlib.h>

#define DEBUG_STATEMENTS 1

typedef struct node_s{
	int data;
	struct node_s* next;
} node_t;

node_t* create_node(int _data, node_t* _next){
	node_t* ret = (node_t*)calloc(1, sizeof(node_t));

	ret->data = _data; 
	ret->next = _next;

	return ret;
}

int delete_node(node_t** head_ref, int key){
	node_t* ptr = *head_ref;
	node_t* last_node = NULL;

	// while(ptr != NULL){
	// 	if(ptr->data = )
	// }
}

void add_data_to_front(node_t** head_ref, int new_data){
	node_t* new_node = create_node(new_data, *head_ref);
	*head_ref = new_node;

	return;
}

void add_data_to_end(node_t** head_ref, int new_data){
	node_t* new_node = create_node(new_data, NULL);
	node_t* ptr = *head_ref;

	while(ptr->next != NULL){
		ptr = ptr->next;
	}

	ptr->next = new_node;

	return;
}

void print_nodes(node_t* head){
	node_t* ptr = head;
	
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	return;
}

int main(void){
	node_t* head = create_node(1, NULL);

	print_nodes(head);
	add_data_to_front(&head, 2);
	print_nodes(head);
	add_data_to_front(&head, 3);
	print_nodes(head);
	add_data_to_front(&head, 4);
	print_nodes(head);
	add_data_to_end(&head, 0);
	print_nodes(head);

	return EXIT_SUCCESS;
}