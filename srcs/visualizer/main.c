/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/01 19:20:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
/*
   char		**tab;
   int			current_player;
   struct s_v	*next;
   struct s_v	*prev;
   */

void free_board_infos(t_v **t, t_visu *v, char *line)__attribute__((noreturn));
void free_board_infos(t_v **t, t_visu *v, char *line)
{
	free(v->p1);
	free(v->p2);
	free(line);
	free(t);
	ft_putstr_fd("Board problem\n", STDERR_FILENO);
	exit (1);
}

void	get_board_infos(t_v **t, t_visu *v);
void	get_board_infos(t_v **t, t_visu *v)
{
	char	**tab;
	char	*line;
	int		ret;

	tab = NULL;
	line = NULL;
	ret = -1;
	t = malloc(sizeof(t));
	if (v->line != NULL)
		line = v->line;
	else
	{
		ret = get_next_line_backslash(STDIN_FILENO, &line);
		if (ret != 1)
			free_board_infos(t, v, line);
	}
	if (ft_strstr(line, "Plateau") == 0)
		free_board_infos(t, v, line);
	tab = ft_strsplit(line, ' ');
	v->nb_y = ft_atoi(tab[1]);
	v->nb_x = ft_atoi(tab[2]);
	free(line);
	ft_free_tab_char(&tab);
	get_next_line_backslash(STDIN_FILENO, &line);
	free(line);
}

void	stock_first_link(t_visu *v, t_v **t);
void	stock_first_link(t_visu *v, t_v **t)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < v->nb_y)
	{
		get_next_line_backslash(STDIN_FILENO, &line);
		ft_putstr(line);
		i++;
		free(line);
	}
	(void)t;
}

int	main(void)
{
	t_visu	v;
	t_v		*t;

	init_struct_visu(&v);
	verif_header_vm();
	get_players_vm(&v);

	get_board_infos(&t, &v);
	

	stock_first_link(&v, &t);


	sleep(1);
	return (0);
}
