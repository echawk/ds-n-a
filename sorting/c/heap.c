#ifdef _WIN32
#include "array.c"
#elif __APPLE__
#include "array.h"
#elif __linux__
#include "array.h"
#endif

#include <stdio.h>

void heapify(Arr_T A, int N, int i) {
  int largest = i;
  int left = (2 * i) + 1;
  int right = (2 * i) + 2;
  if (left < N && A.arr[left] > A.arr[largest]) {
    largest = left;
  }
  if (right < N && A.arr[right] > A.arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(i, largest, A);
    heapify(A, N, largest);
  }
}

void heapSort(Arr_T A, int N) {
  for (int i = (N / 2 - 1); i >= 0; i--) {
    heapify(A, N, i);
  }
  for (int j = (N - 1); j >= 0; j--) {
    swap(0, j, A);
    heapify(A, j, 0);
  }
}

void sort(Arr_T A) { heapSort(A, A.size); }

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
  heapSort(M, M.size);
  printf("Array after sorting: \n");
  print_Arr(M);
  return 0;
}
#endif