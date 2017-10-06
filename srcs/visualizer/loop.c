/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:20:05 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:17 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	draw_prev(t_v **begin, t_visu *v)
{
	if ((*begin)->prev != NULL)
	{
		v->first_time = 0;
		*begin = (*begin)->prev;
		put_background(v, *begin);
		check_for_piece(*begin, v);
		SDL_UpdateWindowSurface(v->window);
	}
}

static void	draw_next(t_v **begin, t_visu *v)
{
	if ((*begin)->next != NULL)
	{
		*begin = (*begin)->next;
		put_background(v, *begin);
		check_for_piece(*begin, v);
		SDL_UpdateWindowSurface(v->window);
	}
}

void		event_loop(t_visu *v, t_v **begin)
{
	while (v->loop)
	{
		while (SDL_PollEvent(&(v->event)))
		{
			if (v->event.type == SDL_QUIT)
				v->loop = false;
			else if (v->event.type == SDL_KEYDOWN)
			{
				if (v->event.key.keysym.sym == LEFT)
					draw_prev(begin, v);
				else if (v->event.key.keysym.sym == RIGHT)
				{
					draw_next(begin, v);
					if ((*begin)->next == NULL && v->first_time == 0)
						draw_result(begin, v);
				}
				else if (v->event.key.keysym.sym == CLOSE)
					v->loop = false;
			}
		}
	}
}

void		case_loop_false(t_visu *v)
{
	if (v->loop == false)
	{
		free_everything(v, v->begin);
		TTF_CloseFont(v->police);
		TTF_CloseFont(v->police_big);
		TTF_CloseFont(v->title);
		SDL_DestroyWindow(v->window);
		SDL_Quit();
	}
}
