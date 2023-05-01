// Nicholas Koeppen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count(int coins[], int coinsSize, int amount) {
  if (amount == 0) {
    return 1;
  } else if (amount < 0) {
    return 0;
  } else {
    if (coinsSize <= 0) {
      return 0;
    } else {
      return count(coins, coinsSize - 1, amount) +
             count(coins, coinsSize, amount - coins[coinsSize - 1]);
    }
  }
}

int main() {
  clock_t start, end;
  double duration;
  int coins[] = {1, 5, 10, 25, 50};
  int size = sizeof(coins) / sizeof(coins[0]);
  start = clock();
  printf("%d\n", count(coins, size, 100));
  end = clock();
  duration = ((double)end-start)/CLOCKS_PER_SEC;
  printf("\nThe execution time of the greedy algorithm counting change is: %10f", duration);
}