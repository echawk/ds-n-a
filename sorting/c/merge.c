#include "array.c"
#include <stdio.h>

void copyArray(Arr_T A, Arr_T copy, int end, int index) {
  for (int i = 0; i < end; i++) {
    copy.arr[i] = A.arr[index + i];
  }
}

void merge(Arr_T A, int left, int middle, int right) {
  int leftSize = middle - left + 1;
  int rightSize = right - middle;
  Arr_T leftA = make_Arr(leftSize);
  Arr_T rightA = make_Arr(rightSize);
  copyArray(A, leftA, leftSize, left);
  copyArray(A, rightA, rightSize, middle + 1);
  int i = 0, j = 0, k = left;
  while (i < leftSize && j < rightSize) {
    if (leftA.arr[i] <= rightA.arr[j]) {
      A.arr[k] = leftA.arr[i];
      i++;
    } else {
      A.arr[k] = rightA.arr[j];
      j++;
    }
    k++;
  }
  while (i < leftSize) {
    A.arr[k] = leftA.arr[i];
    i++;
    k++;
  }
  while (j < rightSize) {
    A.arr[k] = rightA.arr[j];
    j++;
    k++;
  }
}

void mergeSort(Arr_T A, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    mergeSort(A, left, middle);
    mergeSort(A, middle + 1, right);
    merge(A, left, middle, right);
  }
}

// void sort(Arr_T A) { mergeSort(A, 0, A.size - 1); }

#ifndef ASLIB
int main(int argc, char *argv[]) {
  int arr_size;
  if (argc > 1) {
    if (sscanf(argv[1], "%i", &arr_size) != 1) {
      fprintf(stderr, "[ERR] - Not an integer!");
      return 1;
    }
  } else {
    arr_size = 100;
  }
  Arr_T M = make_Arr(arr_size);
  populate_Arr(M);
  printf("Array before sorting: \n");
  print_Arr(M);
  mergeSort(M, 0, M.size - 1);
  printf("Array after sorting: \n");
  print_Arr(M);
  return 0;
}
#endif