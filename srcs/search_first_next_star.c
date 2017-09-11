/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_first_next_star.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:20:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/11 19:21:23 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	search_first_star(t_filler *f)
{
	f->i = 0;
	f->j = 0;
	while (f->j < f->h_piece && f->piece[f->j][f->i] != '*')
	{
		while (f->i < f->w_piece && f->piece[f->j][f->i] != '*')
		{
			f->i++;
		}
		if (f->piece[f->j][f->i] != '*')
		{
			f->i = 0;
			f->j++;
		}
	}
}

void	search_next_star(t_filler *f, int *i, int *j)
{
	if (*i + 1 < f->w_piece)
		(*i)++;
	else if (*j + 1 < f->h_piece)
	{
		*i = 0;
		(*j)++;
	}
	if (*j < f->h_piece && *i < f->w_piece)
	{
		while (*j < f->h_piece && f->piece[*j][*i] != '*')
		{
			while (*i < f->w_piece && f->piece[*j][*i] != '*')
			{
				(*i)++;
			}
			if (f->piece[*j][*i] != '*')
			{
				*i = 0;
				(*j)++;
			}
		}
	}
}
