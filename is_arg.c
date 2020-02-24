

#include "lprintf.h"

int	is_arg(char c)
{
	int		i;
	char	*arg_list;

	arg_list = ft_strdup("cspdiuxX%");
	i = 0;
	while (arg_list[i])
	{
		if (c == arg_list[i])
			return (1);
		i++;
	}
	return (0);
}