

#include "lprintf.h"

char	*hidden_of(char *str)
{
	int		i;
	char	*hidden;

	hidden = NULL;
	i = 0;
	while (*str)
	{
		ft_putchar_str(&hidden,
		ft_putnbr_base((unsigned int)*str, HEXD)[0]);
		str++;
	}
	return (hidden);
}