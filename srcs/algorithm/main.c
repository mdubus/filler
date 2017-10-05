/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:39:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 19:01:43 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_filler	f;

	init_struct_filler(&f);
	get_player_info(&f, f.line);
	while (1)
	{
		get_map_info(&f);
		stock_current_map(&f);
		create_heat_map(&f);
		init_heat_map(&f);
		do_heat_map(&f);
		get_piece(&f);
		stock_piece(&f);
		resolve(&f);
		ft_putnbr(f.tempy);
		ft_putchar(' ');
		ft_putnbr(f.tempx);
		ft_putchar('\n');
		free_all(&f);
	}
	return (0);
}
