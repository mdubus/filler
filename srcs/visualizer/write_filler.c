/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:16:40 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:49 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	write_filler(SDL_Surface **temp, t_visu *v, t_v *begin)
{
	int	w;
	int	h;

	if (SDL_FillRect(v->surf, NULL,
				SDL_MapRGB(v->surf->format, 65, 51, 51)) < 0)
	{
		ft_putstr("Error on SDL_FillRect : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if (TTF_SizeText(v->title, "Filler", &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((*temp = TTF_RenderText_Blended(v->title, "Filler", v->white)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, *temp, (v->width_w / 2 - w / 2), 20);
}
