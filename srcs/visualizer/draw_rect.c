/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:49:39 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:43:48 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	draw_my_rect(SDL_Surface *sborder, t_v *begin, t_visu *v)
{
	if (SDL_FillRect(sborder, NULL,
				SDL_MapRGB(sborder->format, 175, 109, 202)) < 0)
	{
		SDL_FreeSurface(sborder);
		free_all_visu(begin, v, "SDL_FillRect failed");
	}
}

static void	draw_my_current_rect(SDL_Surface *sborder, t_v *begin, t_visu *v)
{
	if (SDL_FillRect(sborder, NULL,
				SDL_MapRGB(sborder->format, 225, 159, 252)) < 0)
	{
		SDL_FreeSurface(sborder);
		free_all_visu(begin, v, "SDL_FillRect failed");
	}
}

static void	draw_en_rect(SDL_Surface *sborder, t_v *begin, t_visu *v)
{
	if (SDL_FillRect(sborder, NULL,
				SDL_MapRGB(sborder->format, 197, 61, 122)) < 0)
	{
		SDL_FreeSurface(sborder);
		free_all_visu(begin, v, "SDL_FillRect failed");
	}
}

static void	draw_en_current_rect(SDL_Surface *sborder, t_v *begin, t_visu *v)
{
	if (SDL_FillRect(sborder, NULL,
				SDL_MapRGB(sborder->format, 247, 111, 172)) < 0)
	{
		SDL_FreeSurface(sborder);
		free_all_visu(begin, v, "SDL_FillRect failed");
	}
}

void		draw_rect(int i, int j, t_visu *v, t_v *begin)
{
	SDL_Rect	border;
	SDL_Surface	*sborder;

	border.x = v->startx + 1 + j * v->square + j;
	border.y = v->starty + 1 + i * v->square + i;
	border.h = v->square;
	border.w = v->square;
	if ((sborder = SDL_CreateRGBSurface(0, border.w, border.h,
					32, 0, 0, 0, 0)) == NULL)
		free_all_visu(begin, v, "Create RGB Surface failed");
	if (begin->tab[i][j] == 'O')
		draw_my_rect(sborder, begin, v);
	else if (begin->tab[i][j] == 'o')
		draw_my_current_rect(sborder, begin, v);
	else if (begin->tab[i][j] == 'X')
		draw_en_rect(sborder, begin, v);
	else if (begin->tab[i][j] == 'x')
		draw_en_current_rect(sborder, begin, v);
	if (SDL_BlitSurface(sborder, NULL, v->surf, &border) < 0)
	{
		SDL_FreeSurface(sborder);
		free_all_visu(begin, v, "SDL_BlitSurface failed");
	}
	SDL_FreeSurface(sborder);
}
