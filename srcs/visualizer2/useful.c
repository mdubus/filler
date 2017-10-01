/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:32:51 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/01 15:33:21 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	put_on_screen_sdl(t_visu *v, SDL_Surface *texte, int x, int y)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(texte, NULL, v->surf, &rect);
	SDL_FreeSurface(texte);
}

SDL_Color	init_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = (Uint8)r;
	color.g = (Uint8)g;
	color.b = (Uint8)b;
	color.a = (Uint8)a;
	return (color);
}
