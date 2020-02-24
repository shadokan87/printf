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

char	*get_next_arg(const char *str, int i)
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
