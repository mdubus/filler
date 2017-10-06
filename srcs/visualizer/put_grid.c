/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:53:19 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	put_grid_horiz(t_visu *v, t_v *begin)
{
	int			nb_y;
	SDL_Rect	border;
	SDL_Surface	*sborder;

	nb_y = v->nb_y;
	border.x = (v->width_w - v->width_line) / 2;
	border.y = 180 - 1;
	v->startx = border.x;
	v->starty = border.y;
	border.h = 1;
	border.w = v->width_line + 2;
	if ((sborder = SDL_CreateRGBSurface(0, border.w, border.h,
					32, 0, 0, 0, 0)) == NULL)
		free_all_visu(begin, v, "Create RGB Surface failed");
	while (nb_y-- >= 0)
	{
		if (SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format,
						250, 227, 227)) < 0)
			free_all_visu(begin, v, "SDL_FillRect failed");
		if (SDL_BlitSurface(sborder, NULL, v->surf, &border) < 0)
			free_all_visu(begin, v, "SDL_BlitSurface failed");
		border.y += v->square + 1;
	}
	SDL_FreeSurface(sborder);
}

void	put_grid_vertic(t_visu *v, t_v *begin)
{
	SDL_Rect	border;
	SDL_Surface	*sborder;
	int			nb_x;

	v->width_line = v->nb_x * v->square + (v->nb_x - 1);
	v->height_line = v->nb_y * v->square + (v->nb_y - 1);
	nb_x = v->nb_x;
	border.x = (v->width_w - v->width_line) / 2;
	border.y = 180 - 1;
	border.h = v->height_line + 2;
	border.w = 1;
	if ((sborder = SDL_CreateRGBSurface(0, border.w, border.h,
					32, 0, 0, 0, 0)) == NULL)
		free_all_visu(begin, v, "Create RGB Surface failed");
	while (nb_x-- >= 0)
	{
		if (SDL_FillRect(sborder, NULL, SDL_MapRGB(sborder->format,
						250, 227, 227)) < 0)
			free_all_visu(begin, v, "SDL_FillRect failed");
		if (SDL_BlitSurface(sborder, NULL, v->surf, &border) < 0)
			free_all_visu(begin, v, "SDL_BlitSurface failed");
		border.x += v->square + 1;
	}
	SDL_FreeSurface(sborder);
}
