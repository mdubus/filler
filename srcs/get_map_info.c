/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:15:21 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/21 18:24:38 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	stock_current_map(t_filler *f)
{
	int i;
	
	i = 0;
	while (i < f->h_board)
	{
		if (get_next_line_backslash(STDIN_FILENO, &f->line) != 1)
			ft_print_error_fd_exit(ft_putstr_fd, "Error 3", f->ttys);
		if (ft_nb_occur_char_in_str(f->line, " ") != 1)
			ft_print_error_fd_exit(ft_putstr_fd, "Error 4", f->ttys);
		if (ft_strlen(f->line) != (size_t )f->w_board + 5)
			ft_print_error_fd_exit(ft_putstr_fd, "Error 5", f->ttys);
		f->map[i] = ft_strsub(f->line, 4, (size_t)f->w_board);
		i++;
	}
	f->map[i] = NULL;
}

void	get_map_info(t_filler *f)
{
	char	**tab;
	int		ret;

	tab = NULL;
	ret = -1;
	ret = get_next_line_backslash(STDIN_FILENO, &f->line);
	if (ret == 0)
		exit(0);
	if (ret != 1 && ret != 0)
		ft_print_error_fd_exit(ft_putstr_fd, "Error 1", f->ttys);
	tab = ft_strsplit(f->line, ' ');
	compare_return_error("Plateau", tab[0], f->ttys);
	f->h_board = ft_atoi(tab[1]);
	f->w_board = ft_atoi(tab[2]);
	f->map = (char **)malloc(sizeof(char*) * ((unsigned long)f->h_board + 1));
	if (get_next_line_backslash(STDIN_FILENO, &f->line) != 1)
		ft_print_error_fd_exit(ft_putstr_fd, "Error 2", f->ttys);
}
