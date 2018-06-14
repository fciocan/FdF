/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:54:59 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 14:08:36 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	i;
	char			*str;
	unsigned int	size;

	size = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * (size + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
