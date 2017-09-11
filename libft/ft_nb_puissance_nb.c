/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_puissance_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:37:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/12 12:39:06 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_nb_puissance_nb(int nb, int puissance)
{
	int	result;

	result = nb;
	if (puissance == 0)
		return (1);
	else if (puissance == 1)
		return (nb);
	while (puissance > 1)
	{
		result = result * nb;
		puissance--;
	}
	return (result);
}
