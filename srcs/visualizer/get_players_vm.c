/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players_vm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:22:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 19:15:09 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void		get_p1_vm(char *line, t_visu **v)
{
	if (ft_strstr(line, "$$$ exec p1 : ") == 0)
		put_error_fd(line, "bad player1\n");
	get_player_name_vm(line, &(*v)->p1);
	(*v)->p1 = ft_strjoin_proper("p1 = ", 0, (*v)->p1, 1);
}

static void	parse_p2(char **line, t_visu **v)
{
	int	ret;

	ret = -1;
	if (ft_strstr(*line, "launched") == 0)
	{
		free((*v)->p1);
		free(*line);
		ft_putstr_fd("Player not launched\n", STDERR_FILENO);
		exit(1);
	}
	free(*line);
	ret = get_next_line_backslash(STDIN_FILENO, line);
	if (ret != 1)
	{
		free((*v)->p1);
		free((*v)->p2);
		free(*line);
		ft_putstr_fd("Player not launched\n", STDERR_FILENO);
		exit(1);
	}
	get_player_name_vm(*line, &(*v)->p2);
	(*v)->p2 = ft_strjoin_proper("p2 = ", 0, (*v)->p2, 1);
}

void		get_p2_vm(t_visu **v)
{
	int		ret;
	char	*line;

	ret = -1;
	line = NULL;
	ret = get_next_line_backslash(STDIN_FILENO, &line);
	if (ft_strstr(line, "Plateau") != 0)
	{
		(*v)->p2 = ft_strdup("p2 = aucun :(");
		(*v)->line = line;
	}
	else
	{
		parse_p2(&line, v);
	}
}

void		get_players_vm(t_visu *v)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = -1;
	ft_compare("launched");
	ret = get_next_line_backslash(STDIN_FILENO, &line);
	if (ret != 1)
		put_error_fd(line, "player not launched\n");
	get_p1_vm(line, &v);
	get_p2_vm(&v);
}
