#include <iostream>

#include "sg-bst.h"

int main(void){
	Node head(10);
	head.insert_data(20);
	head.insert_data(5);
	head.insert_data(8);
	head.insert_data(11);

	head.print(&head);

	return 0;
}