/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:20:12 by motoure           #+#    #+#             */
/*   Updated: 2020/02/24 09:22:10 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lprintf.h"

void	write_star(char **ret, int n)
{
	char *tmp;

	tmp = NULL;
	if (n < 0)
		n *= -1;
	tmp = ft_putnbr_base(n, DEC);
	while (*tmp)
	{
		ft_putchar_str(ret, tmp[0]);
		tmp++;
	}
}

char	*get_next_arg(const char *str, int i, va_list args)
{
	char *ret;
	char *star;

	ret = NULL;
	i++;
	while (str && str[i])
	{
		str[i] == STAR ? write_star(&ret, va_arg(args, int)) : 0;
		str[i] != STAR ? ft_putchar_str(&ret, str[i]) : 0;
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
