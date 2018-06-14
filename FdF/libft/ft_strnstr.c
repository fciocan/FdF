/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:54:40 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 14:09:11 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int little_s;
	int	big_s;
	int ok;
	int i;
	int j;

	if (*little == '\0')
		return ((char*)big);
	little_s = ft_strlen(little);
	big_s = ft_strlen(big);
	i = -1;
	while (++i <= big_s - little_s)
	{
		j = -1;
		ok = 1;
		if ((size_t)(i + little_s) > len)
			return (0);
		while (++j < little_s)
			if (big[i + j] != little[j])
				ok = 0;
		if (ok)
			return ((char*)&big[i]);
	}
	return (0);
}
