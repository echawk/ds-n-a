#ifdef _WIN32
#include "array.c"
#elif __APPLE__
#include "array.h"
#elif __linux__
#include "array.h"
#endif

#include <stdio.h>
#include <time.h>

int getMax(Arr_T A) {
  int max = A.arr[0];
  for (int i = 1; i < A.size; i++) {
    if (A.arr[i] > max) {
      max = A.arr[i];
    }
  }
  return max;
}

void counting_sort(Arr_T A) {
  Arr_T output = make_Arr(A.size);
  int max = getMax(A);
  int *count = calloc(max + 1, sizeof(int));
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
  for (int j = 0; j < A.size; j++) {
    count[A.arr[j]]++;
  }
  for (int k = 1; k <= max; k++) {
    count[k] += count[k - 1];
  }
  for (int n = A.size - 1; n >= 0; n--) {
    output.arr[count[A.arr[n]] - 1] = A.arr[n];
    count[A.arr[n]]--;
  }
  for (int m = 0; m < A.size; m++) {
    A.arr[m] = output.arr[m];
  }
}

#ifndef ASLIB
int main(int argc, char *argv[]) {
  int arr_size;
  clock_t start, end;
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
  start = clock();
  counting_sort(M);
  end = clock();
  printf("\nArray after sorting: \n");
  print_Arr(M);
  double duration = ((double)end-start)/CLOCKS_PER_SEC;
  printf("\nThe execution time of the counting sort algorithm is: %10f", duration);
  return 0;
}
#endif