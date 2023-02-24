#ifndef SG_BST_H
#define SG_BST_H

class Node {
private:
  int data;
  Node *left;
  Node *right;

public:
  // constructor
  Node(int data);
  // destructor
  ~Node();
  // accessors
  int get_data(void);
  Node *get_left_link(void);
  Node *get_right_link(void);
  // mutators
  void set_data(int data);
  void set_left_link(Node *left);
  void set_right_link(Node *right);

  static void print_in_order(Node *node);
};

class BST {
private:
  Node *head;

  Node *insert_at_node(const int data, Node *node);
  Node *search_at_node(const int data, Node *node);
	Node *get_parent_node(Node *node, Node *child);

public:
  // constructor
  BST();
  // destructor
  ~BST();
  // typical BST functions
  Node *insert(const int data);
  Node *remove(const int data);
	Node *in_order_successor(Node *node);
  Node *minimum(Node *node);
  Node *maximum(Node *node);
  void print();
};

#endif