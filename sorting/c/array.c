#include "array.h"
#include <stdlib.h>

Arr_T make_Arr(int size) {
  return (Arr_T){.size = size, .arr = calloc(size, sizeof(int))};
}

Arr_T combine_Arrs(Arr_T A, Arr_T B) {
  Arr_T N = make_Arr(A.size + B.size);
  N.arr = calloc(N.size, sizeof(int));
  int i;
  for (i = 0; i < A.size; i++) {
    N.arr[i] = A.arr[i];
  }
  for (i = A.size; i < N.size; i++) {
    N.arr[i] = B.arr[i - A.size];
  }
  return N;
}

void populate_Arr(Arr_T A) {
  int i = 0;
  for (i = 0; i < A.size; i++) {
    A.arr[i] = rand() % A.size;
  }
}

void sorted_populate_Arr(Arr_T A) {
  int i = 0;
  for (i = 0; i < A.size; i++) {
    A.arr[i] = i + 1;
  }
}

// Thank you once again stackoverflow.
// https://stackoverflow.com/questions/6127503/shuffle-array-in-c#6127606
void shuffle_Arr(Arr_T A) {
  if (A.size > 1) {
    int i;
    for (i = 0; i < A.size; i++) {
      int j = i + rand() / (RAND_MAX / (A.size - i) + 1);
      swap(i, j, A);
    }
  }
}

bool within_Arr(int val, Arr_T A) {
  int i = 0;
  for (i = 0; i < A.size; i++) {
    if (val == A.arr[i]) {
      return true;
    }
  }
  return false;
}

int largestIndIn_Arr(Arr_T A) {
  int li = 0;
  int i = 0;
  for (i = 0; i < A.size; i++) {
    if (A.arr[i] > A.arr[li]) {
      li = i;
    }
  }
  return li;
}

void print_Arr(Arr_T A) {
  int i = 0;
  printf("[");
  for (i = 0; i < A.size - 1; i++) {
    printf("%d,", A.arr[i]);
  }
  printf("%d]\n", A.arr[i]);
}

void reverse_Arr(int start, int end, Arr_T A){
  int temp;
  if (start >= end){
    return;
  }
swap(start, end, A);
reverse_Arr(start + 1, end - 1, A);
}

#ifndef VISUALIZE
void swap(int ind1, int ind2, Arr_T A) {
  if (A.arr[ind1] != A.arr[ind2]) {
    A.arr[ind1] = A.arr[ind1] ^ A.arr[ind2];
    A.arr[ind2] = A.arr[ind1] ^ A.arr[ind2];
    A.arr[ind1] = A.arr[ind1] ^ A.arr[ind2];
  }
}
#endif