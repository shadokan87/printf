
#include "lprintf.h"

int	ft_nbrlen_u(unsigned int n)
{
	unsigned int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}
