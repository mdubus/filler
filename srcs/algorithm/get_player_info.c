/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:26:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/07 09:51:59 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_player_line(char **line)
{
	int	ret;

	ret = -1;
	if ((ret = get_next_line_backslash(STDIN_FILENO, line)) != 1)
	{
		if (ret == 0)
			free(*line);
		return (1);
	}
	if (ft_nb_occur_char_in_str(*line, " ") != 4)
	{
		free(*line);
		return (1);
	}
	return (0);
}

static int	parse_line_player(t_filler *f)
{
	if (compare_return_error("$$$", f->tab[0], f->tab) == 1)
		return (1);
	if (compare_return_error("exec", f->tab[1], f->tab) == 1)
		return (1);
	if (compare_return_error(":", f->tab[3], f->tab) == 1)
		return (1);
	if (compare_return_error("[./mdubus.filler]\n", f->tab[4], f->tab) == 1)
		return (1);
	return (0);
}

int			get_player_info(t_filler *f, char *line)
{
	if (get_player_line(&line) == 1)
		return (1);
	f->tab = ft_strsplit(line, ' ');
	free(line);
	if (!f->tab)
		return (1);
	if (parse_line_player(f) == 1)
		return (1);
	if (f->tab[2] && ft_strcmp(f->tab[2], "p1") == 0)
	{
		f->letter_me = 'O';
		f->letter_ennemy = 'X';
	}
	else if (f->tab[2] && ft_strcmp(f->tab[2], "p2") == 0)
	{
		f->letter_me = 'X';
		f->letter_ennemy = 'O';
	}
	else
	{
		ft_free_tab_char(&f->tab);
		return (1);
	}
	ft_free_tab_char(&f->tab);
	return (0);
}
