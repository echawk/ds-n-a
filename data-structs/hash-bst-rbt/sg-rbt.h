#ifndef SG_RBT_H
#define SG_RBT_H

#include "sg-bst.h"

typedef enum { RED, BLACK } color_t;

class RBNode : Node {
private:
  color_t color;

public:
  // constructors
  RBNode(int data);
  RBNode(int data, color_t color);
  // destructor
  ~RBNode();
  // accessor
  color_t get_color(void);
  // mutator
  void set_color(color_t color);
};

class RBT : BST {
private:
  RBNode *root;

public:
  RBT();

  ~RBT();

  RBNode *insert(const int data);
  RBNode *remove(const int data);
};

#endif