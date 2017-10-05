/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:15:21 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 20:43:03 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	parse_line(t_filler *f, int i)
{
	if (ft_nb_occur_char_in_str(f->line, " ") != 1)
	{
		while (i > 0)
			free(f->map[i--]);
		free(f->line);
		exit(1);
	}
	if (ft_strlen(f->line) != (size_t)f->w_board + 5)
	{
		while (i > 0)
			free(f->map[i--]);
		free(f->line);
		exit(1);
	}
}

void		stock_current_map(t_filler *f)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	while (i < f->h_board)
	{
		if ((ret = get_next_line_backslash(STDIN_FILENO, &f->line)) != 1)
		{
			if (ret == 0)
				free(f->line);
			while (i > 0)
				free(f->map[i--]);
			exit(1);
		}
		parse_line(f, i);
		f->map[i] = ft_strsub(f->line, 4, (size_t)f->w_board);
		i++;
		free(f->line);
	}
	f->map[i] = NULL;
}

static void	get_map_line(t_filler *f)
{
	int		ret;

	ret = -1;
	ret = get_next_line_backslash(STDIN_FILENO, &f->line);
	if (ret == 0)
	{
		free(f->line);
		exit(0);
	}
	if (ret != 1 && ret != 0)
	{
		free(f->line);
		exit(1);
	}
}

void		get_map_info(t_filler *f)
{
	get_map_line(f);
	f->tab = ft_strsplit(f->line, ' ');
	free(f->line);
	compare_return_error("Plateau", f->tab[0], f->tab);
	f->h_board = ft_atoi(f->tab[1]);
	f->w_board = ft_atoi(f->tab[2]);
	f->map = (char **)malloc(sizeof(char*) * ((unsigned long)f->h_board + 1));
	if (get_next_line_backslash(STDIN_FILENO, &f->line) != 1)
	{
		free(f->line);
		ft_free_tab_char(&f->tab);
		exit(1);
	}
	free(f->line);
	ft_free_tab_char(&f->tab);
}
