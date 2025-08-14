#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t bands[]) {
  resistor_value_t code;
  unsigned char buffer;

  buffer = bands[2];
  code.unit = 0;
  code.value = bands[0] * 10 + bands[1];
  while (buffer > 0 && code.value != 0) {
    code.value *= 10;
    if (code.value % 1000 == 0) {
      code.value /= 1000;
      code.unit++;
    }
    buffer--;
  }
  return code;
}
