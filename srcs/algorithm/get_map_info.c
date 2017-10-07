/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:15:21 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/07 10:12:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	parse_line(t_filler *f, int i)
{
	if (ft_nb_occur_char_in_str(f->line, " ") != 1)
	{
		while (i > 0)
			free(f->map[--i]);
		free(f->line);
		return (1);
	}
	if (ft_strlen(f->line) != (size_t)f->w_board + 5)
	{
		while (i > 0)
			free(f->map[--i]);
		free(f->line);
		return (1);
	}
	if (f->line[3] != ' ')
	{
		while (i > 0)
			free(f->map[--i]);
		free(f->line);
		return (1);
	}
	return (0);
}

int			stock_current_map(t_filler *f)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	free(f->line);
	while (i < f->h_board)
	{
		if ((ret = get_next_line_backslash(STDIN_FILENO, &f->line)) != 1)
		{
			if (ret == 0)
				free(f->line);
			while (i > 0)
				free(f->map[--i]);
			return (1);
		}
		if (parse_line(f, i) == 1)
			return (1);
		f->map[i] = ft_strsub(f->line, 4, (size_t)f->w_board);
		i++;
		free(f->line);
	}
	f->map[i] = NULL;
	return (0);
}

static int	get_map_line(t_filler *f)
{
	int		ret;

	ret = -1;
	ret = get_next_line_backslash(STDIN_FILENO, &f->line);
	if (ret == 0)
	{
		free(f->line);
		return (1);
	}
	if (ret != 1 && ret != 0)
	{
		free(f->line);
		return (1);
	}
	return (0);
}

int			get_map_info(t_filler *f)
{
	if (get_map_line(f) == 1)
		return (1);
	f->tab = ft_strsplit(f->line, ' ');
	free(f->line);
	if (!f->tab)
		return (1);
	if (compare_return_error("Plateau", f->tab[0], f->tab) == 1)
		return (1);
	f->h_board = ft_atoi(f->tab[1]);
	f->w_board = ft_atoi(f->tab[2]);
	ft_free_tab_char(&f->tab);
	if (f->h_board <= 0 || f->w_board <= 0)
		return (1);
	f->map = (char **)malloc(sizeof(char*) * ((unsigned long)f->h_board + 1));
	if (!f->map)
		return (1);
	if (get_next_line_backslash(STDIN_FILENO, &f->line) != 1)
	{
		free(f->map);
		return (1);
	}
	return (0);
}
