/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:27:23 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 16:17:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	get_score(t_filler *f, int score)
{
	if (f->is_zero == 1)
	{
		if ((score <= f->score && score > 0) || (score > 0 && f->score == 0))
		{
			f->score = score;
			f->tempx = f->x - f->i;
			f->tempy = f->y - f->j;
		}
		else
		{
			f->score2 = score;
			f->tempx2 = f->x - f->i;
			f->tempy2 = f->y - f->j;
		}
	}
	else
	{
		if (score < f->score || f->score == 0)
		{
			f->score = score;
			f->score2 = score;
			f->tempx2 = f->x - f->i;
			f->tempy2 = f->y - f->j;
		}
	}
}

static void	foreach_star(t_filler *f)
{
	int	score;

	score = 0;
	f->i = 0;
	f->j = 0;
	while (search_next_star(f, &f->i, &f->j) == 1)
	{
		score = 0;
		f->startx = f->i;
		f->starty = f->j;
		if (count_before(f, f->j, f->i, &score) == 0 &&
				count_after(f, f->j, f->i, &score) == 0)
		{
			get_score(f, score);
		}
	}
	if (f->score == 0)
	{
		f->score = f->score2;
		f->tempx = f->tempx2;
		f->tempy = f->tempy2;
	}
}

static void	search_after_zero(t_filler *f)
{
	f->is_zero = 0;
	while (f->y < f->h_board)
	{
		while (f->x < f->w_board)
		{
			if (f->hmap[f->y][f->x] > 0)
				f->is_zero = 1;
			f->x++;
		}
		f->x = 0;
		f->y++;
	}
	f->x = 0;
	f->y = 0;
}

void		resolve(t_filler *f)
{
	f->y = 0;
	f->x = 0;
	f->score = 0;
	f->tempx = 0;
	f->tempy = 0;
	f->score2 = 0;
	f->tempx2 = 0;
	f->tempy2 = 0;
	search_after_zero(f);
	while (f->y < f->h_board)
	{
		while (f->x < f->w_board)
		{
			if (f->hmap[f->y][f->x] == ME)
			{
				foreach_star(f);
			}
			f->x++;
		}
		f->x = 0;
		f->y++;
	}
}
