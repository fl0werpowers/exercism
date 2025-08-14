#include "armstrong_numbers.h"

int pow_i(int n, int pow) {
  int res;

  res = n;
  while (pow > 1) {
    res *= n;
    pow--;
  }
  return res;
}

bool is_armstrong_number(int candidate) {
  int copy;
  int power;
  int buffer;
  int result;

  copy = candidate;
  power = 0;
  result = 0;
  while (copy > 0) {
    copy /= 10;
    power++;
  }
  copy = candidate;
  while (copy > 0) {
    buffer = copy % 10;
    result += pow_i(buffer, power);
    copy /= 10;
  }
  return result == candidate;
}
