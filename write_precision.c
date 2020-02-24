

#include "lprintf.h"

void	write_precision(int precision, int len)
{
	if (precision <= len)
		return ;
	while (precision != len)
	{
		ft_putchar('0');
		precision--;
	}
}