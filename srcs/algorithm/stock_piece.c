/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:39:52 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 20:54:00 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	stock_line(t_filler *f, int i, char *temp)
{
	int	ret;

	ret = -1;
	if ((ret = get_next_line_backslash(STDIN_FILENO, &f->line)) != 1)
	{
		if (ret == 0)
			free(f->line);
		if (i > 0)
			free(temp);
		free_maps(f);
	}
}

void		stock_piece(t_filler *f)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (i < f->h_piece)
	{
		stock_line(f, i, temp);
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
	free(temp);
}
