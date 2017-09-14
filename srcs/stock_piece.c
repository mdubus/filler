/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:39:52 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/14 21:33:09 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	stock_piece(t_filler *f)
{
	int		i;
	char	*temp;
	
	i = 0;
	temp = NULL;
	while (i < f->h_piece)
	{
		if (get_next_line_backslash(STDIN_FILENO, &f->line) != 1)
			ft_print_error_fd_exit(ft_putstr_fd, "Error 8", f->ttys);
		if (temp == NULL)
		{
			temp = ft_strdup(f->line);
			free(f->line);
		}
		else
			temp = ft_strjoin_proper(temp, 1, f->line, 1);
		i++;
	}
	f->piece = ft_strsplit(temp, '\n');
}
