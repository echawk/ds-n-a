#include <iostream>

#include "sg-bst.h"

int main(void) {
  BST tree;

  tree.insert(1);
  tree.insert(-10);
  tree.insert(22);
  tree.insert(12);
  tree.insert(19);
  tree.insert(6);
  tree.print();
	tree.remove(19);
  tree.print();
	tree.remove(-10);
  tree.print();
	tree.remove(1);
  tree.print();
	tree.remove(6);
  tree.print();
	tree.remove(12);
  tree.print();
	tree.remove(22);
  tree.print();

  return 0;
}