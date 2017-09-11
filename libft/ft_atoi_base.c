/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 22:04:06 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/05 22:36:39 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	check_char_begin(char *cpy, int *i)
{
	while (ft_isalnum(cpy[*i]) == 0 && cpy[*i] != '+' && cpy[*i] != '-' &&
			cpy[*i] != '\0')
		(*i)++;
}

int			ft_atoi_base(const char *str, int base)
{
	long	result;
	char	*cpy;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	cpy = ft_strdup(str);
	ft_strtoupper(&cpy);
	if (base <= 1 || base > 36)
		return (0);
	check_char_begin(cpy, &i);
	sign = (cpy[i] == '-') ? -1 : 1;
	if (cpy[i] == '-' || cpy[i] == '+')
		i++;
	while (cpy[i] != '\0')
	{
		if (ft_isdigit(cpy[i]) == 1)
			result = result * base + (cpy[i] - '0');
		else if (ft_isalpha(cpy[i]) == 1)
			result = result * base + (cpy[i] - 'A' + 10);
		i++;
	}
	free(cpy);
	return (result * (long)sign);
}
