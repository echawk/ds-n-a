// Nicholas Koeppen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK 0
#define RED 1

typedef struct Data {
  int data, color;
  struct Data *parentNode, *leftChild, *rightChild;
} Node;

void rotateLeft(Node **rootPointer, Node *x) {
  if (!x || !x->rightChild) {
    return;
  }

  // y stored pointer of right child of x
  Node *y = x->rightChild;

  // store y's left subtree's pointer as x's right child
  x->rightChild = y->leftChild;

  // update parent pointer of x's right
  if (x->rightChild != NULL) {
    x->rightChild->parentNode = x;
  }

  // update y's parent pointer
  y->parentNode = x->parentNode;

  // if x's parent is null make y as root of tree
  if (x->parentNode == NULL) {
    (*rootPointer) = y;
  } else if (x == x->parentNode->leftChild) { // store y at the place of x
    x->parentNode->leftChild = y;
  } else {
    x->parentNode->rightChild = y;
  }

  // make x as left child of y
  y->leftChild = x;

  // update parent pointer of x
  x->parentNode = y;
}

void rotateRight(Node **rootPointer, Node *y) {
  if (!y || !y->leftChild) {
    return;
  }

  Node *x = y->leftChild;
  y->leftChild = x->rightChild;
  if (x->rightChild != NULL)
    x->rightChild->parentNode = y;
  x->parentNode = y->parentNode;
  if (x->parentNode == NULL) {
    (*rootPointer) = x;
  } else if (y == y->parentNode->leftChild) {
    y->parentNode->leftChild = x;
  } else {
    y->parentNode->rightChild = x;
  }
  x->rightChild = y;
  y->parentNode = x;
}

void adjustInsertion(Node **rootPointer, Node *tempNode) {
  // Iterates until tempNode is not the root and tempNode's parent color is red
  while (tempNode != *rootPointer && tempNode->parentNode->color == RED) {
    Node *uncleNode;

    // Find uncle and store uncle in y
    if (tempNode->parentNode == tempNode->parentNode->parentNode->leftChild) {
      uncleNode = tempNode->parentNode->parentNode->rightChild;
    } else {
      uncleNode = tempNode->parentNode->parentNode->leftChild;
    }

    // If uncle is RED, do following
    // (i)  Change color of parent and uncle as BLACK
    // (ii) Change color of grandparent as RED
    // (iii) Move tempNode to grandparent
    if (!uncleNode) {
      tempNode = tempNode->parentNode->parentNode->leftChild;
    } else if (uncleNode->color == RED) {
      uncleNode->color = BLACK;
      tempNode->parentNode->color = BLACK;
      tempNode->parentNode->parentNode->color = RED;
      tempNode = tempNode->parentNode->parentNode;
    } else {
      // Uncle is BLACK, there are four cases (LL, LR, RL and RR)
      // Left-Left (LL) case, do following
      // (i)  Swap color of parent and grandparent
      // (ii) Right Rotate Grandparent
      if (tempNode->parentNode == tempNode->parentNode->parentNode->leftChild &&
          tempNode == tempNode->parentNode->leftChild) {
        int tempColor = tempNode->parentNode->color;
        tempNode->parentNode->color = tempNode->parentNode->parentNode->color;
        tempNode->parentNode->parentNode->color = tempColor;
        rotateRight(rootPointer, tempNode->parentNode->parentNode);
      }

      // Left-Right (LR) case, do following
      // (i)  Swap color of current node  and grandparent
      // (ii) Left Rotate Parent
      // (iii) Right Rotate Grand Parent
      if (tempNode->parentNode == tempNode->parentNode->parentNode->leftChild &&
          tempNode == tempNode->parentNode->rightChild) {
        int tempColor = tempNode->color;
        tempNode->color = tempNode->parentNode->parentNode->color;
        tempNode->parentNode->parentNode->color = tempColor;
        rotateLeft(rootPointer, tempNode->parentNode);
        rotateRight(rootPointer, tempNode->parentNode->parentNode);
      }

      // Right-Right (RR) case, do following
      // (i)  Swap color of parent and grandparent
      // (ii) Left Rotate Grandparent
      if (tempNode->parentNode ==
              tempNode->parentNode->parentNode->rightChild &&
          tempNode == tempNode->parentNode->rightChild) {
        int tempColor = tempNode->parentNode->color;
        tempNode->parentNode->color = tempNode->parentNode->parentNode->color;
        tempNode->parentNode->parentNode->color = tempColor;
        rotateLeft(rootPointer, tempNode->parentNode->parentNode);
      }

      // Right-Left (RL) case, do following
      // (i)  Swap color of current node  and grandparent
      // (ii) Right Rotate Parent
      // (iii) Left Rotate Grand Parent
      if (tempNode->parentNode ==
              tempNode->parentNode->parentNode->rightChild &&
          tempNode == tempNode->parentNode->leftChild) {
        int tempColor = tempNode->color;
        tempNode->color = tempNode->parentNode->parentNode->color;
        tempNode->parentNode->parentNode->color = tempColor;
        rotateRight(rootPointer, tempNode->parentNode);
        rotateLeft(rootPointer, tempNode->parentNode->parentNode);
      }
    }
  }
  (*rootPointer)->color = BLACK; // keep root always black
}

