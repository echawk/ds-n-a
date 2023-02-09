#ifndef SG_BST_H
#define SG_BST_H

class Node{
	private:
		int 	data;
		Node* 	left;
		Node* 	right;

		int 	get_successor(const int value);
	public:
		//accessors
		int 	get_data(void);
		Node*  	get_left_link(void);
		Node* 	get_right_link(void);
		//mutators
		void 	set_data(int data);
		void 	set_left_link(Node* left);
		void 	set_right_link(Node* right);
		//typical BST functions
		void 	insert_data(int data);
		Node* 	remove_data(int data);
		void 	remove_node(Node* node);
		Node* 	search_for_data(int data);
};

#endif