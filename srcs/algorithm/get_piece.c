/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:38:31 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/28 14:20:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_piece(t_filler *f)
{
	char	**tab;

	tab = NULL;
	if (get_next_line_backslash(STDIN_FILENO, &f->line) != 1)
		ft_print_error_fd_exit(ft_putstr_fd, "Error 8", f->ttys);
	if (ft_nb_occur_char_in_str(f->line, " ") != 2)
		ft_print_error_fd_exit(ft_putstr_fd, "Error 9", f->ttys);
	tab = ft_strsplit(f->line, ' ');
	free(f->line);
	compare_return_error("Piece", tab[0], f->ttys);
	f->h_piece = ft_atoi(tab[1]);
	f->w_piece = ft_atoi(tab[2]);
	ft_free_tab_char(&tab);
}
