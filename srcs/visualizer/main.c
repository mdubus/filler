/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/02 18:12:15 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"
/*
   char		**tab;
   int			current_player;
   struct s_v	*next;
   struct s_v	*prev;
   */

void	stock_first_link(t_visu *v, t_v **t);
void	stock_first_link(t_visu *v, t_v **t)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	(*t)->tab = (char **)malloc(sizeof (char *) * (unsigned long)(v->nb_y + 1));
	while (i < v->nb_y)
	{
		get_next_line_backslash(STDIN_FILENO, &line);
		(*t)->tab[i] = ft_strsub(line, 4, (size_t)v->nb_x);
//		ft_putendl((*t)->tab[i]);
		i++;
		free(line);
	}
	(*t)->tab[i] = NULL;
	(*t)->current_player = 0;
	(*t)->next  = NULL;
	(*t)->prev = NULL;
}

void	free_linked_list(t_visu *v, char *line, t_v *begin)__attribute__((noreturn));
void	free_linked_list(t_visu *v, char *line, t_v *begin)
{
	int	i;
	char	c;

	c = 0;
	free(v->p1);
	free(v->p2);
	free(line);
	while (begin->next != NULL)
	{
		i = 0;
		while (begin->tab[i] != NULL)
			free(begin->tab[i++]);
		begin = begin->next;
		if (begin->prev)
			free(begin->prev);
	}
	i = 0;
	while (begin->tab[i] != NULL)
		free(begin->tab[i++]);
	free(begin);
	ft_putstr_fd("Error on parsing\n", STDIN_FILENO);
	exit(1);
}

void	pass_piece(char	**line, t_visu *v, t_v *begin);
void	pass_piece(char	**line, t_visu *v, t_v *begin)
{
	char	**tab;
	int		i;
	int		nb_y;

	tab = ft_strsplit(*line, ' ');
	i = 0;
	nb_y = ft_atoi(tab[1]);
	while (i <= nb_y)
	{
		free(*line);
		if (get_next_line_backslash(STDIN_FILENO, &(*line)) != 1)
			free_linked_list(v, *line, begin);
		i++;
	}
	ft_free_tab_char(&tab);
}

void	check_status(char **line, t_visu *v, t_v *begin, int *current_player);
void	check_status(char **line, t_visu *v, t_v *begin, int *current_player)
{
	if (ft_strstr(*line, "Piece") != 0)// si on a piece == ennemi a perdu
	{
		pass_piece(line, v, begin);
		if (ft_strstr(*line, "O") != 0)
			*current_player = 1;
		else
			*current_player = 2;
		free(*line);
		if (get_next_line_backslash(STDIN_FILENO, &(*line)) != 1)
			free_linked_list(v, *line, begin);
		v->status = 1;
	}
	if (ft_strstr(*line, "fin") != 0)// Si on a fin == fin du jeu
		v->status = 2;
	if (ft_strstr(*line, "Plateau") != 0)
		v->status = 0;
	free(*line);
	if (get_next_line_backslash(STDIN_FILENO, line) != 1)
		free_linked_list(v, *line, begin);
	free(*line);
}

void	stock_map(t_v **t, t_visu *v, int current_player);
void	stock_map(t_v **t, t_visu *v, int current_player)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	(*t)->tab = (char **)malloc(sizeof (char *) * (unsigned long)(v->nb_y + 1));
	while (i < v->nb_y)
	{
		get_next_line_backslash(STDIN_FILENO, &line);
		(*t)->tab[i] = ft_strsub(line, 4, (size_t)v->nb_x);
		i++;
		free(line);
	}
	(*t)->tab[i] = NULL;
	(*t)->current_player = current_player;
	(*t)->next  = NULL;
	(*t)->prev = NULL;
}

void	stock_link(t_visu *v, t_v **t, t_v *begin);
void	stock_link(t_visu *v, t_v **t, t_v *begin)
{
	char	*line;
	int		ret;
	int		current_player;

	line = NULL;
	ret = -1;
	current_player = 0;

	if (get_next_line_backslash(STDIN_FILENO, &line) != 1)
		free_linked_list(v, line, begin);
	if (ft_strstr(line, "Piece") == 0)
		free_linked_list(v, line, begin);
	pass_piece(&line, v, begin);
	if(ft_strstr(line, "got") == 0)
		free_linked_list(v, line, begin);
	if (ft_strstr(line, "O") != 0)
		current_player = 1;
	else if (ft_strstr(line, "X") != 0)
		current_player = 2;
	free(line);
	if (get_next_line_backslash(STDIN_FILENO, &line) != 1)
		free_linked_list(v, line, begin);
	check_status(&line, v, begin, &current_player);
	if (v->status != 2)
	{
		(*t)->next = (t_v*)malloc(sizeof(**t));
		(*t)->next->prev = *t;
		*t = (*t)->next;
		(*t)->next = NULL;
		stock_map(t, v, current_player);
	}

}

int	main(void)
{
	t_visu	v;
	t_v		*t;
	t_v		*begin;

	init_struct_visu(&v);
	verif_header_vm();
	get_players_vm(&v);
	get_board_infos(&t, &v);
	begin = t;
	stock_first_link(&v, &t);
	while (v.status != 2)
	{
		if (v.status != 1)
			stock_link(&v, &t, begin);
		else
			v.status = 0;
	}

int		i;

while (begin != NULL)
{
	ft_printf("{yellow}Player %d plays !{eoc}\n", begin->current_player);
	i = 0;
	while (begin->tab[i] != NULL)
	{
		ft_putendl(begin->tab[i++]);
	}
	begin = begin->next;
	ft_putchar('\n');
}

//	sleep(1);
	return (0);
}
