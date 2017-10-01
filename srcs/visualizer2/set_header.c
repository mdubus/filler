/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:33:03 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/30 14:37:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	set_header(t_visu *v)
{
	int	w;
	int	h;

	v->surf = SDL_GetWindowSurface(v->window);
	SDL_FillRect(v->surf, NULL, SDL_MapRGB(v->surf->format, 65, 51, 51));

	TTF_SizeText(v->title, "Filler", &w, &h);
	put_on_screen_sdl(v, TTF_RenderText_Blended(v->title, "Filler", v->white),
			(v->width_w / 2 - w / 2), 20);

	TTF_SizeText(v->police, v->p1, &w, &h);
	put_on_screen_sdl(v, TTF_RenderText_Blended(v->police, v->p1, v->purple),
			(v->width_w / 2 - w - 100), 100);

	put_on_screen_sdl(v, TTF_RenderText_Blended(v->police, v->p2, v->pink),
			(v->width_w / 2 + 100), 100);
}
