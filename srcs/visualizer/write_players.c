/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:11:46 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:53 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	write_p1(SDL_Surface **temp, t_visu *v, t_v *begin)
{
	int	w;
	int	h;

	if (TTF_SizeText(v->police, v->p1, &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((*temp = TTF_RenderText_Blended(v->police, v->p1, v->purple)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, *temp, (v->width_w / 2 - w - 100), 100);
}

void	write_p2(SDL_Surface **temp, t_visu *v, t_v *begin)
{
	int	w;
	int	h;

	if (TTF_SizeText(v->police, v->p2, &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((*temp = TTF_RenderText_Blended(v->police, v->p2, v->pink)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, *temp, (v->width_w / 2 + 100), 100);
}
