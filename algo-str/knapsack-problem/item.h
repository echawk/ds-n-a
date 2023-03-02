#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define listSize 10

typedef struct Item {
  int value, weight;
  double ratio;
} item;

int randRange(const int min, const int max);
void printList(item list[]);
void printRatio(item list[]);
int generateWeight(int val);
void populateList(item list[]);
void swap(item *a, item *b);
void bubbleSort(item list[]);
void reverse(item list[], int start, int end);
bool withinArray(item list[], int value);
int getIndex(item list[], int value);