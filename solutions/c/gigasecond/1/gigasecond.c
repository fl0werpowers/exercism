#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
	struct tm buf;

	input += 1000000000;
	buf = *gmtime(&input);
	printf("%d chars written", snprintf(output, size, "%d-%.2d-%.2d %.2d:%.2d:%.2d", buf.tm_year + 1900, buf.tm_mon + 1, buf.tm_mday, buf.tm_hour, buf.tm_min, buf.tm_sec));
}
