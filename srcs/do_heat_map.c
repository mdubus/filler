/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heat_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:11:06 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/10 13:53:59 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	put_heat(t_filler *f, int i, int x, int y)
{
	if (x + 1 < f->w_board && PX1 == i && PX1 != ME)
		HEAT = i + 1;
	if (y + 1 < f->h_board && PY1 == i && PY1 != ME)
		HEAT = i + 1;
	if (x + 1 < f->w_board && y + 1 < f->h_board && PP == i && PP != ME)
		HEAT = i + 1;
	if (x + 1 < f->w_board && y - 1 >= 0 && MP == i && MP != ME)
		HEAT = i + 1;
	if (x - 1 >= 0 && MX1 == i && MX1 != ME)
		HEAT = i + 1;
	if (y - 1 >= 0 && MY1 == i && MY1 != ME)
		HEAT = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && MM == i && MM != ME)
		HEAT = i + 1;
	if (x - 1 >= 0 && y + 1 < f->h_board && PM == i && PM != ME)
		HEAT = i + 1;
}

void	do_heat_map(t_filler *f)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 1;
	while (i < f->w_board)
	{
		while (y < f->h_board)
		{
			while (x < f->w_board)
			{
				if (HEAT == 0)
					put_heat(f, i, x, y);
				x++;
			}
			x = 0;
			y++;
		}
		x = 0;
		y = 0;
		i++;
	}
}

void	search_heat_max(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < f->h_board)
	{
		while (x < f->w_board)
		{
			if (f->hmap[y][x] > f->nb_max)
				f->nb_max = f->hmap[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}
