#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
  float orbital_period;
  float earth_years;

  orbital_period = -1;
  earth_years = seconds / 31557600.0;
  switch (planet) {
  case MERCURY:
    orbital_period = 0.2408467;
    break;
  case VENUS:
    orbital_period = 0.61519726;
    break;
  case EARTH:
    orbital_period = 1.0;
    break;
  case MARS:
    orbital_period = 1.8808158;
    break;
  case JUPITER:
    orbital_period = 11.862615;
    break;
  case SATURN:
    orbital_period = 29.447498;
    break;
  case URANUS:
    orbital_period = 84.016846;
    break;
  case NEPTUNE:
    orbital_period = 164.79132;
    break;
  }
  if (orbital_period == -1)
    return orbital_period;
  return earth_years / orbital_period;
}
