/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strislower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:20:20 by mdubus            #+#    #+#             */
/*   Updated: 2017/04/17 17:20:56 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strislower(char *str)
{
	int		i;
	int		mark;

	i = 0;
	mark = 1;
	while (str[i] != '\0')
	{
		if ((ft_islower(str[i++])) == 0)
			mark = 0;
	}
	if (mark == 0)
		return (0);
	else
		return (1);
}
