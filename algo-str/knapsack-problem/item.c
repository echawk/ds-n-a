#include "item.h"

// Thanks to StackOverflow for some inspiration
// https://stackoverflow.com/questions/17846212/generate-a-random-number-between-1-and-10-in-c
int randRange(const int min, const int max) {
  int randNum = rand() % (max - min) + min;
  return randNum;
}

void printList(item list[]) {
  for (int i = 0; i < listSize; i++) {
    if (list[i].value != 0) {
      printf("Item %d -- Value: %d   Weight: %d\n", i + 1, list[i].value,
             list[i].weight);
    }
  }
}

void printRatio(item list[]) {
  for (int i = 0; i < listSize; i++) {
    printf("Item Ratio: %.4f\n", list[i].ratio);
  }
}

int generateWeight(int val) {
  int weight = 0;
  if (val < 4) {
    weight = randRange(1, 5);
  } else if (val > 3 && val < 7) {
    weight = randRange(3, 8);
  } else { // val > 6
    weight = randRange(6, 11);
  }
  return weight;
}

void populateList(item list[]) {
  for (int i = 0; i < listSize; i++) {
    list[i].value = randRange(1, 10);
    list[i].weight = generateWeight(list[i].value);
    list[i].ratio = (double)list[i].value / (double)list[i].weight;
  }
}

void swap(item *a, item *b) {
  item temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(item list[]) {
  for (int i = 0; i < listSize - 1; i++) {
    for (int j = i + 1; j < listSize; j++) {
      if (list[i].ratio > list[j].ratio) {
        swap(&list[i], &list[j]);
      }
    }
  }
}

void reverse(item list[], int start, int end) {
  int temp;
  if (start >= end) {
    return;
  }
  swap(&list[start], &list[end]);
  reverse(list, start + 1, end - 1);
}

bool withinArray(item list[], int value) {
  for (int i = 0; i < listSize; i++) {
    if (value == list[i].value) {
      return true;
    }
  }
  return false;
}

int getIndex(item list[], int value) {
  for (int i = 0; i < listSize; i++) {
    if (value == list[i].value) {
      return i;
    }
  }
}