#ifdef _WIN32
#include "array.c"
#elif __APPLE__
#include "array.h"
#elif __linux__
#include "array.h"
#endif

#include <stdbool.h>

void cocktail_sort(Arr_T A) {
  bool swapped = true;
  int s = 0;
  int e = A.size - 1;
  while (swapped) {
    swapped = false;
    int i;
    for (i = s; i < e; i++) {
      if (A.arr[i] > A.arr[i + 1]) {
        swap(i, i + 1, A);
        swapped = true;
      }
    }
    if (!swapped)
      break;
    swapped = false;
    e--;
    for (i = e - 1; i >= s; i--) {
      if (A.arr[i] > A.arr[i + 1]) {
        swap(i, i + 1, A);
        swapped = true;
      }
    }
    s++;
  }
}

void sort(Arr_T A) { cocktail_sort(A); }

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
  print_Arr(M);
  cocktail_sort(M);
  print_Arr(M);
  return 0;
}
#endif
