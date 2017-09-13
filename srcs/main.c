/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/13 10:49:07 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	try_put_piece(t_filler *f, int x, int y);
int	try_put_piece(t_filler *f, int x, int y)
{
	int	score;
	int	i;
	int	j;

	score = 0;
	i = 0;
	j = 0;
	if (i == f->w_piece && j == f->h_piece)
		return (1);
	while (j < f->h_piece)
	{
		while (i < f->w_piece)
		{
			if (f->piece[j][i] == '*' && (y + j - f->y_distance) >= 0 &&
					(y + j - f->y_distance) < f->h_board &&
					(x + i - f->x_distance) >= 0 &&
					(x + i - f->x_distance) < f->w_board)
			{
				if (HMAP == ME || HMAP == EN)
				{
					if (i != f->startx && j != f->starty)
						return (1);
				}
				else
					score += HMAP;
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (f->score == 0 || score < f->score)
	{
		f->score = score;
		f->tempx = x;
		f->tempy = y;
	}
	dprintf(f->ttys, "\nScore = %d\n\n", f->score);
	return (0);
}

void	resolve(t_filler *f);
void	resolve(t_filler *f)
{
	search_first_me(f);
	f->i = 0;
	f->j = 0;
	while (f->i < f->w_piece && f->j < f->h_piece)
	{
		if (f->piece[f->j][f->i] == '*')
		{
			try_put_piece(f, f->x, f->y);
		}
		f->i++;
		if (f->i >= f->w_piece)
		{
			f->i = 0;
			f->j++;
		}
	}
}

int	main(void)
{
	//	while (1)
	//	{
	t_filler	f;


	init_struct_filler(&f);
	dprintf(f.ttys, "\n");
	get_player_info(&f, f.line);
	get_map_info(&f);
	stock_current_map(&f);
	search_ennemy(&f);
	create_heat_map(&f);
	init_heat_map(&f);
	do_heat_map(&f);
	search_heat_max(&f);
	get_piece(&f);
	stock_piece(&f);
	print_piece(&f);
	get_distance_piece_form(&f);
	resolve(&f);
	//	int i = 0;
	//	while (i < 5)
	//	{
	//	get_next_line_backslash(STDIN_FILENO, &f.line);
	//		dprintf(f.ttys, "%s", f.line);
	//		i++;
	//	}

	//	print_map(&f);
	//	dprintf(f.ttys, "x = %d, y = %d\n", f.x_ennemy, f.y_ennemy);

	//	dprintf(f.ttys, "\nHeat Max = %d\n", f.nb_max);
	//	dprintf(f.ttys, "me = -2, ennemy = -1\n");
	print_heat_map(&f);
	printf("8 2\n");
	//	}

	//	dprintf(f.ttys, "%s\n", f.line);

}
