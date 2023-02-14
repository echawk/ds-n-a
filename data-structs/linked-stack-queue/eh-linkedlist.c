#include "eh-linkedlist.h"

int main() {

  int v = 1;

  LinkedList_T ll = make_LinkedList(v);

  print_LinkedList(ll);
  for (int i = 2; i < 11; i++) {
    appendTo_LinkedList(&ll, i);
  }
  print_LinkedList(ll);

  removeAt_LinkedList(&ll, 2);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);

  insertAt_LinkedList(&ll, 2, 7);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);

  for (int i = 9; i > 0; i--) {
    prependTo_LinkedList(&ll, i);
  }
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);

  removeFirst_LinkedList(&ll);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);

  removeLast_LinkedList(&ll);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);

  return 0;
}
