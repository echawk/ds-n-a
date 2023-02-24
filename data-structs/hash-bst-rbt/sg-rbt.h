#ifndef SG_RBT_H
#define SG_RBT_H

#include "sg-bst.h"

typedef enum {RED, BLACK} color_t;

class RBNode {
private:
	color_t color;
  Node node;
public:
  // constructors
  RBNode(int data);
  RBNode(int data, color_t color);
  // destructor
  ~RBNode();
  // accessors
  int get_data(void);
	color_t get_color(void);
  Node *get_left_link(void);
  Node *get_right_link(void);
  // mutators
  void set_data(int data);
	void set_color(color_t color);
  void set_left_link(Node *left);
  void set_right_link(Node *right);

  static void print_in_order(Node *node);
};

class RBT {
private:
	RBNode root;
public:

};

#endif