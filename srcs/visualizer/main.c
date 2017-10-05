/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 20:23:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#pragma GCC diagnostic error "-Weverything"

void	put_on_screen_sdl(t_visu *v, SDL_Surface *surface, int x, int y)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	if (SDL_BlitSurface(surface, NULL, v->surf, &rect) < 0)
	{
		SDL_FreeSurface(surface);
		ft_putstr("Error on TTF_RenderText_Blended : ");
		free_all_visu(v->begin, v, SDL_GetError());
	}
	SDL_FreeSurface(surface);
}

void	put_background(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;

	write_filler(&temp, v, begin);
	write_p1(&temp, v, begin);
	write_p2(&temp, v, begin);
	put_grid_vertic(v, begin);
	put_grid_horiz(v, begin);
}

void	check_for_piece(t_v *begin, t_visu *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (begin->tab[i] != NULL)
	{
		j = 0;
		while (j < v->nb_x)
		{
			if (begin->tab[i][j] != '.')
				draw_rect(i, j, v, begin);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_visu	v;
	t_v		*t;//free ?
	t_v		*begin;//free ?

	init_struct_visu(&v);
	verif_header_vm();
	get_players_vm(&v);
	get_board_infos(&t, &v);
	begin = t;
	stock_links(&v, &t, begin);
	v.begin = begin;
	get_screen_dimensions(&v, begin);
	init_sdl(&v, begin);
	put_background(&v, begin);
	check_for_piece(begin, &v);
	SDL_UpdateWindowSurface(v.window);
	event_loop(&v, &begin);
	case_loop_false(&v);
	return (0);
}
