#include "luhn.h"
#include <stdio.h>

unsigned int luhn_digit(char digit)
{
	digit = (digit - '0') * 2;
	return digit > 9 ? digit - 9 : digit;
}

bool luhn(const char *num)
{
	int idx;
	int num_counter;
	int num_count;
	unsigned int sum;

	if (*num == 0)
		return false;
	idx = 0;
	num_count = 0;
	while(num[idx])
	{
		if ((num[idx] != ' ')
			&& (num[idx] < '0' || num[idx] > '9'))
			return false;
		if (num[idx] != ' ')
			num_count++;
		idx++;
	}
	if (idx == 1 || num_count == 1)
		return false;
	idx--;
	sum = 0;
	num_counter = 0;
	while(idx >= 0)
	{
		if (num[idx] < '0' || num[idx] > '9')
		{
			idx--;
			continue;
		}
		num_counter++;
		if (num_counter % 2 == 0)
			sum += luhn_digit(num[idx]);
		else
			sum += num[idx] - '0';
		idx--;
	}
	return sum % 10 == 0;
}
