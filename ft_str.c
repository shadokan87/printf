/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:19:56 by motoure           #+#    #+#             */
/*   Updated: 2020/02/24 09:19:58 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lprintf.h"

void	ft_str(char *str)
{
	if (!str || str[0] == '\0')
		write(1, "(null)", 6);
	else
		write(1, str, ft_strlen(str));
}