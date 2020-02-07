
#include "lprintf.h"

void	ft_putchar_str(char **str, char c)
{
	int c_index;
	char *ptr;

	c_index = ft_strlen(*str);
	*str = ft_realloc(*str, ft_strlen(*str) + 2);
	ptr = *str;
	ptr[c_index] = c;
	ptr[c_index + 1] = '\0';
}