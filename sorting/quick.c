#include "array.h"

int partition(Arr_T A, int low, int high) {
  int pivot = A.arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (A.arr[j] < pivot) {
      i++;
      swap(i, j, A);
    }
  }
  swap(i + 1, high, A);
  return i + 1;
}

void quick_sort_driver(Arr_T A, int low, int high) {
  if (low < high) {
    int pi = partition(A, low, high);
    quick_sort_driver(A, low, pi - 1);
    quick_sort_driver(A, pi + 1, high);
  }
}

void quick_sort(Arr_T A) { quick_sort_driver(A, 0, A.size - 1); }

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
  quick_sort(M);
  print_Arr(M);
  return 0;
}
