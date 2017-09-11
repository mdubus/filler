/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b_llint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:23:20 by mdubus            #+#    #+#             */
/*   Updated: 2017/02/12 11:25:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	result_base(long long int temp, unsigned int base, char **result)
{
	size_t			length;
	int				is_neg;
	long long int	temp2;

	length = 0;
	is_neg = 0;
	temp2 = temp;
	while (temp != 0)
	{
		temp = temp / base;
		length++;
	}
	*result = ft_strnew(length + 1);
	while (temp2 != 0)
	{
		if (temp2 % base < 10)
			(*result)[length - 1] = (char)(temp2 % base) + '0';
		else
			(*result)[length - 1] = (char)(temp2 % base) + 'a' - 10;
		temp2 = temp2 / base;
		length--;
	}
}

char		*ft_itoa_b_llint(long long int nb, unsigned int base)
{
	long long int		temp;
	char				*result;

	temp = 0;
	if (nb)
		temp = nb;
	else
		return (ft_strdup("0"));
	result_base(temp, base, &result);
	return (result);
}
