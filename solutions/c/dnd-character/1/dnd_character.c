#include "dnd_character.h"

int ability(void) {
  int idx_min;
  int idx;
  int result;
  int values[4];

  srand(time(NULL));
  idx = 0;
  idx_min = 0;
  while (idx < 4) {
    values[idx] = rand() % 6 + 1;
    if (values[idx] < values[idx_min])
      idx_min = idx;
    idx++;
  }
  values[idx_min] = 0;
  idx = 0;
  result = 0;
  while (idx < 4)
    result += values[idx++];
  return result;
}

int modifier(int score) { return (int)floor((score - 10.0) / 2.0); }

dnd_character_t make_dnd_character(void) {
  dnd_character_t dnd_character;

  dnd_character.strength = ability();
  dnd_character.dexterity = ability();
  dnd_character.constitution = ability();
  dnd_character.intelligence = ability();
  dnd_character.wisdom = ability();
  dnd_character.charisma = ability();
  dnd_character.hitpoints = 10 + modifier(dnd_character.constitution);
  return dnd_character;
}
