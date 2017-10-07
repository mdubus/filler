/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:25:26 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/07 10:37:37 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	free_board_infos(t_v **t, t_visu *v, char *line)
{
	free(v->p1);
	free(v->p2);
	free(line);
	free(*t);
	ft_putstr_fd("Board problem\n", STDERR_FILENO);
	exit(1);
}

static void	parse_board_line(char *line, t_visu *v, t_v **t, char ***tab)
{
	int	i;

	i = 0;
	if (ft_strstr(line, "Plateau") == 0)
		free_board_infos(t, v, line);
	if (ft_nb_occur_char_in_str(line, " ") != 2)
		free_board_infos(t, v, line);
	*tab = ft_strsplit(line, ' ');
	while ((*tab)[i] != NULL)
		i++;
	if (i != 3)
		free_board_infos(t, v, line);
	if (!*tab)
		free_board_infos(t, v, line);
	v->nb_y = ft_atoi((*tab)[1]);
	v->nb_x = ft_atoi((*tab)[2]);
	if (v->nb_y <= 0 || v->nb_x <= 0)
	{
		ft_free_tab_char(tab);
		free_board_infos(t, v, line);
	}
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
	parse_board_line(line, v, t, &tab);
	free(line);
	ft_free_tab_char(&tab);
	get_next_line_backslash(STDIN_FILENO, &line);
	free(line);
}
