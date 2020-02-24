

#include "lprintf.h"

void	ft_str(char *str)
{
	if (!str || str[0] == '\0')
		write(1, "(null)", 6);
	else
		write(1, str, ft_strlen(str));
}