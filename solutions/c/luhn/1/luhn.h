#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool luhn(const char *num);
unsigned int luhn_digit(char digit);

#endif
