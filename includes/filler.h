/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:51:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 11:08:39 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "../libft/includes/libft.h"

# define ME -2
# define EN -1

typedef struct	s_filler
{
	char		**tab;
	char		**map;
	char		**piece;
	int			**hmap;
	char		*line;
	char		letter_me;
	char		letter_ennemy;
	int			is_zero;
	int			w_board;
	int			h_board;
	int			w_piece;
	int			h_piece;
	int			x;
	int			y;
	int			nb_max;
	int			tempx;
	int			tempy;
	int			tempi;
	int			tempj;
	int			score;
	int			i;
	int			j;
	int			startx;
	int			starty;
	int			flag_star;
	int			score2;
	int			tempx2;
	int			tempy2;
}				t_filler;

void			init_struct_filler(t_filler *f);
void			free_tab_char(char ***tab);
void			get_player_info(t_filler *f, char *line);
void			compare_return_error(char *s1, char *s2, char **tab);
void			print_map(t_filler *f);
void			stock_current_map(t_filler *f);
void			get_map_info(t_filler *f);
void			print_heat_map(t_filler *f);
void			create_heat_map(t_filler *f);
void			init_heat_map(t_filler *f);
void			do_heat_map(t_filler *f);
void			get_piece(t_filler *f);
void			print_piece(t_filler *f);
void			stock_piece(t_filler *f);
int				search_next_star(t_filler *f, int *i, int *j);
int				count_score(t_filler *f, int i, int j, int *score);
int				count_before(t_filler *f, int j, int i, int *score);
int				count_after(t_filler *f, int j, int i, int *score);
void			free_all(t_filler *f);
void			free_tab_char(char ***tab);
void			resolve(t_filler *f);
void			free_maps(t_filler *f);

#endif
