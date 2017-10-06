/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:16:20 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 21:31:23 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	fill_hmap_init(int *y, t_filler **f)
{
	int	x;

	x = 0;
	while (x < (*f)->w_board)
	{
		if ((*f)->map[*y][x] == '.')
			(*f)->hmap[*y][x] = 0;
		if ((*f)->map[*y][x] == (*f)->letter_me)
			(*f)->hmap[*y][x] = -2;
		if ((*f)->map[*y][x] == (*f)->letter_ennemy)
			(*f)->hmap[*y][x] = -1;
		x++;
	}
	x = 0;
	(*y)++;
}

int			create_heat_map(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	f->hmap = (int **)malloc(sizeof(int*) * (unsigned long)f->h_board);
	if (!f->hmap)
	{
		free_tab(f);
		return (1);
	}
	while (y < f->h_board)
	{
		f->hmap[y] = (int *)malloc(sizeof(int) * (unsigned long)f->w_board);
		if (!f->hmap[y])
		{
			free_tab(f);
			while (y > 0)
				free(f->hmap[--y]);
			return (1);
		}
		fill_hmap_init(&y, &f);
	}
	return (0);
}
