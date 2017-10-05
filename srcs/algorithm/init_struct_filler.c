/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_filler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:24:35 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 20:41:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_struct_filler2(t_filler *f)
{
	f->nb_max = 0;
	f->tempx = 0;
	f->tempy = 0;
	f->score = 0;
	f->i = -1;
	f->j = 0;
	f->startx = 0;
	f->starty = 0;
	f->flag_star = 0;
	f->tempj = 0;
	f->tempi = 0;
	f->is_zero = 0;
	f->score2 = 0;
	f->tempx2 = 0;
	f->tempy2 = 0;
}

void		init_struct_filler(t_filler *f)
{
	f->tab = NULL;
	f->map = NULL;
	f->hmap = NULL;
	f->piece = NULL;
	f->line = NULL;
	f->letter_me = 0;
	f->letter_ennemy = 0;
	f->x = 0;
	f->y = 0;
	f->w_board = -1;
	f->h_board = -1;
	f->w_piece = -1;
	f->h_piece = -1;
	init_struct_filler2(f);
}
