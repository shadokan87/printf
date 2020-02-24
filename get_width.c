

#include "lprintf.h"

char	*get_width(curr *flag)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (flag->arg[i] && flag->arg[i] != '.')
	{
		ft_putchar_str(&tmp, flag->arg[i]);
		i++;
	}
	return (tmp);
}