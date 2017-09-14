/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_first_next_me.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:19:28 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/14 15:12:46 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	search_first_me(t_filler *f)
{
	while (f->y < f->h_board && f->hmap[f->y][f->x] != ME)
	{
		while (f->x < f->w_board && f->hmap[f->y][f->x] != ME)
		{
			f->x++;
		}
		if (f->x == f->w_board)
		{
			f->x = 0;
			f->y++;
		}
	}
//	dprintf(f->ttys, "\nxme = %d, yme = %d\n", f->x, f->y);
}


void	search_next_me(t_filler *f)
{
	if (f->x + 1 < f->w_board)
		f->x++;
	else if (f->y + 1 < f->h_board)
	{
		f->x = 0;
		f->y++;
	}
	if (f->y < f->h_board && f->x < f->w_board)
	{
		while (f->y < f->h_board && f->hmap[f->y][f->x] != ME)
		{
			while (f->x < f->w_board && f->hmap[f->y][f->x] != ME)
			{
				f->x++;
			}
			if (f->x == f->w_board)
			{
				f->x = 0;
				f->y++;
			}
		}
//		dprintf(f->ttys, "\nxme = %d, yme = %d\n", f->x, f->y);
	}
}
