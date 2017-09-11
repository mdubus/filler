/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:16:33 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/16 13:20:37 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*test;

	test = begin_list;
	i = 0;
	while (test != NULL)
	{
		test = test->next;
		i++;
	}
	return (i);
}
