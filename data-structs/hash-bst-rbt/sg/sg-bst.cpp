#include "sg-bst.h"

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

// typical BST functions
void Node::insert_data(int data) {
  if (this == nullptr) {
    this->data = data;
    return;
  }
  if (data < this->data) {
    this->left->insert_data(data);
  } else if (data > this->data) {
    this->right->insert_data(data);
  }
  return;
}

int Node::get_successor(const int value) {
	if (this->left == nullptr && this->right == nullptr) {
		return this->data;
	}
	else if (this->left == nullptr){
		return this->right->get_successor(value);
	}
	else if (this->right == nullptr){
		return this->left->get_successor(value);
	}
  else if (this->left->data > value && this->right->data > value) {
    return this->left->get_successor(value);
  }
}

Node *Node::remove_data(int data) {
  if (this == nullptr) {
    return nullptr;
  }
  if (data == this->data) {
    if (this->left == nullptr && this->right == nullptr) {

    } else if (this->left == nullptr) {
      this->data = this->right->data;
      this->right = nullptr;
      return this;
    } else if (this->right == nullptr) {
      this->data = this->left->data;
      this->left = nullptr;
      return this;
    } else {
    }
  }
  if (data < this->data) {
    return this->left->remove_data(data);
  }
}

void Node::remove_node(Node *node) {}

Node *Node::search_for_data(int data) {}
