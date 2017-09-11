/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:42:44 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/16 11:30:43 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**temp;

	temp = alst;
	while ((*alst))
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (*alst)->next;
	}
	*temp = NULL;
}
