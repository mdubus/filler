/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/21 18:33:53 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		count_score(t_filler *f, int i, int j, int *score);
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

int		count_before(t_filler *f, int j, int i, int *score);
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

int		count_after(t_filler *f, int j, int i, int *score);
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

void	foreach_star(t_filler *f);
void	foreach_star(t_filler *f)
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
			if (score < f->score || f->score == 0)
			{
				f->score = score;
				f->tempx = f->x - f->i;
				f->tempy = f->y - f->j;
			}
		}

	}
}

void	resolve(t_filler *f);
void	resolve(t_filler *f)
{
	f->y = 0;
	f->x = 0;
	f->score = 0;
	f->tempx = 0;
	f->tempy = 0;
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

int	main(void)
{
	t_filler	f;

	init_struct_filler(&f);
	get_player_info(&f, f.line);
	while (1)
	{
		get_map_info(&f);
		stock_current_map(&f);
		create_heat_map(&f);
		init_heat_map(&f);
		do_heat_map(&f);
		//		print_heat_map(&f);
		search_heat_max(&f);
		get_piece(&f);
		stock_piece(&f);
		//		print_piece(&f);
		resolve(&f);
		printf("%d %d\n", f.tempy, f.tempx);
		fflush(stdout);
	}
}
