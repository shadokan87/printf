
#include "lprintf.h"

void	write_const(const char *str, int *i)
{
	ft_putchar(str[*i]);
	*i += 1;
}