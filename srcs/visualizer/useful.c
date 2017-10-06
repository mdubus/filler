/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:24:41 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:41 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

SDL_Color	init_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = (Uint8)r;
	color.g = (Uint8)g;
	color.b = (Uint8)b;
	color.a = (Uint8)a;
	return (color);
}

void		put_error_fd(char *line, char *str)
{
	free(line);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

void		ft_compare(char *str)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line_backslash(STDIN_FILENO, &line);
	if (ret != 1 || ft_strstr(line, str) == 0)
		put_error_fd(line, "Bad version\n");
	free(line);
}

void		put_on_screen_sdl(t_visu *v, SDL_Surface *surface, int x, int y)
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

void		put_background(t_visu *v, t_v *begin)
{
	SDL_Surface	*temp;

	write_filler(&temp, v, begin);
	write_p1(&temp, v, begin);
	write_p2(&temp, v, begin);
	put_grid_vertic(v, begin);
	put_grid_horiz(v, begin);
}