Node *insert(Node **rootPointer, int newData) {
  Node *tempNode = (Node *)malloc(sizeof(Node));
  Node *parent = NULL;

  tempNode->data = newData;
  tempNode->leftChild = NULL;
  tempNode->rightChild = NULL;
  tempNode->parentNode = NULL;

  if (*rootPointer == NULL) { // empty tree
    tempNode->color = BLACK;
    (*rootPointer) = tempNode;
  } else { // non-empty tree
    Node *root = (*rootPointer);
    while (root != NULL) {
      parent = root;
      if (tempNode->data < root->data) {
        root = root->leftChild;
      } else {
        root = root->rightChild;
      }
    }
    tempNode->parentNode = parent;
    if (tempNode->data > parent->data) {
      parent->rightChild = tempNode;
    } else {
      parent->leftChild = tempNode;
    }
    tempNode->color = RED;

    // adjust insert to accomodate rb-tree color properties
    adjustInsertion(rootPointer, tempNode);
  }
}

Node *search(Node *current, int find) {
  while (current->data != find) {
    if (current != NULL) {
      if (current->data > find) { // Go to left child
        current = current->leftChild;
      } else { // Go to right child
        current = current->rightChild;
      }

      if (current == NULL) {
        return NULL;
      }
    }
  }
  return current;
}

void rebalance(Node *root,
               Node *current) { // not necessary, BST doesn't need to balance
  if (current != NULL) {
    insert(&root, current->data);
    rebalance(root, current->leftChild);
    rebalance(root, current->rightChild);
  }
}

// Returns Minimum Value Node
Node *minValueNode(Node *node) { // Based on GeeksforGeeks
  Node *current = node;

  // loop down to find the leftmost leaf
  while (current && current->leftChild != NULL)
    current = current->leftChild;

  return current;
}

Node *deleteNode(Node *root, int key) { // Based on GeeksforGeeks
  if (root == NULL) {
    return root;
  }

  // Find node to be deleted
  if (key < root->data) {
    root->leftChild = deleteNode(root->leftChild, key);
  } else if (key > root->data) {
    root->rightChild = deleteNode(root->rightChild, key);
  } else { // Else, node to be deleted is head node
    // node with only one child or no child
    if (root->leftChild == NULL) {
      Node *temp = root->rightChild;
      free(root);
      return temp;
    } else if (root->rightChild == NULL) {
      Node *temp = root->leftChild;
      free(root);
      return temp;
    }

    // node with two children:
    // Get the inorder successor
    // (smallest in the right subtree)
    Node *temp = minValueNode(root->rightChild);

    // Copy the inorder
    // successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->rightChild = deleteNode(root->rightChild, temp->data);
  }
  return root;
}

void printTree(Node *root, int level) { // From Stack Overflow
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < level; i++) {
    printf(i == level - 1 ? "  |-" : "    ");
  }
  printf("(%d)\n", root->data);
  printTree(root->leftChild, level + 1);
  printTree(root->rightChild, level + 1);
}

void temp_print_in_order(Node *node) {
  if (node == NULL) {
    return;
  }
  temp_print_in_order(node->leftChild);
  printf("%d ", node->data);
  temp_print_in_order(node->rightChild);
}

int main() {
  Node *root = NULL;
  // printf("%d\n", root->data);
  insert(&root, 14);
  insert(&root, 20);
  insert(&root, 10);
  insert(&root, 21);
  insert(&root, 22);
  insert(&root, 4);
  // printf("%d\n", root->leftChild->data);
  // printf("%d\n", root->rightChild->data);
  printTree(root, 0);
  // temp_print_in_order(root);
  deleteNode(root, 21);
  printf("\nDeleted Node w/ 21\n");
  printTree(root, 0);
  // temp_print_in_order(root);
  deleteNode(root, 14);
  printf("\nDeleted Head Node\n");
  printTree(root, 0);
  // temp_print_in_order(root);
  printf("\n");
}