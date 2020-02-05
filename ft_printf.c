
#include "lprintf.h"

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int c_str(char *str, char c)
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

typedef struct
{
	char *arg;
	char type;
	int precision;
	int width;
	int wType;

} curr;

void fill_precision(curr *flag, va_list args)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	if (!c_str(flag->arg, '.'))
		return ;
	while (flag->arg[i] != '.')
		i++;
	if (flag->arg[i + 1] == STAR)
	{
		flag->precision = va_arg(args, int);
		return ;
	}
	i++;
	while (is_num(flag->arg[i]))
	{
		ft_putchar_str(&tmp, flag->arg[i]);
		i++;
	}
	flag->precision = ft_atoi(tmp ? tmp : "0");
		
}

void	fill_struct(curr *flag, va_list args)
{
	flag->type = flag->arg[ft_strlen(flag->arg) - 1];
	fill_precision(flag, args);
	printf("%d", flag->precision);
}

char *get_next_arg(const char *str, int i)
{
	char *ret;

	ret = NULL;
	while (str[i] && !is_arg(str[i - 1]) && str[i + 1] != '%')
		{
			str[i] != '%' ? ft_putchar_str(&ret, str[i]) : 0;
			i++;
			
		}
	if (ret && !is_arg(ret[ft_strlen(ret) - 1]))
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}




int	ft_printf(const char *str, ...)
{
	int i;
	int ret;
	char *tmp;

	i = 0;
	va_list args;
	
	curr flag;
	
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (flag.arg = get_next_arg(str, i)) != NULL)
			{
				fill_struct(&flag, args);
				i+= ft_strlen(flag.arg) + 1;
			}
			else
			{
				//ft_putchar(str[i]);
				i++;
			}		
	}
	va_end(args);
}

int	main(void)
{
	ft_printf("%.*d", 50);
}
