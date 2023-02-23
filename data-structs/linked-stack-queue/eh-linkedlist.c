#include <stdio.h>
#include <unistd.h>

#include "eh-linkedlist.h"

int main() {

  int v = 1;

  LinkedList_T ll = make_LinkedList(v);

  print_LinkedList(ll);
  for (int i = 2; i < 11; i++) {
    appendTo_LinkedList(&ll, i);
  }
  print_LinkedList(ll);
	if(DEBUG_STATEMENTS)
		sleep(1);
  removeAt_LinkedList(&ll, 2);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);

  // insertAt_LinkedList(&ll, 2, 7);
  // print_LinkedList(ll);
  // printf("size of ll: %d\n", ll.size);

  // printf("%x", parentOf_LinkedList(&ll, ll.head)->val);

  for (int i = 9; i > 0; i--) {
    prependTo_LinkedList(&ll, i);
  }
	if(DEBUG_STATEMENTS)
		sleep(1);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);
	if(DEBUG_STATEMENTS)
		sleep(1);
  removeFirst_LinkedList(&ll);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);
	if(DEBUG_STATEMENTS)
		sleep(1);
  removeLast_LinkedList(&ll);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);
	if(DEBUG_STATEMENTS)
		sleep(1);
  Node_T *n = nodeAt_LinkedList(&ll, 3);
  printf("%d\n", n->val);
	if(DEBUG_STATEMENTS)
		sleep(1);
  Node_T *p = parentOf_LinkedList(&ll, n);
  printf("%d\n", p->val);
	if(DEBUG_STATEMENTS)
		sleep(1);
  print_LinkedList(ll);
  swap_LinkedList(&ll, 1, 4);
  print_LinkedList(ll);
  printf("size of ll: %d\n", ll.size);
	if(DEBUG_STATEMENTS)
		sleep(1);
  quickSort_LinkedList(&ll);
  print_LinkedList(ll);
	if(DEBUG_STATEMENTS)
		sleep(1);
  free_LinkedList(&ll);
  return 0;
}
