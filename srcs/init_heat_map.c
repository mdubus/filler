/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heat_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:09:36 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/10 13:54:34 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_heat_map2(t_filler *f, int i, int x, int y)
{
	if (x + 1 < f->w_board && PX1 == i - 1 && PX1 != ME)
		HEAT = i + 1;
	if (y + 1 < f->h_board && PY1 == i - 1 && PY1 != ME)
		HEAT = i + 1;
	if (x + 1 < f->w_board && y + 1 < f->h_board && PP == i - 1 && PP != ME)
		HEAT = i + 1;
	if (x + 1 < f->w_board && y - 1 >= 0 && MP == i - 1 && MP != ME)
		HEAT = i + 1;
	if (x - 1 >= 0 && MX1 == i - 1 && MX1 != ME)
		HEAT = i + 1;
	if (y - 1 >= 0 && MY1 == i - 1 && MY1 != ME)
		HEAT = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && MM == i - 1 && MM != ME)
		HEAT = i + 1;
	if (x - 1 >= 0 && y + 1 < f->h_board && PM == i - 1 && PM != ME)
		HEAT = i + 1;
}

void	init_heat_map(t_filler *f)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (y < f->h_board)
	{
		while (x < f->w_board)
		{
			if (HEAT == 0)
				init_heat_map2(f, i, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
