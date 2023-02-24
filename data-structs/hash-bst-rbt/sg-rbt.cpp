#include <sg-rbt.h>

// constructors
RBNode::RBNode(int data){
	this->node.set_data(data);
	this->color = RED;
}

RBNode::RBNode(int data, color_t color){
	this->node.set_data(data);
	this->color = color;
}

// destructor
RBNode::~RBNode(){
	
}

// accessors
int RBNode::get_data(void){

}

color_t RBNode::get_color(void){

}

Node *RBNode::get_left_link(void){

}

Node *RBNode::get_right_link(void){

}

// mutators
void RBNode::set_data(int data){

}

void RBNode::set_color(color_t color){

}

void RBNode::set_left_link(Node *left){

}

void RBNode::set_right_link(Node *right){

}

void RBNode::print_in_order(Node *node){

}
