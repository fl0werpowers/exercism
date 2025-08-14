#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
  int low;
  int hi;
  int med;

  low = 0;
  hi = length - 1;
  while (low <= hi) {
    med = low + (hi - low) / 2;
    if (arr[med] == value)
      return &arr[med];
    else if (arr[med] < value)
      low = med + 1;
    else
      hi = med - 1;
  }
  return NULL;
}
