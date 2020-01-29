/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:17:40 by motoure           #+#    #+#             */
/*   Updated: 2019/11/08 13:52:57 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lprintf.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (dst == NULL)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
