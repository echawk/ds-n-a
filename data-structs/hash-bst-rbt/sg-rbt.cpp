#include <iostream>

#include "sg-rbt.h"

// constructors

RBNode::RBNode(int data) { this->data = data; }

RBNode::RBNode(int data, color_t color) {
  this->data = data;
  this->color = color;
}

// destructors

RBNode::~RBNode() {
  if (this->left)
    free(this->left);
  if (this->right)
    free(this->right);
  // we don't free the parent link as it may be needed
  // would cause chain reaction and kill entire tree
}

// accessors

color_t RBNode::get_color(void) { return this->color; }
RBNode *RBNode::get_left_link(void) { return this->left; }
RBNode *RBNode::get_right_link(void) { return this->right; }
RBNode *RBNode::get_parent_link(void) { return this->parent; }

// mutators

void RBNode::set_data(int data) { this->data = data; }
void RBNode::set_color(color_t color) { this->color = color; }
void RBNode::set_left_link(RBNode *left) { this->left = left; }
void RBNode::set_right_link(RBNode *right) { this->right = right; }
void RBNode::set_parent_link(RBNode *parent) { this->parent = parent; }

// typical RBT functions

// destructor

RBT::~RBT() {
  if (root)
    free(root);
}

// private funcs

void RBT::left_rotation(RBNode *node) {
  RBNode *temp = node->get_right_link();

  node->set_right_link(temp->get_left_link());
  if (temp->get_left_link() != nullptr) {
    temp->get_left_link()->set_parent_link(node);
  }
  temp->set_parent_link(node->get_parent_link());

  if (node->get_parent_link() == nullptr) {
    this->root = temp;
  } else if (node == node->get_parent_link()->get_left_link()) {
    node->get_parent_link()->set_left_link(temp);
  } else {
    node->get_parent_link()->set_right_link(temp);
  }

  temp->set_left_link(node);
  node->set_parent_link(temp);

  return;
}

void RBT::right_rotation(RBNode *node) {
  RBNode *temp = node->get_left_link();

  node->set_left_link(temp->get_right_link());
  if (temp->get_right_link() != nullptr) {
    temp->get_right_link()->set_parent_link(node);
  }
  temp->set_parent_link(node->get_parent_link());

  if (node->get_parent_link() == nullptr) {
    this->root = temp;
  } else if (node == node->get_parent_link()->get_right_link()) {
    node->get_parent_link()->set_right_link(temp);
  } else {
    node->get_parent_link()->set_left_link(temp);
  }

  temp->set_right_link(node);
  node->set_parent_link(temp);

  return;
}

void RBT::insert_correction(RBNode *node) {
  while (node->get_parent_link()->get_color() == RED) {
    if (node->get_parent_link() ==
        node->get_parent_link()->get_parent_link()->get_left_link()) {
      RBNode *temp_y =
          node->get_parent_link()->get_parent_link()->get_right_link();
      if (temp_y->get_color() == RED) {
        node->get_parent_link()->set_color(BLACK);
        temp_y->set_color(BLACK);
        node->get_parent_link()->get_parent_link()->set_color(RED);
        node = node->get_parent_link()->get_parent_link();
      } else {
        if (node == node->get_parent_link()->get_right_link()) {
          node = node->get_parent_link();
          this->left_rotation(node);
        }
        node->get_parent_link()->set_color(BLACK);
        node->get_parent_link()->get_parent_link()->set_color(RED);
        this->right_rotation(node->get_parent_link()->get_parent_link());
      }
    } else {
      RBNode *temp_y =
          node->get_parent_link()->get_parent_link()->get_left_link();
      if (temp_y->get_color() == RED) {
        node->get_parent_link()->set_color(BLACK);
        temp_y->set_color(BLACK);
        node->get_parent_link()->get_parent_link()->set_color(RED);
        node = node->get_parent_link()->get_parent_link();
      } else {
        if (node == node->get_parent_link()->get_left_link()) {
          node = node->get_parent_link();
          this->right_rotation(node);
        }
        node->get_parent_link()->set_color(BLACK);
        node->get_parent_link()->get_parent_link()->set_color(RED);
        this->left_rotation(node->get_parent_link()->get_parent_link());
      }
    }
  }

  this->root->set_color(BLACK);

  return;
}

void RBT::remove_correction(RBNode *node) {
  // todo: code
}

void RBT::transplant(RBNode *u, RBNode *v) {
  if (u->get_parent_link() == nullptr) {
    this->root = v;
  } else if (u == u->get_parent_link()->get_left_link()) {
    u->get_parent_link()->set_left_link(v);
  } else {
    u->get_parent_link()->set_right_link(v);
  }

  v->set_parent_link(u->get_parent_link());

  return;
}

// public funcs

RBNode *RBT::insert(const int data) {
  RBNode *temp_x = this->root;
  RBNode *temp_y = nullptr;
  RBNode *new_z = new RBNode(data);

  while (temp_x != nullptr) {
    temp_y = temp_x;
    if (data < temp_x->get_data())
      temp_x = temp_x->get_left_link();
    else
      temp_x = temp_x->get_right_link();
  }

  new_z->set_parent_link(temp_y);
  if (temp_y == nullptr) {
    this->root = new_z;
  } else if (new_z->get_data() < temp_y->get_data()) {
    temp_y->set_left_link(new_z);
  } else {
    temp_y->set_right_link(new_z);
  }

  this->insert_correction(new_z);

  return;
}

RBNode *RBT::remove(RBNode *z) {
  RBNode *x;
  RBNode *y = z;
  color_t y_original_color = y->get_color();

  if (z->get_left_link() == nullptr) {
    x = z->get_right_link();
    this->transplant(z, z->get_right_link());
  } else if (z->get_right_link() == nullptr) {
    x = z->get_left_link();
    this->transplant(z, z->get_left_link());
  } else {
    y = this->minimum(z->get_right_link());
    y_original_color = y->get_color();
    x = y->get_right_link();
    if (y != z->get_right_link()) {
      this->transplant(y, y->get_right_link());
      y->set_right_link(z->get_right_link());
      y->get_right_link()->set_parent_link(y);
    } else {
      x->set_parent_link(y);
      this->transplant(z, y);
      y->set_left_link(z->get_left_link());
      y->get_left_link()->set_parent_link(y);
      y->set_color(z->get_color());
    }
  }

  if (y_original_color == BLACK) {
    this->remove_correction(x);
  }

  return;
}

RBNode *RBT::minimum() {
  RBNode *temp = this->root;

  while (temp->get_left_link() != nullptr) {
    temp = temp->get_left_link();
  }

  return temp;
}

RBNode *RBT::minimum(RBNode *node) {
  RBNode *temp = node;

  while (temp->get_left_link() != nullptr) {
    temp = temp->get_left_link();
  }

  return temp;
}

RBNode *RBT::maximum() {
  RBNode *temp = this->root;

  while (temp->get_right_link() != nullptr) {
    temp = temp->get_right_link();
  }

  return temp;
}

RBNode *RBT::maximum(RBNode *node) {
  RBNode *temp = node;

  while (temp->get_right_link() != nullptr) {
    temp = temp->get_right_link();
  }

  return temp;
}
