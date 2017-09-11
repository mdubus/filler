/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ennemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:19:51 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/09 16:57:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	search_ennemy(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (f->map[y][x] != f->letter_ennemy && f->map[y] != NULL)
	{
		while (f->map[y][x] != f->letter_ennemy && f->map[y][x]!= '\0')
		{
			x++;
		}
		if (f->map[y][x] != f->letter_ennemy)
		{
			x = 0;
			y++;
		}
	}
	f->x_ennemy = x;
	f->y_ennemy = y;
}
