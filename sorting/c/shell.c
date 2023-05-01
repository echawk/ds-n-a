#ifdef _WIN32
#include "array.c"
#elif __APPLE__
#include "array.h"
#elif __linux__
#include "array.h"
#endif

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

void shell_sort(Arr_T A) {
  int gap = A.size / 2;
  while (gap > 0) {
    int x = gap;

    while (x < A.size) {
      int y = x - gap;

      while (y >= 0) {
        if (A.arr[y + gap] > A.arr[y]) {
          break;
        } else {
          swap(y, y + gap, A);
        }
        y = y - gap;
      }
      x = x + 1;
    }
    gap = gap / 2;
  }
}

void sort(Arr_T A) { shell_sort(A); }

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
  shell_sort(M);
  end = clock();
  printf("\nArray after sorting: \n");
  print_Arr(M);
  double duration = ((double)end-start)/CLOCKS_PER_SEC;
  printf("\nThe execution time of the shell sort algorithm is: %10f", duration);
  return 0;
}
#endif
