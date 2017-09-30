/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:39:29 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/30 14:40:05 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

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

