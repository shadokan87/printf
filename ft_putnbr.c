
#include "lprintf.h"

void	ft_putnbr(int n)
{
	ft_putstr(ft_putnbr_base(n, DEC));
}
