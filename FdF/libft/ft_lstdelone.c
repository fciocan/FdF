/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciocan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:46:34 by fciocan           #+#    #+#             */
/*   Updated: 2017/12/16 14:05:51 by fciocan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if ((alst == NULL) || (*alst == NULL))
		return ;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
