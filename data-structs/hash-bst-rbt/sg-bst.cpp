#include <iostream>

#include "sg-bst.h"

// constructor

template <class T>
Node<T>::Node(T data) {
  this->data = data;
  this->left = nullptr;
  this->right = nullptr;
}

// destructor
template <class T>
Node<T>::~Node() {
  free(this->left);
  free(this->right);
}

// accessors

template <class T>
T Node<T>::get_data(void) { return this->data; }

template <class T>
Node<T> *Node<T>::get_left_link(void) { return this->left; }

template <class T>
Node<T> *Node<T>::get_right_link(void) { return this->right; }

// mutators

template <class T>
void Node<T>::set_data(T data) {
  this->data = data;
  return;
}

template <class T>
void Node<T>::set_left_link(Node<T> *left) {
  this->left = left;
  return;
}

template <class T>
void Node<T>::set_right_link(Node<T> *right) {
  this->right = right;
  return;
}

template <class T>
void Node<T>::print_in_order(Node<T> *node) {
  if (node != nullptr) {
    print_in_order(node->left);
    std::cout << node->data << " ";
    print_in_order(node->right);
  }

  return;
}

// typical BST functions

template <class T>
BST<T>::BST() { root = nullptr; }

template <class T>
BST<T>::~BST() { free(root); }

template <class T>
Node<T> *BST<T>::insert_at_node(const T data, Node<T> *node) {
  if (node == nullptr) {
    return nullptr; // shouldn't get here; return nullptr to indicate bad time
  }
  if (data < node->get_data()) {
    if (node->get_left_link() == nullptr) {
      node->set_left_link(new Node<T>(data));
      return node->get_left_link();
    } else {
      return insert_at_node(data, node->get_left_link());
    }
  } else if (data > node->get_data()) {
    if (node->get_right_link() == nullptr) {
      node->set_right_link(new Node<T>(data));
      return node->get_right_link();
    } else {
      return insert_at_node(data, node->get_right_link());
    }
  } else { // data == node->get_data()
    return node;
  }
}

template <class T>
Node<T> *BST<T>::search_at_node(const T data, Node<T> *node) {
  if (node == nullptr || data == node->get_data()) {
    return node;
  }

  if (data < node->get_data()) {
    return search_at_node(data, node->get_left_link());
  }

  return search_at_node(data, node->get_right_link());
}

template <class T>
Node<T> *BST<T>::get_parent_node(Node<T> *node, Node<T> *child) {
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

template <class T>
Node<T> *BST<T>::insert(const T data) {
  if (root == nullptr) {
    root = new Node<T>(data);
    return root;
  }

  return insert_at_node(data, root);
}

template <class T>
void BST<T>::remove(const T data) {
  Node<T> *temp = search_at_node(data, root);

  if(temp == nullptr){
		return;
	}

	if(temp->get_left_link() == nullptr){
		transplant(temp, temp->get_right_link());
	}
	else if(temp->get_right_link() == nullptr){
		transplant(temp, temp->get_left_link());
	}
	else{
		Node<T> *successor = minimum(temp->get_right_link());
		if(successor != temp->get_right_link()){
			transplant(successor, successor->get_right_link());
			successor->set_right_link(temp->get_right_link());
		}

		transplant(temp, successor);
		successor->set_left_link(temp->get_left_link());
	}
}

template <class T>
Node<T> *BST<T>::in_order_successor(Node<T> *node) {
  if (node->get_right_link() != nullptr) {
    return minimum(node->get_right_link());
  } else {
    Node<T> *temp = get_parent_node(root, node);

    while (temp != nullptr && node == temp->get_right_link()) {
      node = temp;
      temp = get_parent_node(root, temp);
    }

    return temp;
  }
}

template <class T>
void BST<T>::transplant(Node<T> *node1, Node<T> *node2){
	Node<T> *node1_par = get_parent_node(root, node1);
	Node<T> *node2_par = get_parent_node(root, node2);

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

template <class T>
Node<T> *BST<T>::minimum(Node<T> *node) {
  Node<T> *temp = node;
  while (temp->get_left_link() != nullptr) {
    temp = temp->get_left_link();
  }
  return temp;
}

template <class T>
Node<T> *BST<T>::maximum(Node<T> *node) {
  Node<T> *temp = node;
  while (temp->get_right_link() != nullptr) {
    temp = temp->get_right_link();
  }
  return temp;
}

template <class T>
void BST<T>::print() {
  Node<T>::print_in_order(root);
  std::cout << std::endl;

  return;
}
