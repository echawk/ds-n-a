#include "cg-linkedlist.h"

int main() {
  clock_t start, end;
  double duration;
  LL_T *linked = createList();
  start = clock();
  addToEnd(linked, 19);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf(
      "\nThe duration to add an element to the end of a linked list is: %10f\n",
      duration);
  addToEnd(linked, 20);
  start = clock();
  addToFront(linked, 1);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to add an element to the front of a linked list is: "
         "%10f\n",
         duration);
  addToFront(linked, 15);
  addToEnd(linked, 10);
  addToEnd(linked, 5);
  printList(linked);
  start = clock();
  Node_T *found = findNode(linked, 19);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to find an element in a linked list is: %10f\n",
         duration);
  printf("\nThe node that was found contains %d\n\n", found->data);
  start = clock();
  deleteNode(linked, 20);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf(
      "\nThe duration to delete a specific element in a linked list is: %10f\n",
      duration);
  printList(linked);
  start = clock();
  removeFirst(linked);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to delete an element from the front of a linked list "
         "is: %10f\n",
         duration);
  printList(linked);
  start = clock();
  removeLast(linked);
  end = clock();
  duration = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\nThe duration to delete an element from the end of a linked list "
         "is: %10f\n",
         duration);
  printList(linked);
  return 0;
}