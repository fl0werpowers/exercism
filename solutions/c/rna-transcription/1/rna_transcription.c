#include "rna_transcription.h"

char *to_rna(const char *dna) {
  char *rna;
  int idx;

  idx = 0;
  rna = (char *)malloc(strlen(dna) + 1);
  strcpy(rna, dna);
  while (rna[idx]) {
    switch (rna[idx]) {
    case 'G':
      rna[idx] = 'C';
      break;
    case 'C':
      rna[idx] = 'G';
      break;
    case 'T':
      rna[idx] = 'A';
      break;
    case 'A':
      rna[idx] = 'U';
      break;
    default:
      break;
    }
    idx++;
  }
  return rna;
}
