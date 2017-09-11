/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/11 15:43:24 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	try_put_piece(t_filler *f, int x, int y);
int	try_put_piece(t_filler *f, int x, int y)
{
	int	score;

	score = 0;
	int	i;
	int	j;

	i = f->x_distance;
	j = f->y_distance;
	if (i + 1 < f->w_piece)
		i++;
	else if (j + 1 < f->h_piece)
	{
		i = 0;
		j++;
	}
	else
		return (1);

	while (j < f->h_piece && f->piece[j][i] != '*')
	{
		while (i < f->w_piece && f->piece[j][i] != '*')
		{
			i++;
		}
		if (f->piece[j][i] != '*')
		{
			i = 0;
			j++;
		}
	}





	while (j < f->h_piece)
	{
		while (i < f->w_piece)
		{
			if(HMAP == ME || HMAP == EN)
				return (1);
			else if (f->piece[j][i] == '*')
				score += HMAP;
			i++;
		}
		i = 0;
		j++;
	}
	if (f->score == 0 || score < f->score)
		f->score = score;
	dprintf(f->ttys, "\nScore = %d\n", f->score);
	return (0);
}

void	search_me(t_filler *f);
void	search_me(t_filler *f)
{
	while (f->y_me < f->h_board && f->hmap[f->y_me][f->x_me] != ME)
	{
		while (f->x_me < f->w_board && f->hmap[f->y_me][f->x_me] != ME)
		{
			f->x_me++;
		}
		if (f->x_me == f->w_board)
		{
			f->x_me = 0;
			f->y_me++;
		}
	}
	dprintf(f->ttys, "\nxme = %d, yme = %d\n", f->x_me, f->y_me);
}

void	resolve(t_filler *f);
void	resolve(t_filler *f)
{
	search_me(f);
	try_put_piece(f, f->x_me, f->y_me);
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

	dprintf(f.ttys, "\nHeat Max = %d\n", f.nb_max);
	dprintf(f.ttys, "me = -2, ennemy = -1\n");
	print_heat_map(&f);
	printf("8 2\n");
	//	}

	//	dprintf(f.ttys, "%s\n", f.line);

}
