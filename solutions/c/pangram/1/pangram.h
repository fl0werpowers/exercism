#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

bool is_pangram(const char *sentence);
bool letter_is_unique(char *letters, char letter, int letter_count);

#endif
