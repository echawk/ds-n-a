#include <stdint.h>
#include <stdio.h>

#include "array.h"

// function to find the max value in the array
int getMax(Arr_T A) {
  int max = A.arr[0];
  for (int i = 0; i < A.size; i++) {
    if (A.arr[i] > max) {
      max = A.arr[i];
    }
  }
  return max;
}

void bucketSort(Arr_T A) {
  int max = getMax(A); // get max of array
  int bucket[max];     // create max number of buckets
  for (int i = 0; i <= max; i++) {
    bucket[i] = 0; // fill list with 0's
  }
  for (int j = 0; j < A.size; j++) {
    bucket[A.arr[j]]++;
  }
  for (int k = 0, m = 0; k <= max; k++) {
    while (bucket[k] > 0) {
      A.arr[m++] = k;
      bucket[k]--;
    }
  }
}

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
  bucketSort(M);
  printf("Array after sorting: \n");
  print_Arr(M);
  return 0;
}
