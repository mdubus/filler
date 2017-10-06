/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_wins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:57:32 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	p1_wins(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;
	int			w;
	int			h;

	if (TTF_SizeText(v->police_big, "P1 WINS !", &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((temp = TTF_RenderText_Blended(v->police_big, "P1 WINS !",
					v->purple)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, temp, (v->width_w / 2 - w / 2), v->height_w - 120);
}

static void	p2_wins(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;
	int			w;
	int			h;

	if (TTF_SizeText(v->police_big, "P2 WINS !", &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((temp = TTF_RenderText_Blended(v->police_big, "P2 WINS !",
					v->pink)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, temp, (v->width_w / 2 - w / 2), v->height_w - 120);
}

static void	equality(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;
	int			w;
	int			h;

	if (TTF_SizeText(v->police_big, "Equality !", &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((temp = TTF_RenderText_Blended(v->police_big, "Equality !",
					v->white)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, temp, (v->width_w / 2 - w / 2), v->height_w - 120);
}

void		draw_result(t_v **begin, t_visu *v)
{
	v->first_time = 1;
	put_result_p1(v, *begin);
	put_result_p2(v, *begin);
	if (v->resultp1 > v->resultp2)
		p1_wins(v, *begin);
	else if (v->resultp1 < v->resultp2)
		p2_wins(v, *begin);
	else
		equality(v, *begin);
	SDL_UpdateWindowSurface(v->window);
}
