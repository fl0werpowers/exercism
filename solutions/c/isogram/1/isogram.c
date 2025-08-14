#include "isogram.h"

bool is_uppercase(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}
bool is_lowercase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}
char to_lower(char ch)
{
    return ch + 32; // ch + ('a' - 'A')
}

bool is_isogram(const char phrase[])
{
    int idx1;
    int idx2;
    char cmp1;
    char cmp2;

    if (phrase == NULL)
        return false;
    idx1 = 0;
    while (phrase[idx1])
    {
      if (!is_lowercase(phrase[idx1]) && !is_uppercase(phrase[idx1]))
      {
          idx1++;
          continue;
      }
        cmp1 = is_uppercase(phrase[idx1]) ? to_lower(phrase[idx1]) : phrase[idx1];
        idx2 = idx1 + 1;
        while (phrase[idx2])
        {
            if (!is_lowercase(phrase[idx2]) && !is_uppercase(phrase[idx2]))
              {
                  idx2++;
                  continue;
              }
            cmp2 = is_uppercase(phrase[idx2]) ? to_lower(phrase[idx2]) : phrase[idx2];
            if (cmp1 == cmp2)
                return false;
            idx2++;
        }
        idx1++;
    }
    return true;
}