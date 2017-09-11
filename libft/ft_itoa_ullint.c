/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ullint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:49:41 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/13 19:03:25 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_count_length(unsigned long long int n)
{
	unsigned long long int	n_cpy;
	int						length;

	n_cpy = n;
	length = 1;
	while (n_cpy / 10 != 0)
	{
		n_cpy = n_cpy / 10;
		length++;
	}
	return (length);
}

static char		*do_itoa(char *str, int length, unsigned long long int n)
{
	str[length] = '\0';
	length--;
	if (n == 0)
		str[length] = 0 + '0';
	while (n != 0)
	{
		str[length] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (str);
}

char			*ft_itoa_ullint(unsigned long long int n)
{
	int		length;
	char	*str;

	length = ft_count_length(n);
	str = (char *)malloc((unsigned long long int)(length + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str = do_itoa(str, length, n);
	return (str);
}
