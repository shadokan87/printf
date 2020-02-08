
#include "lprintf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int sign;

	n == -2147483648 ? write(1, "-2147483648", 11) : 0;
	n == 0 ? write(1, "0", 1) : 0;
	if (n == -2147483648)
		return ;
	if (n == 0)
		return ;
	sign = (n > 0 ? 0 : 1);
	n > 0 ? 0 : ft_putchar('-');
	n = (n > 0 ? n : n * -1);
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
