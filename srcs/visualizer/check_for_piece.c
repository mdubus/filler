/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:27:45 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:43:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	check_for_piece(t_v *begin, t_visu *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (begin->tab[i] != NULL)
	{
		j = 0;
		while (j < v->nb_x)
		{
			if (begin->tab[i][j] != '.')
				draw_rect(i, j, v, begin);
			j++;
		}
		i++;
	}
}
