/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:39:52 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 21:26:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		free_tab(t_filler *f)
{
	int		i;

	i = 0;
	while (i < f->h_board)
		free(f->map[i++]);
	free(f->map);
}

static void	free_hmap(t_filler *f)
{
	int i;

	i = 0;
	while (i < f->h_board)
		free(f->hmap[i++]);
	free(f->hmap);
}

static void	free_piece(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->h_piece)
		free(f->piece[i++]);
	free(f->piece);
}

void		free_all(t_filler *f)
{
	free_tab(f);
	free_hmap(f);
	free_piece(f);
}

int			free_maps(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->h_board)
	{
		free(f->map[i]);
		free(f->hmap[i]);
		i++;
	}
	free(f->map);
	free(f->hmap);
	return (1);
}
