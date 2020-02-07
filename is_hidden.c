
#include "lprintf.h"

int	is_hidden(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}
