#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Arr {
  int size;
  int *arr;
} Arr_T;

Arr_T make_Arr(int size);
void populate_Arr(Arr_T A);
bool within_Arr(int val, Arr_T A);
int largestIndIn_Arr(Arr_T A);
void print_Arr(Arr_T A);
void swap(int ind1, int ind2, Arr_T A);
void sorted_populate_Arr(Arr_T A);
void shuffle_Arr(Arr_T A);
void sort(Arr_T A);
