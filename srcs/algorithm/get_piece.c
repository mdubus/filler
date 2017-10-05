/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:38:31 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 20:30:29 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	get_w_h_piece(t_filler *f)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(f->line, ' ');
	free(f->line);
	if (ft_strcmp("Piece", tab[0]) != 0)
	{
		free_maps(f);
		ft_free_tab_char(&tab);
		exit(1);
	}
	f->h_piece = ft_atoi(tab[1]);
	f->w_piece = ft_atoi(tab[2]);
	ft_free_tab_char(&tab);
}

void		get_piece(t_filler *f)
{
	int		ret;

	ret = -1;
	if ((ret = get_next_line_backslash(STDIN_FILENO, &f->line)) != 1)
	{
		if (ret == 0)
			free(f->line);
		free_maps(f);
	}
	if (ft_nb_occur_char_in_str(f->line, " ") != 2)
	{
		free(f->line);
		free_maps(f);
	}
	get_w_h_piece(f);
}
