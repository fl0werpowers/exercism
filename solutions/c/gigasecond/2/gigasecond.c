#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
	struct tm *buf;

	input += 1000000000;
	buf = gmtime(&input);
	strftime(output, size, "%Y-%m-%d %H:%M:%S", buf);
}
