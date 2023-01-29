#include <stdio.h>
#include <stdlib.h>

typedef struct Arr {
  int size;
  int *arr;
} Arr_T;

Arr_T make_Arr(int size) {
  return (Arr_T){.size = size, .arr = malloc(sizeof(int) * size)};
}

void populate_Arr(Arr_T A) {
  int i = 0;
  for (i = 0; i < A.size; i++) {
    A.arr[i] = rand() % A.size;
  }
}
void print_Arr(Arr_T A) {
  int i = 0;
  printf("[");
  for (i = 0; i < A.size - 1; i++) {
    printf("%d,", A.arr[i]);
  }
  printf("%d]\n", A.arr[i]);
}

void swap(int ind1, int ind2, Arr_T A) {
  if (A.arr[ind1] != A.arr[ind2]) {
    A.arr[ind1] = A.arr[ind1] ^ A.arr[ind2];
    A.arr[ind2] = A.arr[ind1] ^ A.arr[ind2];
    A.arr[ind1] = A.arr[ind1] ^ A.arr[ind2];
  }
}
