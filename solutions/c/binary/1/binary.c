#include "binary.h"

int power(int num, int pow) {
  if (pow == 0)
    return 1;
  if (pow == 1)
    return num;
  return num * power(num, pow - 1);
}

int convert(const char *input) {
  int acc;
  int count;
  int idx;

  idx = 0;
  while (input[idx]) {
    if (input[idx] < 48 || input[idx] > 49)
      return INVALID;
    idx++;
  }
  count = idx - 1;
  idx = 0;
  acc = 0;
  while (input[idx]) {
    acc += (input[idx] - 48) * power(2, count);
    count--;
    idx++;
  }
  return acc;
}
