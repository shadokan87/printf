
#include "lprintf.h"

int ft_nbrlen(int n)
{
	int count;

	count = 0;
	n = n < 0 ? ~n + 1: n;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}
