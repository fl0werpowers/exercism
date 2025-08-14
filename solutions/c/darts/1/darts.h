#ifndef DARTS_H
#define DARTS_H

enum { SCORE_MISS = 0, SCORE_OUTER = 1, SCORE_MIDDLE = 5, SCORE_INNER = 10 };
enum { RAD_INNER = 1, RAD_MIDDLE = 25, RAD_OUTER = 100 };

typedef struct {
  float x;
  float y;
} coordinate_t;

unsigned char score(coordinate_t pos);

#endif
