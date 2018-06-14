/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:54:24 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 14:08:23 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	while ((dst[i] != '\0') && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
