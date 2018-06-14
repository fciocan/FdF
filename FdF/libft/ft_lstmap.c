/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:47:01 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 14:06:02 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a;
	t_list	*b;

	if (lst == NULL)
		return (NULL);
	b = f(lst);
	a = b;
	if (a == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		b->next = f(lst);
		if (b->next == NULL)
			return (NULL);
		b = b->next;
	}
	return (a);
}
