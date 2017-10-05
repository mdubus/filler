/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:26:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 19:17:12 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	get_player_line(char **line)
{
	int	ret;

	ret = -1;
	if ((ret = get_next_line_backslash(STDIN_FILENO, line)) != 1)
	{
		if (ret == 0)
			free(*line);
		exit(1);
	}
	if (ft_nb_occur_char_in_str(*line, " ") != 4)
	{
		free(*line);
		exit(1);
	}
}

void		get_player_info(t_filler *f, char *line)
{
	get_player_line(&line);
	f->tab = ft_strsplit(line, ' ');
	free(line);
	compare_return_error("$$$", f->tab[0], f->tab);
	compare_return_error("exec", f->tab[1], f->tab);
	compare_return_error(":", f->tab[3], f->tab);
	compare_return_error("[./mdubus.filler]\n", f->tab[4], f->tab);
	if (ft_strcmp(f->tab[2], "p1") == 0)
	{
		f->letter_me = 'O';
		f->letter_ennemy = 'X';
	}
	else if (ft_strcmp(f->tab[2], "p2") == 0)
	{
		f->letter_me = 'X';
		f->letter_ennemy = 'O';
	}
	else
	{
		ft_free_tab_char(&f->tab);
		exit(1);
	}
	ft_free_tab_char(&f->tab);
}
