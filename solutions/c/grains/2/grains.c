#include "grains.h"
#include <stdint.h>

uint64_t square(uint8_t index) {
  if (index < 1 || index > 64)
    return 0;
  uint64_t result = 1;
  return result << (index - 1);
}

uint64_t total(void) {
  uint64_t total = 0;
  uint64_t one = 1;
  for (uint8_t i = 1; i <= 64; i++) {
    total += one << i;
  }
  return total;
}
