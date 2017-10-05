/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heat_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:11:06 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 16:24:36 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	put_heat(t_filler *f, int i, int x, int y)
{
	if (x + 1 < f->w_board && f->hmap[y][x + 1] == i)
		f->hmap[y][x] = i + 1;
	if (y + 1 < f->h_board && f->hmap[y + 1][x] == i)
		f->hmap[y][x] = i + 1;
	if (x + 1 < f->w_board && y + 1 < f->h_board && f->hmap[y + 1][x + 1] == i)
		f->hmap[y][x] = i + 1;
	if (x + 1 < f->w_board && y - 1 >= 0 && f->hmap[y - 1][x + 1] == i)
		f->hmap[y][x] = i + 1;
	if (x - 1 >= 0 && f->hmap[y][x - 1] == i)
		f->hmap[y][x] = i + 1;
	if (y - 1 >= 0 && f->hmap[y - 1][x] == i)
		f->hmap[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && f->hmap[y - 1][x - 1] == i)
		f->hmap[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < f->h_board && f->hmap[y + 1][x - 1] == i)
		f->hmap[y][x] = i + 1;
}

void		do_heat_map(t_filler *f)
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
				if (f->hmap[y][x] == 0)
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
