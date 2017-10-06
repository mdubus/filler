/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:09:43 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 11:10:55 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include <OpenGL/gl3.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <SDL.h>
# include <SDL_video.h>
# include <stdbool.h>
# include <SDL_ttf.h>
# include <SDL_keycode.h>
# include "filler.h"

# define CLOSE 27
# define LEFT 1073741904
# define RIGHT 1073741903

typedef struct	s_v
{
	char		**tab;
	int			current_player;
	int			padding1;
	int			padding2;
	int			padding3;
	struct s_v	*next;
	struct s_v	*prev;
}				t_v;

typedef struct	s_visu
{
	SDL_Window	*window;
	SDL_Surface	*surf;
	TTF_Font	*police;
	TTF_Font	*police_big;
	TTF_Font	*title;
	SDL_Event	event;
	bool		loop;
	SDL_Color	white;
	SDL_Color	purple;
	SDL_Color	pink;
	char		*p1;
	char		*p2;
	char		*line;
	int			nb_x;
	int			nb_y;
	int			status;
	int			resultp1;
	int			resultp2;
	int			width_w;
	int			height_w;
	int			square;
	int			width_line;
	int			height_line;
	int			startx;
	int			starty;
	int			first_time;
	int			padding4;
	t_v			*begin;
}				t_visu;

void			get_player_name_vm(char *line, char	**player);
void			get_p1_vm(char *line, t_visu **v);
void			get_p2_vm(t_visu **v);
void			get_players_vm(t_visu *v);
void			verif_header_vm(void);
void			init_struct_visu(t_visu *v);
void			put_error_fd(char *line, char *str);
void			ft_compare(char *str);
void			get_board_infos(t_v **t, t_visu *v);
void			free_linked_list(t_visu *v, char *line, t_v *begin);
void			stock_link(t_visu **v, t_v **t, t_v *begin);
void			get_results(char **line, t_visu **v, t_v *begin);
void			stock_links(t_visu *v, t_v **t, t_v *begin);
void			free_all_visu(t_v *begin, t_visu *v, const char *s);
void			get_screen_dimensions(t_visu *v, t_v *begin);
SDL_Color		init_color(int r, int g, int b, int a);
void			write_p1(SDL_Surface **temp, t_visu *v, t_v *begin);
void			write_p2(SDL_Surface **temp, t_visu *v, t_v *begin);
void			put_on_screen_sdl(t_visu *v, SDL_Surface *surface, int x,
				int y);
void			write_filler(SDL_Surface **temp, t_visu *v, t_v *begin);
void			init_typo(t_visu *v, t_v *begin);
void			init_sdl(t_visu *v, t_v *begin);
void			put_grid_horiz(t_visu *v, t_v *begin);
void			put_grid_vertic(t_visu *v, t_v *begin);
void			draw_rect(int i, int j, t_visu *v, t_v *begin);
void			free_everything(t_visu *v, t_v *begin);
void			put_result_p1(t_visu *v, t_v *begin);
void			put_result_p2(t_visu *v, t_v *begin);
void			event_loop(t_visu *v, t_v **begin);
void			case_loop_false(t_visu *v);
void			draw_result(t_v **begin, t_visu *v);
void			put_background(t_visu *v, t_v *begin);
void			check_for_piece(t_v *begin, t_visu *v);

#endif
