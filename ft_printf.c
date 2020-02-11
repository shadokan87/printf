
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
	if (!str)
		return (0);
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
	int width_type;

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
	flag->precision = ft_atoi(tmp ? tmp : "-1");
	flag->precision = flag->precision == 0 ? - 1 : flag->precision;
	tmp ? free(tmp) : 0;
}

void	reset_struct(curr *flag)
{
	flag->arg = NULL;
	flag->type = '0';
	flag->precision = 0;
	flag->width = 0;
	flag->width_type = 0;
}

int		contain_num(char *str)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (is_num(str[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

void	fill_width(curr *flag, va_list args)
{
	int i;
	char *tmp;
	char *n;

	i = 0;
	tmp = NULL;
	n = NULL;
	while (flag->arg[i] && flag->arg[i] != '.')
	{
		ft_putchar_str(&tmp, flag->arg[i]);
		i++;
	}
	i = 0;
	if (tmp && tmp[i] == '0')
		i++;
	while (contain_num(tmp) && !is_num(tmp[i]) && !c_str(tmp, STAR))
	{
		i++;
	}
	while (tmp && is_num(tmp[i]) && !c_str(tmp, STAR))
	{
		ft_putchar_str(&n, tmp[i]);
		i++;
	}
	c_str(tmp, STAR) ? flag->width = va_arg(args, int) :
	(flag->width = ft_atoi(n ? n : "0"));
	n ? free(n) : 0;
	tmp ? free(tmp) : 0;
}

void	fill_width_type(curr *flag)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	while (flag->arg && flag->arg[i] && flag->arg[i - 1] != '.')
	{
		ft_putchar_str(&tmp, flag->arg[i]);
		i++;
	}
	i = 0;
	if (tmp && c_str(tmp, DASH))
		flag->width_type = flag->width > 0 ? DASH : 0;
	else
	{
		while (tmp && tmp[i] && !is_num(tmp[i]))
			i++;
		if (tmp && tmp[i] == '0' && flag->width_type != DASH &&
		!c_str(flag->arg, '.')
		)
			flag->width_type = flag->width > 0 ? ZERO : 0;
	}
	free(tmp);
}

int	fill_struct(curr *flag, va_list args)
{
	flag->type = flag->arg[ft_strlen(flag->arg) - 1];
	fill_width(flag, args);
	fill_precision(flag, args);
	fill_width_type(flag);
	return (ft_strlen(flag->arg) + 1);
}

void	write_precision(int precision, int len)
{
	if (precision <= len)
		return ;
	while (precision != len)
	{
		ft_putchar('0');
		precision--;
	}
}

void	write_width(curr *flag, int len, int exception)
{
	int tmp;
	
	tmp = flag->width;
	if (exception > -1)
	{
		while (exception)
		{
			ft_putchar(' ');
			exception--;
		}
		return ;
	}
	if (tmp == 0 || tmp <= len)
		return ;
	while (tmp != len)
	{
		ft_putchar(flag->width_type == ZERO ? '0' : ' ');
		tmp--;
	}
}

void	arg_putnbr(curr *flag, va_list args, int *ret)
{
	int to_ret;
	int n;
	int swap;

	n = va_arg(args, int);
	swap = n;
	to_ret = ft_nbrlen(n);
	to_ret = flag->precision > 0 && flag->precision > to_ret ?
	flag->precision : to_ret;
	n < 0 ? flag->width-- : 0;
	n < 0 && flag->precision == 0 && flag->width_type == ZERO ? ft_putchar('-') : 0;
	flag->width_type != DASH ? write_width(flag, to_ret, -1) : 0;
	n < 0 && flag->precision != 0 ? ft_putchar('-') : 0;
	write_precision(flag->precision, ft_nbrlen(n));
	n < 0 ? n *= -1 : 0;
	swap < 0 && flag->precision == 0 && flag->width_type != ZERO ? ft_putchar('-') : 0;
	flag->precision == -1 ? ft_putchar(' '): ft_putnbr(n);
	flag->width_type == DASH ? write_width(flag, to_ret, -1) : 0;
	to_ret += (swap < 0 ? 1 : 0);
	to_ret = to_ret < flag->width ? flag->width + (swap < 0 ? 1 : 0): to_ret;
	*ret += to_ret;
}

void	arg_putunsigned(curr *flag, va_list args, int *ret)
{
	int to_ret;
	unsigned int n;

	n = va_arg(args, unsigned int);
	to_ret = ft_nbrlen(n);
	write_precision(flag->precision, to_ret);
	to_ret = to_ret < flag->precision ? flag->precision : to_ret;
	flag->width_type != DASH ? write_width(flag, to_ret, -1) : 0;
	n != 0 ? ft_putstr(ft_putnbr_base_u(n, DEC)) : 0;
	flag->width_type == DASH ? write_width(flag, to_ret, -1) : 0;
	to_ret = to_ret < flag->width ? flag->width : to_ret;
	*ret += to_ret;
}

void	arg_puthexa(curr *flag, va_list args, int *ret)
{
	int to_ret;
	unsigned int n;

	n = va_arg(args, unsigned int);
	to_ret = ft_strlen(ft_putnbr_base_u(n, HEXD));
	write_precision(flag->precision, to_ret);
	to_ret = to_ret < flag->precision ? flag->precision : to_ret;
	flag->width_type != DASH ? write_width(flag, to_ret, -1) : 0;
	n != 0 ? ft_putstr(ft_putnbr_base_u(n, flag->type
	== 'x' ? HEXD : MAJHEXD)) : 0;
	flag->width_type == DASH ? write_width(flag, to_ret, -1) : 0;
	to_ret = to_ret < flag->width ? flag->width : to_ret;
	*ret += to_ret;
}

void ft_str(char *str)
{
	if (!str || str[0] == '\0')
		write(1, "(null)", 6);
	else
		write(1, str, ft_strlen(str));
}

char	*hidden_of(char *str)
{
	int i;
	char *hidden;

	hidden = NULL;
	i = 0;
	while (*str)
	{
		ft_putchar_str(&hidden,
		ft_putnbr_base((unsigned int)*str, HEXD)[0]);
		str++;
	}
	return (hidden);
}

int	hidden_strlen(char *str, char *tmp)
{
	int i;

	i = 0;
	if (tmp && is_hidden(tmp))
		return (ft_strlen(hidden_of(tmp)));
	else
		return (ft_strlen(str));
}

void	arg_putstr(curr *flag, va_list args, int *ret)
{
	int to_ret;
	char *str;
	char *tmp;
	int i;

	i = 0;
	tmp = va_arg(args, char *);
	str = ft_strdup(tmp);
	if (flag->precision >0 && flag->precision < ft_strlen(str))
		str[flag->precision] = '\0';
	to_ret = hidden_strlen(str, tmp);
	flag->width_type != DASH ? write_width(flag, to_ret,
	flag->precision == -1 ? flag->width : -1) : 0;
	flag->precision > -1 ? ft_putstr(str) : 0;
	flag->width_type == DASH ? write_width(flag, to_ret,
	flag->precision == -1 ? flag->width : -1) : 0;
	to_ret = to_ret < flag->width ? flag->width : to_ret;
	*ret += to_ret;
}

void	arg_putchar(curr *flag, va_list args, int *ret)
{
	int to_ret;
	char c;

	c = (char)va_arg(args, int);
	to_ret = 1;
	flag->width_type != DASH ? write_width(flag, to_ret, -1) : 0;
	ft_putchar(c);
	flag->width_type == DASH ? write_width(flag, to_ret, -1) : 0;
	to_ret = to_ret < flag->width ? flag->width : to_ret;
	*ret += to_ret;
}

void	arg_putptr(curr *flag, va_list args, int *ret)
{
	int to_ret;
	unsigned long int n;

	n = va_arg(args, unsigned long int);
	to_ret = ft_strlen(ft_putnbr_base_u(n, HEXD)) + 2;
	write_precision(flag->precision, to_ret);
	to_ret = to_ret < flag->precision ? flag->precision : to_ret;
	flag->width_type != DASH ? write_width(flag, to_ret, -1) : 0;
	ft_putptr(n);
	flag->width_type == DASH ? write_width(flag, to_ret, -1) : 0;
	to_ret = to_ret < flag->width ? flag->width : to_ret;
	*ret += to_ret;
}

int	print_struct(curr *flag, va_list args)
{
	int ret;

	ret = 0;
	flag->type == 'd' ? arg_putnbr(flag, args, &ret) : 0;
	flag->type == 'i' ? arg_putnbr(flag, args, &ret) : 0;
	flag->type == 'u' ? arg_putunsigned(flag, args, &ret) : 0;
	flag->type == 'p' ? arg_putptr(flag, args, &ret) : 0;
	flag->type == 's' ? arg_putstr(flag, args, &ret) : 0;
	flag->type == 'x' ? arg_puthexa(flag, args, &ret) : 0;
	flag->type == 'X' ? arg_puthexa(flag, args, &ret) : 0;
	flag->type == 'c' ? arg_putchar(flag, args, &ret) : 0;
	return (ret);
}

char *get_next_arg(const char *str, int i)
{
	char *ret;

	ret = NULL;
	i++;
	while (str[i])
	{
		ft_putchar_str(&ret, str[i]);
		if (is_arg(ret[ft_strlen(ret) - 1]))
			break ;
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

	i = 0;
	va_list args;
	
	curr flag;
	ret = ft_strlen((char *)str);
	reset_struct(&flag);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (flag.arg = get_next_arg(str, i)) != NULL)
			{
				ret -= ret > 0 ? fill_struct(&flag, args) : 0;
				ret += print_struct(&flag, args);
				i+= ft_strlen(flag.arg) + 1;
				reset_struct(&flag);
			}
			else
			{
				ft_putchar(str[i]);
				i++;
			}		
	}
	va_end(args);
	return (ret);
}
