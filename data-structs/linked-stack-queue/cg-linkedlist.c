#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char *data;
  struct Node *next;
} node;

void printList(node *n) {
  while (n != NULL) {
    printf("%s ", n->data);
    n = n->next;
  }
}

int listSize(node *n) {
  node *curr;
  int count = 0;
  for (curr = n; curr != NULL; curr = curr->next) {
    count++;
  }
  return count;
}

/*function to create a node with data/link
 * and giving it a space in memory*/
node *createNode(char *s, node *n) {
  node *newNode;
  newNode = (node *)malloc(sizeof(node));
  newNode->data = s;
  newNode->next = n;
  return newNode;
}

node *findNode(char *s, node *n) {
  node *curr = n;
  if (n != NULL) {
    while (curr->data != s) {
      if (curr->next != NULL) {
        curr = curr->next;
      }
    }
  } else {
    printf("This node does not exist!\n");
  }
  return curr;
}

void deleteNode(char *s, node **n) {
  node *curr = *n;
  node *prev = NULL;
  if (n != NULL) {
    while (curr->data != s) {
      if (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
      }
    }
    if (curr == *n) {
      *n = curr->next;
    } else {
      prev->next = curr->next;
    }
    free(curr);
  } else {
    printf("The list is empty!\n");
  }
}

/*Main will be removed later. Here for testing purposes
int main(){
    node* sixth = createNode("Manjaro", NULL);
    node* fifth = createNode("Ubuntu", sixth);
    node* fourth = createNode("Fedora", fifth);
    node* third = createNode("Arch", fourth);
    node* second = createNode("Mint", third);
    node* head = createNode("Debian", second);
    printf("Original list: ");
    printList(head);
    printf("\n");
    printf("\tList size: %d", listSize(head));
    deleteNode("Ubuntu", &head);
    printf("\nNew list: ");
    printList(head);
    printf("\n");
    printf("\tList size: %d", listSize(head));
    return 0;
}*/
