#include "array.h"

void insertion_sort(Arr_T A) {
  int i = 1;
  while (i < A.size) {
    int j = i;
    while ((j > 0) && (A.arr[j - 1] > A.arr[j])) {
      swap(j, j - 1, A);
      j--;
    }
    i++;
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
  print_Arr(M);
  insertion_sort(M);
  print_Arr(M);
  return 0;
}
