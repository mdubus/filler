/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heat_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:09:36 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 16:21:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_heat_map2(t_filler *f, int x, int y)
{
	if (x + 1 < f->w_board && f->hmap[y][x + 1] == EN)
		f->hmap[y][x] = 1;
	if (y + 1 < f->h_board && f->hmap[y + 1][x] == EN)
		f->hmap[y][x] = 1;
	if (x + 1 < f->w_board && y + 1 < f->h_board &&
			f->hmap[y + 1][x + 1] == EN)
		f->hmap[y][x] = 1;
	if (x + 1 < f->w_board && y - 1 >= 0 && f->hmap[y - 1][x + 1] == EN)
		f->hmap[y][x] = 1;
	if (x - 1 >= 0 && f->hmap[y][x - 1] == EN)
		f->hmap[y][x] = 1;
	if (y - 1 >= 0 && f->hmap[y - 1][x] == EN)
		f->hmap[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && f->hmap[y - 1][x - 1] == EN)
		f->hmap[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < f->h_board && f->hmap[y + 1][x - 1] == EN)
		f->hmap[y][x] = 1;
}

void		init_heat_map(t_filler *f)
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
			if (f->hmap[y][x] == 0)
				init_heat_map2(f, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
