
#include "lprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_arg(char c)
{
	int i;
	char *arg_list;

	arg_list = ft_strdup("cspdiuxX");
	i = 0;
	while (arg_list[i])
	{
		if (c == arg_list[i])
			return (1);
		i++;
	}
	return (0);
}

/*
int	check_arg(char c, va_list args)
{
	if (!arg_is_valid(c))
		return (0);
	c == 'c' ? ft_putchar(va_arg(args, int)) : 0;
	c == 's' ? ft_putstr(va_arg(args, char *)) : 0;
	c == 'p' ? ft_putptr(va_arg(args, unsigned long int)) : 0;
	c == 'd' ? ft_putnbr(va_arg(args, int)) : 0;
	c == 'i' ? ft_putnbr(va_arg(args, int)) : 0;
	return (1);
}
*/

typedef struct
{
	char *arg;
	char type;
	int s;
	int w;
	int z;
}curr_arg;

char	*get_next_arg(const char *str)
{
	char *return_value;
	char *tmp;
	int arg_start;
	int count;
	static int i = 0;

	tmp = (char *)str;
	return_value = NULL;
	count = -1;
	while (str[i] && str[i] != '%')
	i++;
	if (str[i] == '\0' || str[i + 1] == '%')
		return (0);
	i++;
	count = 1;
	if (!(return_value = malloc(sizeof(char) * count + 1)))
		return (0);
	arg_start = i;
	while (str[i] && !is_arg(str[i]))
	{
		count++;
		i++;
		if (str[i] == '%')
			break ;
		return_value = ft_realloc(return_value, sizeof(char) * count + 1);
	}
	is_arg(str[i]) ? ft_memsub((void **)&return_value, &(tmp)[arg_start], 0, count) : free(return_value);
	return (is_arg(str[i]) ? return_value : NULL);
}

int	Pad(int pad, int n, char c)
{
	int ret;


	ret = pad -= ft_nbrlen(n);
	while (pad)
	{
		ft_putchar(c);
		pad--;
	}
	return (ret);
}

void	print(char *str, char type, va_list args)
{
	//type == 'd' ? ft_putnbr(va_arg(args, int)) : 0;
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	get_s(char *arg)
{
	int i;
	int start;
	char *ret;

	if (ft_strlen(arg) == 1)
		return (0);
	ret = NULL;
	i = ft_strlen(arg) - 2;
	if (arg[i] == '*')
		return (-1);
	if (!is_num(arg[i]))
		return (0);
	start = i;
	while (is_num(arg[start]))
		start--;
	start = is_num(arg[start]) ? start : start + 1;
	if (!(ret = malloc(sizeof(char) * start + i + 2)))
		return (0);
	ft_memsub((void **)&ret, arg, start, start + i + 1);
	i = ft_atoi(ret);
	free(ret);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int y;
	int arg_len;
	int ret;
	char *tmp;

	curr_arg live;
	i = 0;
	y = 0;
	arg_len = 0;
	va_list args;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%' && (live.arg = get_next_arg(str)) != NULL)
		{
			live.type = live.arg[ft_strlen(live.arg) - 1];
			live.s = get_s(live.arg);
			printf("%d", live.s);
			print(live.arg, live.type, args);
			i+= ft_strlen(live.arg) + 1;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
}

int	main(void)
{
	ft_printf("%01555d", 5);
}
