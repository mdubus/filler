/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:25:26 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/03 15:22:09 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#pragma GCC diagnostic error "-Weverything"

static void free_board_infos(t_v **t, t_visu *v, char *line)__attribute__((noreturn));
static void	free_board_infos(t_v **t, t_visu *v, char *line)
{
	free(v->p1);
	free(v->p2);
	free(line);
	free(*t);
	ft_putstr_fd("Board problem\n", STDERR_FILENO);
	exit(1);
}

void		get_board_infos(t_v **t, t_visu *v)
{
	char	**tab;
	char	*line;
	int		ret;

	tab = NULL;
	line = NULL;
	ret = -1;
	*t = (t_v*)malloc(sizeof(**t));
	if (v->line != NULL)
		line = v->line;
	else
	{
		ret = get_next_line_backslash(STDIN_FILENO, &line);
		if (ret != 1)
			free_board_infos(t, v, line);
	}
	if (ft_strstr(line, "Plateau") == 0)
		free_board_infos(t, v, line);
	tab = ft_strsplit(line, ' ');
	v->nb_y = ft_atoi(tab[1]);
	v->nb_x = ft_atoi(tab[2]);
	free(line);
	ft_free_tab_char(&tab);
	get_next_line_backslash(STDIN_FILENO, &line);
	free(line);
}
