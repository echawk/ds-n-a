#ifdef _WIN32
#include "array.c"
#elif __APPLE__
#include "array.h"
#elif __linux__
#include "array.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG_STATEMENTS 0

int get_max(Arr_T arr) {
  int max = arr.arr[0];

  for (int i = 1; i < arr.size; i++) {
    if (max < arr.arr[i]) {
      max = arr.arr[i];
    }
  }

  return max;
}

int get_place(int num, int place) { return ((num / place) % 10); }

void counting_sort(Arr_T arr, int place) {
  int output[arr.size + 1];
  int max = get_place(arr.arr[0], place);

  for (int i = 1; i < arr.size; i++) {
    if (get_place(arr.arr[i], place) > max) {
      max = arr.arr[i];
    }
  }
  int *count = calloc(max + 1, sizeof(int));
  // count of the elements
  for (int i = 0; i < arr.size; i++) {
    count[get_place(arr.arr[i], place)]++;
  }
  // cumulative count
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  // place everything in sorted order
  for (int i = arr.size - 1; i >= 0; i--) {
    output[count[get_place(arr.arr[i], place)] - 1] = arr.arr[i];
    count[get_place(arr.arr[i], place)]--;
  }

  for (int i = 0; i < arr.size; i++) {
    arr.arr[i] = output[i];
  }

  return;
}

void radix_sort(Arr_T arr) {
  int max = get_max(arr);

  for (int place = 1; max / place > 0; place *= 10) {
    counting_sort(arr, place);
  }
}

void sort(Arr_T arr) { radix_sort(arr); }

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
  radix_sort(M);
  end = clock();
  printf("\nArray after sorting: \n");
  print_Arr(M);
  double duration = ((double)end-start)/CLOCKS_PER_SEC;
  printf("\nThe execution time of the radix sort algorithm is: %10f", duration);
  return 0;
}
#endif
