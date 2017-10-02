/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerSDL.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 11:03:58 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/02 16:22:57 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERSDL_H
#define HEADERSDL_H

//#include <OpenGL/gl3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include <SDL.h>
//#include <SDL_video.h>
#include <stdbool.h>
//#include <SDL_ttf.h>
//#include <SDL_keycode.h>
#include "filler.h"

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
//	SDL_Window	*window;
//	SDL_Surface	*surf;
//	TTF_Font	*police;
//	TTF_Font	*title;
//	SDL_Color	white;
//	SDL_Color	purple;
//	SDL_Color	pink;
//	SDL_Rect	rect;
	char		*p1;
	char		*p2;
	char		*line;
	int			nb_x;
	int			nb_y;
	int			status;
	int			padding4;
}				t_visu;

/*
void		init_struct_visu(t_visu *v);
void		init_SDL(t_visu *v);
SDL_Color	init_color(int r, int g, int b, int a);
void		get_player_name(char *line, char **player);
void		get_players(t_visu *v);
void		set_header(t_visu *v);
void	put_on_screen_sdl(t_visu *v, SDL_Surface *texte, int x, int y);
void	get_window_size(t_visu *v);
void	set_params_rects(t_visu *v, int width_w, int width_r, char **tab);
void	put_grid_horiz(t_visu *v);
void	put_grid_vertic(t_visu *v);*/

void	get_player_name_vm(char *line, char	**player);
void	get_p1_vm(char *line, t_visu *v);
void	get_p2_vm(t_visu *v);
void	get_players_vm(t_visu *v);
void	verif_header_vm(void);
void	init_struct_visu(t_visu *v);
void	put_error_fd(char *line, char *str) __attribute__((noreturn));
void	ft_compare(char *str);
void	get_board_infos(t_v **t, t_visu *v);



#endif
