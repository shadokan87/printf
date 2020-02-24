

#include "lprintf.h"

void	write_width(curr *flag, int len, int exception)
{
	int tmp;

	tmp = flag->width;
	if (exception > -1)
	{
		while (exception)
		{
			ft_putchar(' ');
			exception--;
		}
		return ;
	}
	if (tmp == 0 || tmp <= len)
		return ;
	while (tmp != len)
	{
		ft_putchar(flag->width_type == ZERO ? '0' : ' ');
		tmp--;
	}
}