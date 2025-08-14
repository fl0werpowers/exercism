#include "grains.h"
#include <stdint.h>

uint64_t square(uint8_t index) {
  if (index == 0 || index > 64)
    return 0;
  if (index == 1)
    return 1;
  uint8_t n = index - 1;
  uint64_t x = 2;
  uint64_t y = 1;
  while (n > 1) {
    if (n % 2 != 0) {
      y = x * y;
      n -= 1;
    }
    x = x * x;
    n = n / 2;
  }
  return x * y;
}

uint64_t total(void) {
  uint64_t total = 0;
  uint64_t square = 1;
  for (uint8_t i = 1; i <= 64; i++) {
    total += square;
    square *= 2;
  }
  return total;
}
