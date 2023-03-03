#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
};

class LinkedList {
public:
  Node *head;

  LinkedList() { head = NULL; }

  void addToEnd(int);
  void addToFront(int);
  Node *findNode(int);
  void deleteNode(int, Node **);
  void removeFirst(Node **);
  void removeLast(Node **);
  int listSize(Node *);
  void printList(Node *);
};

void LinkedList::addToEnd(int s) {
  Node *newNode = new Node(s);
  if (head == NULL) {
    head = newNode;
  } else {
    Node *curr = head;
    if (curr != NULL) {
      while (curr->next != NULL) {
        curr = curr->next;
      }
    }
    curr->next = newNode;
  }
}

void LinkedList::addToFront(int s) {
  Node *newNode = new Node(s, NULL);
  if (head == NULL) {
    head = newNode;
  } else {
    Node *temp = head;
    newNode = new Node(s, temp);
    head = newNode;
  }
}

Node *LinkedList::findNode(int s) {
  Node *curr = head;
  if (head != NULL) {
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

void LinkedList::deleteNode(int s, Node **n) {
  Node *curr = *n;
  Node *prev = NULL;
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

void LinkedList::removeFirst(Node **n){
  Node *curr = *n;
  Node *newHead = curr->next;
  free(curr);
  head = newHead;
}

void LinkedList::removeLast(Node **n){
  Node *curr = *n;
  Node *prev = NULL;
  if (n != NULL) {
    while (curr->next != NULL) {
      prev = curr;
      curr = curr->next;
    }
    if (curr->next == NULL) {
      prev->next = NULL;
    }
    free(curr);
  } else {
    printf("The list is empty!\n");
  }
}

int LinkedList::listSize(Node *n) {
  Node *curr;
  int count = 0;
  for (curr = n; curr != NULL; curr = curr->next) {
    count++;
  }
  return count;
}

void LinkedList::printList(Node *n) {
  while (n != NULL) {
    printf("%d ", n->data);
    n = n->next;
  }
}

/*
int main() {
  srand((unsigned)time(NULL));
  LinkedList list = LinkedList();
  list.addToEnd(rand() % 50);
  list.addToEnd(rand() % 50);
  list.addToEnd(11);
  list.addToEnd(rand() % 50);
  list.addToEnd(rand() % 50);
  list.addToEnd(19);
  list.addToFront(25);
  printf("Original list: ");
  list.printList(list.head);
  printf("\n");
  printf("\tList size: %d", list.listSize(list.head));
  //list.deleteNode(11, &list.head);
  //list.removeFirst(&list.head);
  list.removeLast(&list.head);
  printf("\nNew list: ");
  list.printList(list.head);
  printf("\n");
  printf("\tList size: %d", list.listSize(list.head));
  return 0;
}*/