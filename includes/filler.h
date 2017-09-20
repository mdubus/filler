/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:51:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/20 17:02:10 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include <stdio.h>
#include "../libft/includes/libft.h"

# define HEAT f->hmap[y][x]
# define PX1 f->hmap[y][x + 1]
# define PY1 f->hmap[y + 1][x]
# define MX1 f->hmap[y][x - 1]
# define MY1 f->hmap[y - 1][x]
# define PP f->hmap[y + 1][x + 1]
# define MM f->hmap[y - 1][x - 1]
# define MP f->hmap[y - 1][x + 1]
# define PM f->hmap[y + 1][x - 1]
# define ME -2
# define EN -1
# define HMAP f->hmap[y + j - f->y_distance][x + i - f->x_distance]

typedef struct	s_filler
{
	char		**tab;
	char		**map;
	char		**piece;
	int			**hmap;
	char		*line;
	char		*player_name;
	char		letter_me;
	char		letter_ennemy;
	char		padding1;
	char		padding2;
	int			ret;
	int			ttys;
	int			w_board;
	int			h_board;
	int			w_piece;
	int			h_piece;
	int			x_ennemy;
	int			y_ennemy;
	int			x;
	int			y;
	int			nb_max;
	int			x_distance;
	int			y_distance;
	int			tempx;
	int			tempy;
	int			score;
	int			i;
	int			j;
	int			startx;
	int			starty;
	int			flag_star;
}				t_filler;


void	init_struct_filler(t_filler *f);
void	free_tab_char(char ***tab);
void	get_player_info(t_filler *f, char *line);
void	compare_return_error(char *s1, char *s2, int fd);
void	print_map(t_filler *f);
void	stock_current_map(t_filler *f);
void	search_ennemy(t_filler *f);
void	get_map_info(t_filler *f);
void	print_heat_map(t_filler *f);
void	create_heat_map(t_filler *f);
void	init_heat_map(t_filler *f);
void	do_heat_map(t_filler *f);
void	search_heat_max(t_filler *f);
void	get_piece(t_filler *f);
void	print_piece(t_filler *f);
void	stock_piece(t_filler *f);
void	get_distance_piece_form(t_filler *f);
void	search_first_me(t_filler *f);
void	search_next_me(t_filler *f);
int		search_next_star(t_filler *f, int *i, int *j);





#endif
