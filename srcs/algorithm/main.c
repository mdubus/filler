/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/07 10:10:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	print_coor(t_filler *f)
{
	ft_putnbr(f->tempy);
	ft_putchar(' ');
	ft_putnbr(f->tempx);
	ft_putchar('\n');
}

int			main(void)
{
	t_filler	f;

	init_struct_filler(&f);
	if (get_player_info(&f, f.line) == 1)
		return (1);
	while (1)
	{
		if (get_map_info(&f) == 1)
			return (1);
		if (stock_current_map(&f) == 1)
			return (1);
		create_heat_map(&f);
		init_heat_map(&f);
		do_heat_map(&f);
		if (get_piece(&f) == 1)
			return (1);
		if (stock_piece(&f) == 1)
			return (1);
		resolve(&f);
		print_coor(&f);
		free_all(&f);
	}
	return (0);
}
