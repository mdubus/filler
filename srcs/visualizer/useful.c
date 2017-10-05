/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:24:41 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/05 14:53:33 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
#pragma GCC diagnostic error "-Weverything"

SDL_Color	init_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.r = (Uint8)r;
	color.g = (Uint8)g;
	color.b = (Uint8)b;
	color.a = (Uint8)a;
	return (color);
}

void	put_error_fd(char *line, char *str)
{
	free(line);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

void	ft_compare(char *str)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line_backslash(STDIN_FILENO, &line);
	if (ret != 1 || ft_strstr(line, str) == 0)
		put_error_fd(line, "Bad version\n");
	free(line);
}


