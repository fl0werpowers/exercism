#include "atbash_cipher.h"

unsigned int out_length(const char *input, atbash_type type) {
  unsigned int length;
  unsigned int idx;

  length = 0;
  idx = 0;
  while (input[idx]) {
    if ((input[idx] >= 'A' && input[idx] <= 'Z') ||
        (input[idx] >= 'a' && input[idx] <= 'z') ||
        (input[idx] >= '0' && input[idx] <= '9'))
      length++;
    if (type == ENCODE && length % 5 == 0)
      length++;
    idx++;
  }
  length++;
  return length;
}

char *atbash_encode(const char *input) {
  char *output = (char *)malloc(out_length(input, ENCODE));
  int out_idx = 0;

  for (int idx = 0; input[idx]; idx++) {
    if ((out_idx + 1) % 6 == 0 && input[idx + 1]) {
      output[out_idx] = ' ';
      out_idx++;
    }
    if ((input[idx] >= 'A' && input[idx] <= 'Z') ||
        (input[idx] >= 'a' && input[idx] <= 'z')) {
      char out_symbol = input[idx];
      if (out_symbol >= 'A' && out_symbol <= 'Z') {
        out_symbol += 'a' - 'A';
      }
      out_symbol = 'z' + 'a' - out_symbol;
      output[out_idx] = out_symbol;
      out_idx++;
    } else if (input[idx] >= '0' && input[idx] <= '9') {
      output[out_idx] = input[idx];
      out_idx++;
    }
  }
  output[out_idx] = 0;
  return output;
}

char *atbash_decode(const char *input) {
  char *output = (char *)malloc(out_length(input, DECODE));
  int out_idx = 0;

  for (int idx = 0; input[idx]; idx++) {
    if (input[idx] >= 'a' && input[idx] <= 'z') {
      output[out_idx] = 'z' + 'a' - input[idx];
      out_idx++;
    } else if (input[idx] >= '0' && input[idx] <= '9') {
      output[out_idx] = input[idx];
      out_idx++;
    }
  }
  output[out_idx] = 0;
  return output;
}
