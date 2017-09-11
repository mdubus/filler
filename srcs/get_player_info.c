/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:26:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/09 17:45:59 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_player_info(t_filler *f, char *line)
{
	char	**tab;

	tab = NULL;
	if (get_next_line_backslash(STDIN_FILENO, &line) != 1)
		ft_print_error_fd_exit(ft_putstr_fd, "Error 6", f->ttys);
	if (ft_nb_occur_char_in_str(line, " ") != 4)
		ft_print_error_fd_exit(ft_putstr_fd, "Error 7", f->ttys);
	tab = ft_strsplit(line, ' ');
//	dprintf(f->ttys, "%s", tab[4]);
	compare_return_error("$$$", tab[0], f->ttys);
	compare_return_error("exec", tab[1], f->ttys);
	compare_return_error(":", tab[3], f->ttys);
	compare_return_error("[./mdubus.filler]\n", tab[4], f->ttys);
	if (ft_strcmp(tab[2], "p1") == 0)
	{
		f->letter_me = 'O';
		f->letter_ennemy = 'X';
	}
	else if (ft_strcmp(tab[2], "p2") == 0)
	{
		f->letter_me = 'X';
		f->letter_ennemy = 'O';
	}
	else
		ft_print_error_fd_exit(ft_putstr_fd, "Error 8", f->ttys);
	free_tab_char(&tab);
}
