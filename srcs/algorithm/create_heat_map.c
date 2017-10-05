/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:16:20 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 16:03:41 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	create_heat_map(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	f->hmap = (int **)malloc(sizeof(int*) * (unsigned long)f->h_board);
	while (y < f->h_board)
	{
		f->hmap[y] = (int *)malloc(sizeof(int) * (unsigned long)f->w_board);
		while (x < f->w_board)
		{
			if (f->map[y][x] == '.')
				f->hmap[y][x] = 0;
			if (f->map[y][x] == f->letter_me)
				f->hmap[y][x] = -2;
			if (f->map[y][x] == f->letter_ennemy)
				f->hmap[y][x] = -1;
			x++;
		}
		x = 0;
		y++;
	}
}
