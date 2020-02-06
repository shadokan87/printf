
#include "lprintf.h"

int ft_nbrlen(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	n = n < 0 ? ~n + 1: n;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}
