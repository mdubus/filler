/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 18:11:50 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

int		main(void)
{
	t_visu	v;
	t_v		*t;
	t_v		*begin;

	init_struct_visu(&v);
	verif_header_vm();
	get_players_vm(&v);
	get_board_infos(&t, &v);
	begin = t;
	stock_links(&v, &t, begin);
	v.begin = begin;
	get_screen_dimensions(&v, begin);
	init_sdl(&v, begin);
	put_background(&v, begin);
	check_for_piece(begin, &v);
	SDL_UpdateWindowSurface(v.window);
	event_loop(&v, &begin);
	case_loop_false(&v);
	return (0);
}
