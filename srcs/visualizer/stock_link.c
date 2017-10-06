/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:11:24 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 20:11:19 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	pass_piece(char **line, t_visu *v, t_v *begin)
{
	char	**tab;
	int		i;
	int		nb_y;

	nb_y = 0;
	tab = ft_strsplit(*line, ' ');
	if (!tab)
		free_linked_list(v, *line, begin);
	i = 0;
	if (tab[1])
		nb_y = ft_atoi(tab[1]);
	else
		free_linked_list(v, *line, begin);
	while (i <= nb_y)
	{
		free(*line);
		if (get_next_line_backslash(STDIN_FILENO, &(*line)) != 1)
			free_linked_list(v, *line, begin);
		i++;
	}
	ft_free_tab_char(&tab);
}

static void	check_status(char **line, t_visu **v, t_v *begin,
		int *current_player)
{
	if (ft_strstr(*line, "Piece") != 0)
	{
		pass_piece(line, *v, begin);
		*current_player = (ft_strstr(*line, "O") != 0) ? 1 : 2;
		free(*line);
		if (get_next_line_backslash(STDIN_FILENO, &(*line)) != 1)
			free_linked_list(*v, *line, begin);
		(*v)->status = 1;
	}
	if (ft_strstr(*line, "fin") != 0)
	{
		get_results(line, v, begin);
		(*v)->status = 2;
	}
	else if (ft_strstr(*line, "Plateau") != 0)
		(*v)->status = 0;
	if ((*v)->status != 2)
	{
		free(*line);
		if (get_next_line_backslash(STDIN_FILENO, line) != 1)
			free_linked_list(*v, *line, begin);
		free(*line);
	}
}

static void	stock_map(t_v **t, t_visu *v, int current_player, t_v *begin)
{
	int		i;

	i = 0;
	(*t)->tab = (char **)malloc(sizeof(char *) * (unsigned long)(v->nb_y + 1));
	if (!(*t))
		free_everything(v, begin);
	while (i < v->nb_y)
		parse_line_stock_map(v, begin, t, &i);
	(*t)->tab[i] = NULL;
	(*t)->current_player = current_player;
}

static void	parse_map(t_visu *v, char **line, t_v *begin, int *current_player)
{
	if (get_next_line_backslash(STDIN_FILENO, line) != 1)
		free_linked_list(v, *line, begin);
	if (ft_strstr(*line, "Piece") == 0)
		free_linked_list(v, *line, begin);
	pass_piece(line, v, begin);
	if (ft_strstr(*line, "error on input") != 0)
	{
		free(*line);
		if (get_next_line_backslash(STDIN_FILENO, line) != 1)
			free_linked_list(v, *line, begin);
		if (ft_strstr(*line, "Piece") == 0)
			free_linked_list(v, *line, begin);
		pass_piece(line, v, begin);
	}
	if (ft_strstr(*line, "got") == 0)
		free_linked_list(v, *line, begin);
	if (ft_strstr(*line, "O") != 0)
		*current_player = 1;
	else if (ft_strstr(*line, "X") != 0)
		*current_player = 2;
	else
		*current_player = 0;
	free(*line);
}

void		stock_link(t_visu **v, t_v **t, t_v *begin)
{
	char	*line;
	int		ret;
	int		current_player;

	line = NULL;
	ret = -1;
	current_player = 0;
	parse_map(*v, &line, begin, &current_player);
	if (get_next_line_backslash(STDIN_FILENO, &line) != 1)
		free_linked_list(*v, line, begin);
	check_status(&line, v, begin, &current_player);
	if ((*v)->status != 2)
	{
		(*t)->next = (t_v*)malloc(sizeof(**t));
		(*t)->next->prev = *t;
		*t = (*t)->next;
		(*t)->next = NULL;
		stock_map(t, *v, current_player, begin);
	}
}
