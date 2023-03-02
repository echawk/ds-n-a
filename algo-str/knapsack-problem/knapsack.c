#include "item.c"
#include <stdio.h>
#include <stdlib.h>

//{{Value, Weight}, {Value, Weight}}
// value caps at 10
// weight caps at 10
#define capacity 15

item bestItems[listSize];

void greedyKnapsack(item items[], int max) {
  int totalProfit = 0;
  for (int i = 0; i < listSize; i++) {
    if (items[i].weight >= max) {
      break;
    } else {
      bestItems[i] = items[i];
      totalProfit = totalProfit + items[i].value;
      max = max - items[i].weight;
    }
  }
  printf("Total Profit: %d\tTotal Weight = %d\n", totalProfit, capacity - max);
}

int main() {
  item itemList[listSize];
  int index = 0;
  populateList(itemList);
  printList(itemList);
  printf("\n");
  bubbleSort(itemList);
  reverse(itemList, 0, listSize - 1);
  printf("This is the list sorted by best value/weight ratio: \n");
  printList(itemList);
  printf("\n");
  printf("This is the best way to fill the knapsack: \n");
  greedyKnapsack(itemList, capacity);
  printList(bestItems);
  return 0;
}