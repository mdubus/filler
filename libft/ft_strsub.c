/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:42:07 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/14 13:37:17 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str_new;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	if (s)
	{
		str_new = (char *)malloc((len + 1) * sizeof(char));
		if (str_new == 0)
			return (0);
		while (len > 0)
		{
			str_new[j] = s[i];
			j++;
			i++;
			len--;
		}
		str_new[j] = '\0';
		return (str_new);
	}
	return (0);
}
