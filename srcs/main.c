/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/20 18:24:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	try_put_piece(t_filler *f, int x, int y);
int	try_put_piece(t_filler *f, int x, int y)
{
	dprintf(f->ttys, "\n\x1b[32m TRY PUT PIECE \x1b[0m\n");
	dprintf(f->ttys, "x = %d, y = %d\n\n", x, y);
	int	score;
	int	i;
	int	j;

	score = 0;
	i = 0;
	j = 0;
	
	while (j < f->h_piece)
	{
		while (i < f->w_piece)
		{
			if (f->piece[j][i] == '*')
			{
				dprintf(f->ttys, "%d ", f->hmap[y + j - f->y_distance][x + i - f->x_distance]);
			}
			i++;
		}
		i = 0;
		j++;
	}
	dprintf(f->ttys, "\n");
	return (0);
}

void	count_before(t_filler *f, int j, int i, int *score);
void	count_before(t_filler *f, int j, int i, int *score)
{
	(void)score;
	int	tempj;
	int	tempi;

	tempj = j;
	tempi = i;
	while (j >= 0)
	{
		while (i >= 0)
		{
			if (f->piece[j][i] == '*' && f->hmap[f->y - j][f->x - i] != ME && f->hmap[f->y - j][f->x - i] != EN)
			{
				dprintf(f->ttys, "%d\n", f->hmap[f->y - tempj][f->x - tempi]);
	//			*score += f->hmap[f->y - j][f->x - i];
			}
			i--;
		}
		i = f->w_piece - 1;
		j--;
	}
}

void	foreach_star(t_filler *f, int *score);
void	foreach_star(t_filler *f, int *score)
{
	f->i = 0;
	f->j = 0;
		dprintf(f->ttys, "h = %d, w = %d\n\n", f->h_piece, f->w_piece);
		while (search_next_star(f, &f->i, &f->j) == 1)
		{
			f->startx = f->i;
			f->starty = f->j;
			dprintf(f->ttys, "j = %d, i = %d\n", f->j, f->i);
			count_before(f, f->j, f->i, score);
	//		dprintf(f->ttys, "score = %d\n", *score);
		//	count_after(f, f->j, f->i, &score);
			
			//			try_put_piece(f, f->x, f->y);
		}
}

void	resolve(t_filler *f);
void	resolve(t_filler *f)
{
	int	score;

	score = 0;
	f->y = 0;
	f->x = 0;
	f->score = 0;
	while (f->y < f->h_board)
	{
		while (f->x < f->w_board)
		{
			if (f->hmap[f->y][f->x] == ME)
			{
				score = 0;
				foreach_star(f, &score);
			}
			f->x++;
		}
		f->x = 0;
		f->y++;
	}
}

int	main(void)
{
	//	while (1)
	//	{

	t_filler	f;

	init_struct_filler(&f);
	dprintf(f.ttys, "\n\x1b[1;32m=======================\n *** START *** \x1b[0m\n\n");
	get_player_info(&f, f.line);
	while (1)
	{
		//		dprintf(f.ttys, "\x1b[33m In while 1 \x1b[0m\n");
		get_map_info(&f);
		//		dprintf(f.ttys, "\x1b[33m In stock map \x1b[0m\n");
		stock_current_map(&f);
		//		dprintf(f.ttys, "\x1b[33m Out of stock map \x1b[0m\n");
		//	search_ennemy(&f);
		create_heat_map(&f);
		init_heat_map(&f);
		do_heat_map(&f);
		print_heat_map(&f);
		search_heat_max(&f);
		get_piece(&f);
		//		dprintf(f.ttys, "\x1b[33m In stock piece \x1b[0m\n");
		stock_piece(&f);
		//		dprintf(f.ttys, "\x1b[33m Out of stock piece \x1b[0m\n");
		print_piece(&f);
		get_distance_piece_form(&f);
		resolve(&f);
		//	dprintf(f.ttys, "\n%d %d\n", f.tempy, f.tempx);
		printf("%d %d\n", f.tempy, f.tempx);
		fflush(stdout);
		//dprintf(1, "%d %d\n", f.tempy, f.tempx);
		//	printf("8 2\n");
	}







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
	//	print_heat_map(&f);
	//	printf("8 2\n");
	//	}

	//	dprintf(f.ttys, "%s\n", f.line);

}
