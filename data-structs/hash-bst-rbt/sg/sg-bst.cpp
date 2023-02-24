#include <iostream>

#include "sg-bst.h"

// constructor

Node::Node(int data) {
  this->data = data;
  this->left = nullptr;
  this->right = nullptr;
}

// destructor

Node::~Node() {
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

void Node::print_in_order(Node *node) {
  if (node != nullptr) {
    print_in_order(node->left);
    std::cout << node->data << " ";
    print_in_order(node->right);
  }

  return;
}

// typical BST functions

BST::BST() { root = nullptr; }

BST::~BST() { free(root); }

Node *BST::insert_at_node(const int data, Node *node) {
  if (node == nullptr) {
    return nullptr; // shouldn't get here; return nullptr to indicate bad time
  }
  if (data < node->get_data()) {
    if (node->get_left_link() == nullptr) {
      node->set_left_link(new Node(data));
      return node->get_left_link();
    } else {
      return insert_at_node(data, node->get_left_link());
    }
  } else if (data > node->get_data()) {
    if (node->get_right_link() == nullptr) {
      node->set_right_link(new Node(data));
      return node->get_right_link();
    } else {
      return insert_at_node(data, node->get_right_link());
    }
  } else { // data == node->get_data()
    return node;
  }
}

Node *BST::search_at_node(const int data, Node *node) {
  if (node == nullptr || data == node->get_data()) {
    return node;
  }

  if (data < node->get_data()) {
    return search_at_node(data, node->get_left_link());
  }

  return search_at_node(data, node->get_right_link());
}

Node *BST::get_parent_node(Node *node, Node *child) {
  if (node == nullptr || child == nullptr || child == root) {
    return nullptr;
  }

  if (node->get_left_link() == child || node->get_right_link() == child) {
    return node;
  }

  if (child->get_data() < node->get_data()) {
    return get_parent_node(node->get_left_link(), child);
  }
  return get_parent_node(node->get_right_link(), child);
}

Node *BST::insert(const int data) {
  if (root == nullptr) {
    root = new Node(data);
    return root;
  }

  return insert_at_node(data, root);
}

Node *BST::remove(const int data) {
  Node *temp = search_at_node(data, root);

  if (temp == nullptr) {
    return nullptr;
  }
  return nullptr;
}

Node *BST::in_order_successor(Node *node) {
  if (node->get_right_link() != nullptr) {
    return minimum(node->get_right_link());
  } else {
    Node *temp = get_parent_node(root, node);

    while (temp != nullptr && node == temp->get_right_link()) {
      node = temp;
      temp = get_parent_node(root, temp);
    }

    return temp;
  }
}

Node *BST::transplant(Node *node1, Node *node2){
	Node *node1_par = get_parent_node(root, node1);
	Node *node2_par = get_parent_node(root, node2);

	if(node1_par == nullptr){
		root = node2;
	}
	else if(node1 == node1_par->get_left_link()){
		node1_par->set_left_link(node2);
	}
	else{
		node1_par->set_right_link(node2);
	}

	if(node2 != nullptr){
		node2_par = node1_par;
	}
}

Node *BST::minimum(Node *node) {
  Node *temp = node;
  while (temp->get_left_link() != nullptr) {
    temp = temp->get_left_link();
  }
  return temp;
}

Node *BST::maximum(Node *node) {
  Node *temp = node;
  while (temp->get_right_link() != nullptr) {
    temp = temp->get_right_link();
  }
  return temp;
}

void BST::print() {
  Node::print_in_order(root);
  std::cout << std::endl;

  return;
}
