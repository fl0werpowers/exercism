#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
  int acc;

  acc = 0;
  while (*lhs && *rhs) {
    if (*lhs != *rhs)
      acc++;
    lhs++;
    rhs++;
  }

  if (*lhs != *rhs)
    return -1;
  else
    return acc;
}
