// Nicholas Koeppen

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
  int data;
  struct Data *leftChild;
  struct Data *rightChild;
} Node;

Node *insert(Node *current, int insert) {
  Node *tempNode = (Node *)malloc(sizeof(Node));
  Node *parent = NULL;

  tempNode->data = insert;
  tempNode->leftChild = NULL;
  tempNode->rightChild = NULL;

  if (current == NULL) { // empty tree
    current = tempNode;
    return current;
  } else {
    while (true) {
      parent = current;

      if (insert == current->data) { // Node is already in tree
        return current;
      } else if (insert < current->data) { // Go to left child
        current = current->leftChild;

        if (current == NULL) {
          parent->leftChild = tempNode;
          return parent->leftChild;
        }
      } else { // Go to right child
        current = current->rightChild;

        if (current == NULL) {
          parent->rightChild = tempNode;
          return parent->rightChild;
        }
      }
    }
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
    insert(root, current->data);
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
  Node *root = insert(NULL, 14);
  // printf("%d\n", root->data);
  insert(root, 14);
  insert(root, 20);
  insert(root, 10);
  insert(root, 21);
  insert(root, 22);
  insert(root, 4);
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
