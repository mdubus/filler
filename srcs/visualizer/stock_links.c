/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:18:17 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 11:33:21 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#pragma GCC diagnostic error "-Weverything"

void	stock_links(t_visu *v, t_v **t, t_v *begin)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	(*t)->tab = (char **)malloc(sizeof(char *) * (unsigned long)(v->nb_y + 1));
	while (i < v->nb_y)
	{
		get_next_line_backslash(STDIN_FILENO, &line);
		(*t)->tab[i] = ft_strsub(line, 4, (size_t)v->nb_x);
		i++;
		free(line);
	}
	(*t)->tab[i] = NULL;
	(*t)->current_player = 0;
	(*t)->next = NULL;
	(*t)->prev = NULL;
	while (v->status != 2)
	{
//	ft_putendl("ENTER HERE");
//		ft_printf("%d", v->status);
		if (v->status != 1)
		{
	//		printf(" STOCK LINK !\n");
			stock_link(&v, t, begin);
		}
		else
		{
	//		ft_putendl("TEST");
			v->status = 0;
		}
	}
//	ft_putendl("COUCOU");
}
