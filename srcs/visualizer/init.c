/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:23:41 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:13 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	verif_header_vm(void)
{
	ft_compare("# -------------- VM  version 1.1 ------------- #");
	ft_compare("#                                              #");
	ft_compare("# 42 / filler VM Developped by: Hcao - Abanlin #");
	ft_compare("#                                              #");
	ft_compare("# -------------------------------------------- #");
}

void	init_struct_visu(t_visu *v)
{
	v->p1 = NULL;
	v->p2 = NULL;
	v->line = NULL;
	v->nb_x = 0;
	v->nb_y = 0;
	v->status = -1;
	v->resultp1 = 0;
	v->resultp2 = 0;
	v->width_w = 0;
	v->height_w = 0;
	v->square = 0;
	v->width_line = 0;
	v->height_line = 0;
	v->startx = 0;
	v->starty = 0;
	v->loop = true;
	v->white = init_color(255, 255, 255, 255);
	v->purple = init_color(215, 149, 242, 255);
	v->pink = init_color(237, 101, 162, 255);
	v->first_time = 0;
}

void	init_typo(t_visu *v, t_v *begin)
{
	v->title = TTF_OpenFont("srcs/visualizer/KGSecondChancesSketch.ttf", 55);
	if (!v->title)
	{
		ft_putstr("Unable to initialize title : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	v->police = TTF_OpenFont("srcs/visualizer/KGSecondChancesSketch.ttf", 30);
	if (!v->police)
	{
		ft_putstr("Unable to initialize police : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	v->police_big = TTF_OpenFont("srcs/visualizer/KGSecondChancesSketch.ttf",
			35);
	if (!v->police_big)
	{
		ft_putstr("Unable to initialize police_big : ");
		free_all_visu(begin, v, SDL_GetError());
	}
}

void	init_sdl(t_visu *v, t_v *begin)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("Unable to initialize SDL : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if (TTF_Init() == -1)
	{
		ft_putstr("TTF_init : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((v->window = SDL_CreateWindow("mdubus's Filler", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, v->width_w, v->height_w,
					SDL_WINDOW_SHOWN)) == NULL)
	{
		ft_putstr("Unable to initialize window : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	init_typo(v, begin);
	if ((v->surf = SDL_GetWindowSurface(v->window)) == NULL)
	{
		ft_putstr("Unable to initialize surface : ");
		free_all_visu(begin, v, SDL_GetError());
	}
}
