/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:52:55 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/30 14:53:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	put_grid_horiz(t_visu *v)
{
	int			nb_y;
	SDL_Rect	border;
	SDL_Surface	*sborder;

	nb_y = v->nb_y;
	border.x = (v->width_w - v->width_line) / 2;
	border.y = 180 - 1;
	border.h = 1;
	border.w = v->width_line + 2;
	sborder = SDL_CreateRGBSurface(0, border.w, border.h, 32, 0, 0, 0, 0);
	while (nb_y-- >= 0)
	{
		SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format, 250, 227, 227));
		SDL_BlitSurface(sborder, NULL, v->surf, &border);
		border.y += v->rect.h + 1;
	}
	SDL_FreeSurface(sborder);
}

void	put_grid_vertic(t_visu *v)
{
	SDL_Rect	border;
	SDL_Surface	*sborder;
	int			nb_x;

	v->width_line = v->nb_x * v->rect.w + (v->nb_x - 1);
	v->height_line = v->nb_y * v->rect.h + (v->nb_y - 1);
	nb_x = v->nb_x;
	border.x = (v->width_w - v->width_line) / 2;
	border.y = 180 - 1;
	border.h = v->height_line + 2;
	border.w = 1;
	sborder = SDL_CreateRGBSurface(0, border.w, border.h, 32, 0, 0, 0, 0);
	while (nb_x-- >= 0)
	{
		SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format, 250, 227, 227));
		SDL_BlitSurface(sborder, NULL, v->surf, &border);
		border.x += v->rect.w + 1;
	}
	SDL_FreeSurface(sborder);
}
