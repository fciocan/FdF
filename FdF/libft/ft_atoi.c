/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:07:33 by fciocan           #+#    #+#             */
/*   Updated: 2018/02/08 17:34:07 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str, int *k)
{
	int		s;
	int		r;

	r = 0;
	s = 1;
	while (str[*k] >= 0 && str[*k] <= 32)
		(*k)++;
	if (str[*k] == '-')
		s = -1;
	if (str[*k] == '+' || str[*k] == '-')
		(*k)++;
	while (str[*k] && str[*k] >= '0' && str[*k] <= '9')
	{
		r = r * 10 + str[*k] - '0';
		(*k)++;
	}
	return (s * r);
}
