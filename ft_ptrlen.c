
#include "lprintf.h"

static int	count(unsigned int n, int b_len)
{
	int count;

	count = 0;
	while (n)
	{
		n /= b_len;
		count++;
	}
	return (count);
}

static int	check_base(char *base)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (ft_strlen(base) <= 1 || !base)
		return (0);
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '-'
		|| base[i] == '+')
			return (0);
		i++;
	}
	while (i <= ft_strlen(base) - 2)
	{
		y = i + 1;
		while (y <= ft_strlen(base) - 1)
			{
				if (base[i] == base[y])
					return (0);
				y++;
			}
		i++;
	}
	return (1);
}

static char	*ft_putnbr_base_ptr(unsigned long int n, char *base)
{
	int i;
	char *ret;
	int b_len;

	b_len = ft_strlen(base);
	i = 0;
	if (n == 0)
		return ("0");
	if (!(ret = malloc(sizeof(char) * count(n, b_len) + 1)) ||
    !check_base(base))
		return (0);
	while (n)
	{
		ret[i] = base[n % b_len];
		n /= b_len;
		i++;
	}
	ret[i] = '\0';
	return (ft_strrev(ret));
}

int		ft_ptrlen(unsigned long int ptr)
{
	if (!ptr)
		return (3);
	return(ft_strlen(ft_putnbr_base_ptr(ptr, HEXD)) + 2);
}
