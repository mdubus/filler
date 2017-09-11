/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance_piece_form.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:55:36 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/10 13:56:15 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_distance_piece_form(t_filler *f)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < f->h_piece && f->piece[y][x] != '*')
	{
		while (x < f->w_piece && f->piece[y][x] != '*')
		{
			x++;
		}
		if (f->piece[y][x] != '*')
		{
			x = 0;
			y++;
		}
	}
	f->x_distance = x;
	f->y_distance = y;
}
