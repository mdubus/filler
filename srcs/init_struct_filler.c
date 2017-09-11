/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_filler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:24:35 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/11 16:30:36 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_struct_filler(t_filler *f)
{
	f->tab = NULL;
	f->map = NULL;
	f->hmap = NULL;
	f->piece = NULL;
	f->line = NULL;
	f->player_name = NULL;
	f->letter_me = 0;
	f->letter_ennemy = 0;
	f->x_ennemy = 0;
	f->y_ennemy = 0;
	f->x_me = 0;
	f->y_me = 0;
	f->ret = -1;
	f->ttys = open("/dev/ttys001", O_RDWR);
	f->w_board = -1;
	f->h_board = -1;
	f->w_piece = -1;
	f->h_piece = -1;
	f->nb_max = 0;
	f->x_distance = 0;
	f->y_distance = 0;
	f->heat_min = 0;
	f->tempx = 0;
	f->tempy = 0;
	f->score = 0;
}
