

#include "lprintf.h"

void	print_value_u(curr *flag, int n, int *to_ret)
{
	if (flag->precision == -1)
		n == 0 && flag->width > 0 ? ft_putchar(' ') : 0;
	else
		ft_putstr(ft_putnbr_base_u(n, DEC));
	flag->width_type == DASH ? write_width(flag, *to_ret, -1) : 0;
	*to_ret = *to_ret < flag->width ? flag->width : *to_ret;
}