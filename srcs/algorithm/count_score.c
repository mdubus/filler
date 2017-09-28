/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:22:28 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/23 15:23:16 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		count_score(t_filler *f, int i, int j, int *score)
{
	if (f->y + j - f->tempj < 0 || f->y + j - f->tempj >= f->h_board ||
			f->x + i - f->tempi < 0 || f->x + i - f->tempi >= f->w_board)
		return (1);
	if (f->hmap[f->y + j - f->tempj][f->x + i - f->tempi] == ME ||
			f->hmap[f->y + j - f->tempj][f->x + i - f->tempi] == EN)
	{
		if (i != f->tempi || j != f->tempj)
			return (1);
	}
	if (f->hmap[f->y + j - f->tempj][f->x + i - f->tempi] != ME)
		*score += f->hmap[f->y + j - f->tempj][f->x + i - f->tempi];
	return (0);
}

int		count_before(t_filler *f, int j, int i, int *score)
{
	f->tempj = j;
	f->tempi = i;
	while (j >= 0)
	{
		while (i >= 0)
		{
			if (f->piece[j][i] == '*')
			{
				if (count_score(f, i, j, score) == 1)
					return (1);
			}
			i--;
		}
		i = f->w_piece - 1;
		j--;
	}
	return (0);
}

int		count_after(t_filler *f, int j, int i, int *score)
{
	f->tempj = j;
	f->tempi = i;
	while (j < f->h_piece)
	{
		while (i < f->w_piece)
		{
			if (f->piece[j][i] == '*')
			{
				if (count_score(f, i, j, score) == 1)
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
