#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum Atbash { ENCODE, DECODE } atbash_type;

unsigned int out_length(const char *input, atbash_type type);
char *atbash_encode(const char *input);
char *atbash_decode(const char *input);

#endif
