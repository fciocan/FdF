/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:48:50 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 15:48:52 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
