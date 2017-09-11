/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:15:26 by mdubus            #+#    #+#             */
/*   Updated: 2017/04/17 17:20:10 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strisupper(char *str)
{
	int		i;
	int		mark;

	i = 0;
	mark = 1;
	while (str[i] != '\0')
	{
		if ((ft_isupper(str[i++])) == 0)
			mark = 0;
	}
	if (mark == 0)
		return (0);
	else
		return (1);
}
