/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:17:28 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/13 13:22:59 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_count_length(int n)
{
	int		n_cpy;
	int		length;

	n_cpy = n;
	length = 1;
	while (n_cpy / 10 != 0)
	{
		n_cpy = n_cpy / 10;
		length++;
	}
	return (length);
}

static int		check_sign(int n)
{
	int	sign;

	if (n < 0)
		sign = 1;
	else
		sign = 2;
	return (sign);
}

static char		*do_itoa(char *str, int length, int n)
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

char			*ft_itoa(int n)
{
	int		length;
	char	*str;
	int		sign;

	length = ft_count_length(n);
	sign = check_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (sign == 1)
	{
		length = length + 1;
		n = -n;
	}
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str = do_itoa(str, length, n);
	if (sign == 1)
		str[0] = '-';
	return (str);
}
