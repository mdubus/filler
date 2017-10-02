/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:23:41 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/02 16:23:03 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	verif_header_vm(void)
{
	ft_compare("# -------------- VM  version 1.1 ------------- #");
	ft_compare("#                                              #");
	ft_compare("# 42 / filler VM Developped by: Hcao - Abanlin #");
	ft_compare("#                                              #");
	ft_compare("# -------------------------------------------- #");
}

void	init_struct_visu(t_visu *v)
{
	v->p1 = NULL;
	v->p2 = NULL;
	v->line = NULL;
	v->nb_x = 0;
	v->nb_y = 0;
	v->status = -1;
}
