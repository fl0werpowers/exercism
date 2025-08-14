#include "raindrops.h"

void convert(char result[], int drops) {
  int div_3 = !(drops % 3);
  int div_5 = !(drops % 5);
  int div_7 = !(drops % 7);
  if (div_3 || div_5 || div_7)
    sprintf(result, "%s%s%s", div_3 ? "Pling" : "", div_5 ? "Plang" : "",
            div_7 ? "Plong" : "");
  else
    sprintf(result, "%d", drops);
}
