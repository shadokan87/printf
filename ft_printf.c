/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 08:16:21 by motoure           #+#    #+#             */
/*   Updated: 2020/02/24 10:14:45 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	t_curr	flag;
	va_list args;

	i = 0;
	ret = ft_strlen((char *)str);
	reset_struct(&flag);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (flag.arg = get_next_arg(str, i)) != NULL)
		{
			ret -= ret > 0 ? fill_struct(&flag, args) : 0;
			ret += print_struct(&flag, args);
			i += ft_strlen(flag.arg) + 1;
			reset_struct(&flag);
		}
		else
			write_const(str, &i);
	}
	va_end(args);
	return (ret);
}
