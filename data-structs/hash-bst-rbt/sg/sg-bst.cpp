#include <iostream>

#include "sg-bst.h"

// constructor

Node::Node(int data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

// destructor

Node::~Node(){
	free(this->left);
	free(this->right);
}

// accessors

int Node::get_data(void) { return this->data; }

Node *Node::get_left_link(void) { return this->left; }

Node *Node::get_right_link(void) { return this->right; }

// mutators

void Node::set_data(int data) {
  this->data = data;
  return;
}

void Node::set_left_link(Node *left) {
  this->left = left;
  return;
}

void Node::set_right_link(Node *right) {
  this->right = right;
  return;
}

void Node::print_in_order(Node* node){
	if(node == nullptr){
		return;
	}

	print_in_order(node->left);
	std::cout << node->data << " ";
	print_in_order(node->right);

	return;
}

// typical BST functions

BST::BST(){
	head = nullptr;
}

BST::~BST(){
	free(head);
}

Node* BST::insert_at_node(const int data, Node* node) {
	if(node == nullptr){
		return nullptr;	//shouldn't be here; return nullptr to indicate bad time
	}
	if(data < node->get_data()){
		if(node->get_left_link() == nullptr){
			node->set_left_link(new Node(data));
			return node->get_left_link();
		}
		else{
			return insert_at_node(data, node->get_left_link());
		}
	}
	else if(data > node->get_data()){
		if(node->get_right_link() == nullptr){
			node->set_right_link(new Node(data));
			return node->get_right_link();
		}
		else{
			return insert_at_node(data, node->get_right_link());
		}
	}
	else{	//data == node->get_data()
		return node;
	}
}

Node* BST::insert(const int data){
	if(head == nullptr){
		head = new Node(data);
		return head;
	}
	else{
		return insert_at_node(data, head);
	}
}

Node* BST::search_for_data(const int data, Node* node){
	if(node == nullptr){
		return nullptr;	//should be able to get here, indicates data not found
	}

	if(data == node->get_data()){
		return node;
	}
	else if(data < node->get_data()){
		search_for_data(data, node->get_left_link());
	}
	else{
		search_for_data(data, node->get_right_link());
	}
}

void BST::print(){
	if(head == nullptr){
		std::cout << "Empty list" << std::endl;
		return;
	}

	Node::print_in_order(head);
	std::cout << std::endl;

	return;
}
