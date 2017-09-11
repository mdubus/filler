/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:29:01 by mdubus            #+#    #+#             */
/*   Updated: 2016/12/18 11:59:03 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_countwords(char const *s, char c)
{
	int	i;
	int	nbwords;

	i = 0;
	nbwords = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nbwords++;
		}
	}
	return (nbwords);
}
