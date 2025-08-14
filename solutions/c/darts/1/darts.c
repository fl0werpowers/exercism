#include "darts.h"

unsigned char score(coordinate_t pos) {
  float r;

  r = pos.x * pos.x + pos.y * pos.y;
  if (r <= RAD_INNER)
    return SCORE_INNER;
  if (r <= RAD_MIDDLE)
    return SCORE_MIDDLE;
  if (r <= RAD_OUTER)
    return SCORE_OUTER;
  return SCORE_MISS;
}
