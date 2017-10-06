/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_stock_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:10:34 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 20:11:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void		parse_line_stock_map(t_visu *v, t_v *begin, t_v **t, int *i)
{
	char	*line;

	line = NULL;
	if (get_next_line_backslash(STDIN_FILENO, &line) != 1)
	{
		free_linked_list(v, line, begin);
		while (*i > 0)
			free((*t)->tab[--(*i)]);
	}
	if (line[3] != ' ')
	{
		free_linked_list(v, line, begin);
		while (*i > 0)
			free((*t)->tab[--(*i)]);
	}
	if (ft_strlen(line) != (size_t)v->nb_x + 5)
	{
		free_linked_list(v, line, begin);
		while (*i > 0)
			free((*t)->tab[--(*i)]);
	}
	(*t)->tab[*i] = ft_strsub(line, 4, (size_t)v->nb_x);
	(*i)++;
	free(line);
}
