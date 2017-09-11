/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:10:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/17 10:45:01 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_fill_with(size_t size, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * size + 1);
	str[size + 1] = '\0';
	while (i <= size)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
