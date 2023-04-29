#ifdef _WIN32
#include "array.c"
#elif __APPLE__
#include "array.h"
#elif __linux__
#include "array.h"
#endif

#include <stdbool.h>
#include <stdio.h>

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
  if (argc > 1) {
    if (sscanf(argv[1], "%i", &arr_size) != 1) {
      fprintf(stderr, "[ERR] - Not an integer!");
      return 1;
    }
  } else {
    arr_size = 100;
  }
  Arr_T M = make_Arr(arr_size); // Create Array
  populate_Arr(M);              // Populate Array
  print_Arr(M);                 // Print initial array
  shell_sort(M);                // Sorts array with my Shell Short method
  print_Arr(M);                 // Print end array
  return 0;
}
#endif
