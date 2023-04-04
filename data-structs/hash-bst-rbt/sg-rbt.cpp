#include <iostream>

#include "sg-rbt.h"

// constructors

RBNode::RBNode(int data) {
  this->set_data(data);
  this->color = RED;
}

RBNode::RBNode(int data, color_t color) {
  this->set_data(data);
  this->color = color;
}

// accessor

color_t RBNode::get_color(void) { return this->color; }

// mutator

void RBNode::set_color(color_t color) { this->color = color; }

// typical RBT functions

RBT::RBT() { root = nullptr; }

RBT::~RBT() { free(root); }