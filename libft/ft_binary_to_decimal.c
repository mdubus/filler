/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:40:01 by mdubus            #+#    #+#             */
/*   Updated: 2017/02/12 11:14:33 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_binary_to_decimal(char *str)
{
	int		i;
	int		nb;
	int		puissance;
	int		binaire;
	int		number;

	if (str == NULL)
		str = NULL;
	i = 0;
	nb = 0;
	binaire = 2;
	puissance = 7;
	while (puissance >= 0)
	{
		if (str[i] == '1')
			number = 1;
		else
			number = 0;
		nb = nb + number * ft_nb_puissance_nb(2, puissance);
		puissance--;
		i++;
	}
	return (nb);
}
