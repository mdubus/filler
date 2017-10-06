/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:38:31 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 17:56:57 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_piece_dimensions(char **tab, t_filler *f)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i != 3)
	{
		ft_free_tab_char(&tab);
		free_maps(f);
		return (1);
	}
	f->h_piece = ft_atoi(tab[1]);
	f->w_piece = ft_atoi(tab[2]);
	if (f->h_piece <= 0 || f->w_piece <= 0)
	{
		ft_free_tab_char(&tab);
		free_maps(f);
		return (1);
	}
	return (0);
}

static int	get_w_h_piece(t_filler *f)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(f->line, ' ');
	free(f->line);
	if (!tab)
	{
		free_maps(f);
		return (1);
	}
	if (ft_strcmp("Piece", tab[0]) != 0)
	{
		ft_free_tab_char(&tab);
		free_maps(f);
		return (1);
	}
	if (get_piece_dimensions(tab, f) == 1)
		return (1);
	ft_free_tab_char(&tab);
	return (0);
}

int			get_piece(t_filler *f)
{
	int		ret;

	ret = -1;
	if ((ret = get_next_line_backslash(STDIN_FILENO, &f->line)) != 1)
	{
		if (ret == 0)
			free(f->line);
		if (free_maps(f) == 1)
			return (1);
	}
	if (ft_nb_occur_char_in_str(f->line, " ") != 2)
	{
		free(f->line);
		if (free_maps(f) == 1)
			return (1);
	}
	if (get_w_h_piece(f) == 1)
		return (1);
	return (0);
}
