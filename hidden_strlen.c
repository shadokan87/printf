

#include "lprintf.h"

int	hidden_strlen(char *str, char *tmp)
{
	int i;

	i = 0;
	if (tmp && is_hidden(tmp))
		return (ft_strlen(hidden_of(tmp)));
	else
		return (ft_strlen(str));
}