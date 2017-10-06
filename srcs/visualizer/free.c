/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:53:08 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 12:05:09 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	free_linked_list(t_visu *v, char *line, t_v *begin)
{
	int		i;
	char	c;

	c = 0;
	free(v->p1);
	free(v->p2);
	free(line);
	while (begin->next != NULL)
	{
		i = 0;
		while (begin->tab[i] != NULL)
			free(begin->tab[i++]);
		begin = begin->next;
		if (begin->prev)
			free(begin->prev);
	}
	i = 0;
	while (begin->tab[i] != NULL)
		free(begin->tab[i++]);
	free(begin);
	exit(1);
}

void	free_all_visu(t_v *begin, t_visu *v, const char *s)
{
	int	i;

	i = 0;
	free(v->p1);
	free(v->p2);
	while (begin->next != NULL)
	{
		i = 0;
		while (begin->tab[i] != NULL)
			free(begin->tab[i++]);
		begin = begin->next;
		if (begin->prev)
			free(begin->prev);
	}
	i = 0;
	while (begin->tab[i] != NULL)
		free(begin->tab[i++]);
	free(begin);
	ft_putendl(s);
	exit(1);
}

void	free_everything(t_visu *v, t_v *begin)
{
	int		i;
	char	c;

	c = 0;
	free(v->p1);
	free(v->p2);
	while (begin->next != NULL)
	{
		i = 0;
		while (begin->tab[i] != NULL)
			free(begin->tab[i++]);
		begin = begin->next;
		if (begin->prev)
			free(begin->prev);
	}
	i = 0;
	while (begin->tab[i] != NULL)
		free(begin->tab[i++]);
	free(begin);
	exit(1);
}
