

#include "lprintf.h"

void	print_value_d(curr *flag, int n, int swap, int *to_ret)
{
	swap < 0 && flag->precision == 0 && flag->width_type
		!= ZERO ? ft_putchar('-') : 0;
	if (flag->precision == -1 && n == 0)
		flag->width > 0 ? ft_putchar(' ') : 0;
	else
		ft_putnbr(n);
	flag->width_type == DASH ? write_width(flag, *to_ret, -1) : 0;
	*to_ret += (swap < 0 ? 1 : 0);
	if (*to_ret < flag->width)
		*to_ret = flag->width + (swap < 0 ? 1 : 0);
}