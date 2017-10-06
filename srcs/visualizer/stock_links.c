/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:18:17 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 19:48:19 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	free_link(char *line, t_visu *v, t_v **t, int *i)
{
	while (*i > 0)
		free((*t)->tab[--(*i)]);
	free((*t)->tab);
	free(line);
	free(v->p1);
	free(v->p2);
	exit(1);
}

static void	stock_first_link(t_visu *v, t_v **t)
{
	char	*line;
	int		i;
	int		ret;

	line = NULL;
	i = 0;
	ret = -1;
	while (i < v->nb_y)
	{
		if ((ret = get_next_line_backslash(STDIN_FILENO, &line)) == 0 ||
				ret == -1)
			free_link(line, v, t, &i);
		if (line[3] != ' ')
			free_link(line, v, t, &i);
		if (ft_strlen(line) != (size_t)v->nb_x + 5)
			free_link(line, v, t, &i);
		(*t)->tab[i] = ft_strsub(line, 4, (size_t)v->nb_x);
		i++;
		free(line);
	}
	(*t)->tab[i] = NULL;
}

void		stock_links(t_visu *v, t_v **t, t_v *begin)
{
	int		ret;

	ret = -1;
	(*t)->tab = (char **)malloc(sizeof(char *) * (unsigned long)(v->nb_y + 1));
	if (!(*t)->tab)
	{
		free(v->p1);
		free(v->p2);
		exit(1);
	}
	stock_first_link(v, t);
	(*t)->current_player = 0;
	(*t)->next = NULL;
	(*t)->prev = NULL;
	while (v->status != 2)
	{
		if (v->status != 1)
			stock_link(&v, t, begin);
		else
			v->status = 0;
	}
}
