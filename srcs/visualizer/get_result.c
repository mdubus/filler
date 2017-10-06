/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:15:33 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 21:23:13 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	parse_result_line(t_visu **v, t_v *begin, char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i != 4)
		free_everything(*v, begin);
	if (ft_strcmp(tab[0], "==") != 0)
		free_everything(*v, begin);
}

void		get_results(char **line, t_visu **v, t_v *begin)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(*line, ' ');
	free(*line);
	if (!tab)
		free_everything(*v, begin);
	parse_result_line(v, begin, tab);
	if (ft_strstr(tab[1], "O") != 0)
		(*v)->resultp1 = ft_atoi(tab[3]);
	else
		(*v)->resultp2 = ft_atoi(tab[3]);
	ft_free_tab_char(&tab);
	if (ft_strstr((*v)->p2, "aucun") == 0)
	{
		if (get_next_line_backslash(STDIN_FILENO, line) != 1)
			free_linked_list(*v, *line, begin);
		tab = ft_strsplit(*line, ' ');
		if (ft_strstr(tab[1], "X") != 0)
			(*v)->resultp2 = ft_atoi(tab[3]);
		else
			(*v)->resultp1 = ft_atoi(tab[3]);
		free(*line);
		ft_free_tab_char(&tab);
	}
}
