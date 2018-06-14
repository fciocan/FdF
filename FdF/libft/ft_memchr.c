/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:44:12 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 14:06:13 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	size_t			i;

	i = 0;
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == c2)
		{
			return (((void *)s2) + i);
		}
		i++;
	}
	return (NULL);
}
