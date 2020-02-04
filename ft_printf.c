
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

char	*get_next_arg(const char *str, int i)
{
	char *return_value;
	char *tmp;
	int arg_start;
	int count;

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
	while (str[i] && !is_arg(str[i]) && str[i] != '%')
	{
		count++;
		i++;
		return_value = ft_realloc(return_value, sizeof(char) * count + 1);
	}
	is_arg(str[i]) ? ft_memsub((void **)&return_value, &(tmp)[arg_start], 0, count) : free(return_value);
	return (is_arg(str[i]) ? return_value : NULL);
}


int	c_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	int_replace(int src, int arguments_number, ...)
{
	va_list dst;
	int ret;
	int *ptr;
	int i;

	i = 0;
	va_start(dst, arguments_number);
	while (i < arguments_number)
	{
		ptr = va_arg(dst, int *);
		*ptr = src;
		i++;
	}
	va_end(dst);
}

typedef struct
{
	char *arg;
	char type;
	int s;
	int w;
	int z;
	int dr;
}curr_arg;

int	int_pad(int int_pad, int n, char c)
{
	int ret;


	ret = int_pad -= ft_nbrlen(n);
	while (int_pad)
	{
		ft_putchar(c);
		int_pad--;
	}
	return (ret);
}

int	str_pad(int int_pad, char *str, char c)
{
	int ret;


	ret = int_pad -= ft_strlen(str);
	while (int_pad)
	{
		ft_putchar(c);
		int_pad--;
	}
	return (ret);
}

int	arg_putnbr(int n, curr_arg *live)
{
	if (live->s > -9 || live-> z > -9)
		int_pad(live->s > -9 ? live->s : live->z, n, live->z > -9 ? '0' : ' ');
	ft_putnbr(n);
	if (live->dr > -9)
		int_pad(live->dr, n, ' ');
}

int	arg_putstr(char *str, curr_arg *live)
{
	if (live->s > -9 || live-> z > -9)
		str_pad(live->s > -9 ? live->s : live->z, str, live->z > -9 ? '0' : ' ');
	ft_putstr(str);
	if (live->dr > -9)
		str_pad(live->dr, str, ' ');
}

int	print_struct(curr_arg *live, va_list args)
{
	live->type == 'd' ? arg_putnbr(va_arg(args, int), live) : 0;
	live->type == 's' ? arg_putstr(va_arg(args, char *), live) : 0;
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	get_right(curr_arg *live, va_list args)
{
	int i;
	int zero;
	int start;
	int count;
	char *ret;

	i = ft_strlen(live -> arg) - 2;
	start = i;
	count = 0;
	while (start >= 0 && is_num(live -> arg[start]) && ft_strlen(live -> arg) > 1)
		{
			start--;
			count++;
		}
	if (count == 0 || live->arg[0] == '0')
		return (0);
	if (!(ret = malloc(sizeof(char) * count + 1)))
		return (0);
	start = start == -1 ? start + 1 : start;
	zero = live -> arg[start] == '0' ? 1 : 0;
	while (live -> arg[start] == '0' || !is_num(live -> arg[start]))
		start++;
	ft_memsub((void **)&ret, &live -> arg[start], 0, i - start + 1);
	zero ? (live -> z = ft_atoi(ret)) : (live -> s = ft_atoi(ret));
}

int	check_right(char *str)
{
	int i;
	int dash;

	dash = 0;
	i = ft_strlen(str) - 1;
	while (str[i] && i >= 0 && str[i] != '-')
	{
		if (str[i - 1] == '-')
		dash = 1;
		i--;
	}
	i = ft_strlen(str) - 1;
	while ((str[i] && i >= 0) || (str[i] && str[i] != '.'))
	{
		if (str[i] == '*' && str[i - 1] == '0' && dash == 0)
			return (ZERO + STAR);
		else if (str[i] == '*')
			return (dash == 0 ? STAR : DASH + STAR);
		i--;
	}
	return (dash == 0 ? 0 : DASH);
}

int	fill_struct(curr_arg *live, va_list args)
{
		int ret;

		ret = 0;
		if ((ret = check_right(live->arg)) == DASH + STAR)
			live->dr = va_arg(args, int);
		else if (ret == STAR)
			live->s = va_arg(args, int);
		else if (ret == ZERO + STAR)
			live->z = va_arg(args, int);
		else if (ret == DASH)
		{
			get_right(live, args);
			live->dr = live->s;
			live->s = -9;
		}
		else if (ret == DASH + STAR)
			live->dr = va_arg(args, int);
		else
			get_right(live, args);
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

	live.z = -9;
	live.s = -9;
	live.dr = -9;
	
	while (str[i])
	{
			if (str[i] == '%' && (live.arg = get_next_arg(str, i)) != NULL)
			{
				live.type = live.arg[ft_strlen(live.arg) - 1];
				fill_struct(&live, args);
				print_struct(&live, args);
				live.z = -9;
				live.s = -9;
				live.dr = -9;
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
	char test[ ] = "test";
	printf("[%6.5d]\n", 50);
}
