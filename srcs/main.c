/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/11 19:21:19 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	try_put_piece(t_filler *f, int x, int y);
int	try_put_piece(t_filler *f, int x, int y)
{
	dprintf(f->ttys, "coucou\n");
	int	score;

	score = 0;
	search_next_star(f, &f->i, &f->j);
	if (f->i == f->w_piece && f->j == f->h_piece)
		return (1);

	while (f->j < f->h_piece)
	{
		while (f->i < f->w_piece)
		{
			if(HMAP == ME || HMAP == EN)
				return (1);
			else if (f->piece[f->j][f->i] == '*')
				score += HMAP;
			f->i++;
		}
		f->i = 0;
		f->j++;
	}
	if (f->score == 0 || score < f->score)
	{
		f->score = score;
		f->tempx = x;
		f->tempy = y;
	}
	dprintf(f->ttys, "\nScore = %d\n", f->score);
	return (0);
}

void	resolve(t_filler *f);
void	resolve(t_filler *f)
{
	search_first_me(f);
//	search_next_me(f);
	search_first_star(f);
	//	f->i = f->x_distance;
	//	f->j = f->y_distance;
	try_put_piece(f, f->x, f->y);
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
