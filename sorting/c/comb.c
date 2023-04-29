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

const double gapCoeff = 10.0 / 13.0; // value to multiply to get gap

/*Worst case performace: O(n^2)
  Average case performance: Ω(n^2/2^p) where p is number of increments)
  Best case performance: θ(nlogn)*/
void combSort(Arr_T A) {
  int i, j, gap = A.size; // inital gap is size of array
  bool swapped = true;
  while (gap > 1 || swapped) {
    gap = gap * gapCoeff;
    if (gap < 1) {
      gap = 1; // prevents j from being negative
    }
    swapped = false;
    for (i = 0, j = gap; j < A.size; i++, j++) {
      if (A.arr[i] > A.arr[j]) {
        swap(i, j, A);
        swapped = true;
      }
    }
  }
}

void sort(Arr_T A) { combSort(A); }

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
  combSort(M);
  end = clock();
  printf("\nArray after sorting: \n");
  print_Arr(M);
  double duration = ((double)end-start)/CLOCKS_PER_SEC;
  printf("\nThe execution time of the comb sort algorithm is: %10f", duration);
  return 0;
}
#endif
