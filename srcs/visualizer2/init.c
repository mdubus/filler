/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:32:00 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/01 18:12:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	init_struct_visu(t_visu *v)
{
	v->loop = true;
	v->window = NULL;
	v->surf = NULL;
	v->title = NULL;
	v->police = NULL;
	v->white = init_color(255, 255, 255, 255);
	v->purple = init_color(215, 149, 242, 255);
	v->pink = init_color(237, 101, 162, 255);
	v->width_line = 0;
	v->height_line = 0;
	v->ret = -1;
}

void	init_SDL(t_visu *v)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		dprintf(STDERR_FILENO, "Unable to initialize SDL: %s", SDL_GetError());
		exit(1);
	}
	if(TTF_Init()==-1)
	{
		dprintf(STDERR_FILENO, "TTF_Init: %s\n", TTF_GetError());
		exit(1);
	}
	v->window = SDL_CreateWindow("mdubus's Filler", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, v->width_w, v->height_w,
			SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
	v->title = TTF_OpenFont("srcs/visualizer/KGSecondChancesSketch.ttf", 55);
	if(!v->title)
	{
	    dprintf(STDERR_FILENO, "TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}
	v->police = TTF_OpenFont("srcs/visualizer/KGSecondChancesSketch.ttf", 30);
	if(!v->police)
	{
		dprintf(STDERR_FILENO, "TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}
}
