#ifndef SG_RBT_H
#define SG_RBT_H

#include "sg-bst.h"

typedef enum { RED, BLACK } color_t;

class RBNode : Node {
private:
  color_t color;

	RBNode *left;
	RBNode *right;
	RBNode *parent;
public:
  // constructors
  RBNode(int data);
  RBNode(int data, color_t color);
  // destructor
  ~RBNode();
  // accessor
  color_t get_color(void);
	int get_data(void);
  RBNode *get_left_link(void);
  RBNode *get_right_link(void);
  RBNode *get_parent_link(void);
  // mutator
  void set_color(color_t color);
	void set_data(int data);
  void set_left_link(RBNode *left);
  void set_right_link(RBNode *right);
  void set_parent_link(RBNode *parent);
};

class RBT : BST {
private:
	RBNode * const SENTINEL = nullptr;
  RBNode *root = SENTINEL;
	RBNode *insert_at_node(const int data, RBNode *node);
  RBNode *search_at_node(const int data, RBNode *node);
public:
  RBT();

  ~RBT();

  RBNode *insert(const int data);
  RBNode *remove(const int data);
};

#endif