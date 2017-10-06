/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:55:02 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	put_result_p1(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;
	char		*resultp1;
	int			w;
	int			h;

	resultp1 = ft_strjoin("p1 = ", ft_itoa(v->resultp1));
	if (TTF_SizeText(v->police, resultp1, &w, &h) == -1)
	{
		free(resultp1);
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((temp = TTF_RenderText_Blended(v->police, resultp1, v->purple)) == NULL)
	{
		free(resultp1);
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, temp, (v->width_w / 2 - w - 100), v->height_w - 200);
	SDL_UpdateWindowSurface(v->window);
	free(resultp1);
}

void	put_result_p2(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;
	char		*resultp2;
	int			w;
	int			h;

	resultp2 = ft_strjoin("p2 = ", ft_itoa(v->resultp2));
	if (TTF_SizeText(v->police, resultp2, &w, &h) == -1)
	{
		ft_putstr("Error on TTF_SizeText : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	if ((temp = TTF_RenderText_Blended(v->police, resultp2, v->pink)) == NULL)
	{
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(begin, v, SDL_GetError());
	}
	put_on_screen_sdl(v, temp, (v->width_w / 2 + 100), v->height_w - 200);
	SDL_UpdateWindowSurface(v->window);
	free(resultp2);
}
