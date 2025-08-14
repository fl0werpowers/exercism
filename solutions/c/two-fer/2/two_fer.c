#include "two_fer.h"

void two_fer(char *buffer, const char *name) {
  int idx;
  int idx2;
  char part1[9] = "One for ";
  char placeholder[3] = "you";
  char part2[14] = ", one for me.";

  idx = 0;
  idx2 = 0;
  while (part1[idx2]) {
    buffer[idx] = part1[idx2];
    idx++;
    idx2++;
  }
  idx2 = 0;
  if (*name)
    while (name[idx2]) {
      buffer[idx] = name[idx2];
      idx++;
      idx2++;
    }
  else
    while (placeholder[idx2]) {
      buffer[idx] = placeholder[idx2];
      idx++;
      idx2++;
    }
  idx2 = 0;
  while (part2[idx2]) {
    buffer[idx] = part2[idx2];
    idx++;
    idx2++;
  }
  buffer[idx] = 0;
}
