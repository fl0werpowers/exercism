#include "resistor_color.h"

resistor_band_t color_code(resistor_band_t band) { return band; }

resistor_band_t *colors(void) {
  resistor_band_t *color_list;
  int idx;

  color_list = malloc((WHITE + 1) * 4);
  idx = 0;
  for (resistor_band_t color = BLACK; color <= WHITE; color++) {
    color_list[idx] = color;
    idx++;
  }
  return color_list;
}
