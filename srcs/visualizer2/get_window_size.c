/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:39:29 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/01 14:46:22 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	set_params_rects(t_visu *v, int width_w, int width_r, char **tab)
{
	v->width_w = width_w;
	if (width_w == 800)
		v->height_w = width_w + 100;
	else if (width_w == 1000)
		v->height_w = width_w + 50;
	else if (width_w == 1200)
		v->height_w = width_w;
	v->nb_x = ft_atoi(tab[2]);
	v->nb_y = ft_atoi(tab[1]);
	if (v->nb_x > v->nb_y)
		width_r = (width_w - 200 - v->nb_x) / v->nb_x;
	else
		width_r = (width_w - 350 - v->nb_y) / v->nb_y;
	v->rect.w = width_r;
	v->rect.h = width_r;
}

void	get_window_size(t_visu *v)
{
	char	*line;
	char	**tab;

	tab = NULL;
	line = NULL;

	get_next_line_backslash(STDIN_FILENO, &line);
	tab = ft_strsplit(line, ' ');
	free(line);
	if (ft_strstr(tab[0], "Plateau") == 0)
		exit(1);
	if (ft_atoi(tab[1]) <= 20 && ft_atoi(tab[2]) <= 20)
		set_params_rects(v, 800, 25, tab);
	else if (ft_atoi(tab[1]) <= 50 && ft_atoi(tab[2]) <= 50)
		set_params_rects(v, 1000, 15, tab);
	else if (ft_atoi(tab[1]) <= 100 && ft_atoi(tab[2]) <= 100)
		set_params_rects(v, 1200, 6, tab);
	else
	{
		ft_free_tab_char(&tab);
		exit(1);
	}
	ft_free_tab_char(&tab);
}

