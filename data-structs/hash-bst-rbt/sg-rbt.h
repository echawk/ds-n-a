#ifndef SG_RBT_H
#define SG_RBT_H

typedef enum { RED, BLACK } color_t;

class RBNode {
private:
  int data;

  color_t color = RED;

  RBNode *left = nullptr;
  RBNode *right = nullptr;
  RBNode *parent = nullptr;

public:
  // inline static RBNode * const SENTINEL = nullptr;
  // down with the sentinel, we're nullptr gang now
  // constructors
  RBNode(int data);
  RBNode(int data, color_t color);
  // destructor
  ~RBNode();
  // accessor
  int get_data(void);
  color_t get_color(void);
  RBNode *get_left_link(void);
  RBNode *get_right_link(void);
  RBNode *get_parent_link(void);
  // mutator
  void set_data(int data);
  void set_color(color_t color);
  void set_left_link(RBNode *left);
  void set_right_link(RBNode *right);
  void set_parent_link(RBNode *parent);
};

class RBT {
private:
  RBNode *root = nullptr;
  void left_rotation(RBNode *node);
  void right_rotation(RBNode *node);
  void insert_correction(RBNode *node);
  void remove_correction(RBNode *node);
  void transplant(RBNode *u, RBNode *v);

public:
  ~RBT();

  RBNode *insert(const int data);
  RBNode *remove(RBNode *z);
  RBNode *minimum();
  RBNode *minimum(RBNode *node);
  RBNode *maximum();
  RBNode *maximum(RBNode *node);
};

#endif