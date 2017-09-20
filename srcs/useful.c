/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:21:15 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/20 11:37:22 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	compare_return_error(char *s1, char *s2, int fd)
{
	if (ft_strcmp(s1, s2) != 0)
		ft_print_error_fd_exit(ft_putstr_fd, "Error", fd);
}

void	print_map(t_filler *f)
{
	int i;

	i = 0;
	while (f->map[i] != NULL)
		dprintf(f->ttys, "%s\n", (char *)f->map[i++]);
}

void	print_heat_map(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < f->h_board)
	{
		while (x < f->w_board)
		{
			if (HEAT == EN)
				dprintf(f->ttys, "\033[31m%3d\033[0m", HEAT);
			else if (HEAT == ME)
				dprintf(f->ttys, "\033[32m%3d\033[0m", HEAT);
			else
				dprintf(f->ttys, "%3d", HEAT);
			x++;
		}
		x = 0;
		y++;
		dprintf(f->ttys, "\n");
	}
}

void	print_piece(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->h_piece)
		dprintf(f->ttys, "\n%s", f->piece[i++]);
	dprintf(f->ttys, "\n");
}
