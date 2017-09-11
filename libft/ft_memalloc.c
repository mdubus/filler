/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:27:50 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/11 18:13:35 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size * sizeof(void *));
	if (memory == 0)
		return (0);
	ft_bzero(memory, size);
	return (memory);
}
