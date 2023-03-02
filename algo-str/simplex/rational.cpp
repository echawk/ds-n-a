#include <cstdio>
#include <cstdlib>

#include "rational.h"

rational_t ratio_init() { return (rational_t){.numer = 0, .denom = 1}; }

rational_t ratio_init(int num) {
  return (rational_t){.numer = num, .denom = 1};
}

rational_t ratio_init(int numer, int denom) {
  return (rational_t){.numer = numer, .denom = denom};
}

int gcd(int x, int y) {
  int result = ((x < y) ? x : y);

  while (result > 0) {
    if (x % result != 0 || y % result != 0) {
      result--;
    }
  }

  return result; // return gcd of a nd b
}

void ratio_reduce(rational_t *ratio) {
  int divisor = gcd(ratio->numer, ratio->denom);

  ratio->numer /= divisor;
  ratio->denom /= divisor;

  return;
}
