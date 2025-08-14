#include "perfect_numbers.h"

int classify_number(int number) {
  int idx;
  int acc;

  if (number <= 0)
    return ERROR;
  idx = 1;
  acc = 0;
  while (idx <= number / 2) {
    if (number % idx == 0)
      acc += idx;
    idx++;
  }
  if (number == acc)
    return PERFECT_NUMBER;
  else if (number < acc)
    return ABUNDANT_NUMBER;
  else
    return DEFICIENT_NUMBER;
}
