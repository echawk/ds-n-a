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

int main(void) {
  Arr_T test_arr = make_Arr(10);
  populate_Arr(test_arr);

  printf("Array before it is sorted: ");
  print_Arr(test_arr);

  gnome_sort(test_arr);

  printf("Array after it is gnome sorted: ");
  print_Arr(test_arr);

  return EXIT_SUCCESS;
}