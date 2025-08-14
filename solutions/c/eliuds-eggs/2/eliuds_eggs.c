#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int eggs) {
  unsigned int count;

  count = 0;
  while (eggs != 0) {
    if (eggs % 2 != 0)
      count++;
    eggs >>= 1;
  }
  return count;
}
