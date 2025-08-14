#include "pangram.h"
#include <stdio.h>

bool letter_is_unique(char *letters, char letter, int letter_count) {
  int idx;

  idx = 0;
  while (idx < letter_count) {
    if (letters[idx] == letter)
      return false;
    idx++;
  }
  return true;
}

bool is_pangram(const char *sentence) {
  char letters[26];
  int idx;
  int letter_count;
  char buffer_letter;

  if (!sentence)
    return false;
  idx = 0;
  letter_count = 0;
  while (sentence[idx]) {
    if ((sentence[idx] >= 'A' && sentence[idx] <= 'Z') ||
        (sentence[idx] >= 'a' && sentence[idx] <= 'z')) {
      buffer_letter = (sentence[idx] >= 'a' && sentence[idx] <= 'z')
                          ? sentence[idx]
                          : sentence[idx] + ('a' - 'A');
      if (letter_is_unique(letters, buffer_letter, letter_count)) {
        letters[letter_count] = buffer_letter;
        letter_count++;
      }
    }
    idx++;
  }
  if (letter_count == 26)
    return true;
  else
    return false;
}
