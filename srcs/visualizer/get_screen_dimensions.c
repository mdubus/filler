/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_dimensions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:20:28 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:44:08 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	set_dimensions(t_visu *v, int width, int height, int square)
{
	v->width_w = width;
	v->height_w = height;
	v->square = square;
}

static void	higher_than_wide(t_visu *v, t_v *begin)
{
	if (v->nb_y <= 20)
		set_dimensions(v, 200 + 200 + (v->nb_y * 25) + v->nb_y, 220 + 200 +
				(v->nb_x * 25) + v->nb_x, 25);
	else if (v->nb_y <= 50)
		set_dimensions(v, 200 + 200 + (v->nb_y * 15) + v->nb_y, 220 + 200 +
				(v->nb_x * 15) + v->nb_x, 15);
	else if (v->nb_y <= 100)
		set_dimensions(v, 200 + 200 + (v->nb_y * 6) + v->nb_y, 220 + 200 +
				(v->nb_x * 6) + v->nb_x, 6);
	else
		free_all_visu(begin, v, "Map is too big !");
}

void		get_screen_dimensions(t_visu *v, t_v *begin)
{
	if (v->nb_x >= v->nb_y)
	{
		if (v->nb_x <= 20)
			set_dimensions(v, 220 + 200 + (v->nb_x * 25) + v->nb_x, 200 + 200 +
					(v->nb_y * 25) + v->nb_y, 25);
		else if (v->nb_x <= 50)
			set_dimensions(v, 220 + 200 + (v->nb_x * 15) + v->nb_x, 200 + 200 +
					(v->nb_y * 15) + v->nb_y, 15);
		else if (v->nb_x <= 100)
			set_dimensions(v, 220 + 200 + (v->nb_x * 6) + v->nb_x, 200 + 200 +
					(v->nb_y * 6) + v->nb_y, 6);
		else
			free_all_visu(begin, v, "Map is too big !");
	}
	else
		higher_than_wide(v, begin);
}
