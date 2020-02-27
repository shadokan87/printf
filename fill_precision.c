/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:16:09 by motoure           #+#    #+#             */
/*   Updated: 2020/02/24 09:16:11 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lprintf.h"

void	fill_precision(t_curr *flag, va_list args)
{
	int		i;
	char	*tmp;

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
	flag->precision = flag->precision == 0 ? -1 : flag->precision;
	tmp ? free(tmp) : 0;
}
