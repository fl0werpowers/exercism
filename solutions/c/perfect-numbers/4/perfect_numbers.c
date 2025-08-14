#include "perfect_numbers.h"

int classify_number(int number) {
  int idx;
  int acc;

  if (number <= 0)
    return ERROR;
  idx = 0;
  acc = 0;
  while (idx < number) {
    if (number % idx == 0)
      acc += idx;
    idx++;
  }
  if (number == acc)
    return PERFECT_NUMBER;
  if (number < acc)
    return ABUNDANT_NUMBER;
  if (number > acc)
    return DEFICIENT_NUMBER;
}
