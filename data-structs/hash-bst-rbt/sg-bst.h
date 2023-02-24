#ifndef SG_BST_H
#define SG_BST_H

template <class T>
class Node {
private:
  T data;
  Node *left;
  Node *right;

public:
  // constructor
  Node(T data);
  // destructor
  ~Node();
  // accessors
  T get_data(void);
  Node *get_left_link(void);
  Node *get_right_link(void);
  // mutators
  void set_data(T data);
  void set_left_link(Node *left);
  void set_right_link(Node *right);

  static void print_in_order(Node *node);
};

template <class T>
class BST {
private:
  Node<T> *root;

  Node<T> *insert_at_node(const T data, Node<T> *node);
  Node<T> *search_at_node(const T data, Node<T> *node);
  Node<T> *get_parent_node(Node<T> *node, Node<T> *child);

public:
  // constructor
  BST();
  // destructor
  ~BST();
  // typical BST functions
  Node<T> *insert(const T data);
  void     remove(const T data);
  Node<T> *in_order_successor(Node<T> *node);
	void     transplant(Node<T> *node1, Node<T> *node2);
  Node<T> *minimum(Node<T> *node);
  Node<T> *maximum(Node<T> *node);
  void print();
};

#endif