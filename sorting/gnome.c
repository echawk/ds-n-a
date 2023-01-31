#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "array.h"

void gnome_sort(Arr_T arr) {
  int pos = 0;

  while (pos < arr.size) {
    if ((pos == 0) || (arr.arr[pos] >= arr.arr[pos - 1])) {
      pos += 1;
    } else {
      swap(pos, pos - 1, arr);
      pos -= 1;
    }
  }

  return;
}

void sort(Arr_T arr) { gnome_sort(arr); }

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
  combSort(M);
  printf("Array after sorting: \n");
  print_Arr(M);
  return 0;
}
#endif
