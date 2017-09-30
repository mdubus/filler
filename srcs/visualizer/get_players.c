/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:43:35 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/30 12:50:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	get_player_name(char *line, char **player)
{
	char	**tab;
	char	**tab2;
	int		i;
	int		j;
	if (ft_strstr(line, "bad player") != 0)
		exit(1);
	tab = NULL;
	tab2 = NULL;
	i = 0;
	j = 0;
	tab = ft_strsplit(line, '/');
	while (ft_strstr(tab[i], ".filler") == 0)
		i++;
	tab2 = ft_strsplit(tab[i], '.');
	while (ft_strstr(tab2[j], "filler") == 0)
		j++;
	*player = ft_strdup(tab2[j - 1]);
	ft_free_tab_char(&tab);
	ft_free_tab_char(&tab2);
	free(line);
}

void	get_players(t_visu *v)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;

	i = 6;
	j = 0;
	while (i-- > 0)
	{
		get_next_line_backslash(STDIN_FILENO, &line);
		if (ft_strstr("error:", line) != 0)
			exit(1);
		free(line);
	}
	get_next_line_backslash(STDIN_FILENO, &line);
	get_player_name(line, &v->p1);
	v->p1 = ft_strjoin_proper("p1 = ", 0, v->p1, 1);

	get_next_line_backslash(STDIN_FILENO, &line);
	get_next_line_backslash(STDIN_FILENO, &line);
	if (ft_strstr(line, "exec p2") == 0)
		exit(1);
	get_player_name(line, &v->p2);
	v->p2 = ft_strjoin_proper("p2 = ", 0, v->p2, 1);
}
