/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:08:16 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/01 15:19:11 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/includes/libft.h"
#include <stdlib.h>

typedef struct	s_v
{
	char		**tab;
	int			current_player;
	struct s_v	*next;
	struct s_v	*prev;
}				t_v;

typedef struct	s_visu
{
	int			width_w;
	int			height_w;
	int			nb_x;
	int			nb_y;
	int			width_line;
	int			height_line;
	int			ret;
	char		*p1;
	char		*p2;
}				t_visu;

int	stock_map_in_list(t_visu *v, t_v *t, char **line);
int	stock_map_in_list(t_visu *v, t_v *t, char **line)
{
	int	i;

	i = 0;
	t->tab = (char**)malloc(sizeof(char*) * (v->nb_y + 1));
	while (i < v->nb_y - 1)
	{
		if (ft_strlen(*line) != (size_t)v->nb_x + 5)
			exit (1);
		t->tab[i++] = ft_strsub(*line, 4, v->nb_x);
		free(*line);
		v->ret = get_next_line_backslash(STDIN_FILENO, line);
		if (v->ret == 0)
			return (1); // a modifier
	}
	t->tab[i] = NULL;
	return (0);
}

void	case_ennemy_lost(char **line, t_visu *v);
void	case_ennemy_lost(char **line, t_visu *v)
{
	char	**tab;
	int	nb_y_piece;

	tab = ft_strsplit(*line, ' ');
	nb_y_piece = ft_atoi(tab[1]);
	ft_free_tab_char(&tab);

	while (nb_y_piece > 0)
	{
		v->ret = get_next_line_backslash(STDIN_FILENO, line);
//		ft_putstr(*line);
		nb_y_piece--;
	}
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
//	ft_putstr(*line);
	v->ret = get_next_line_backslash(STDIN_FILENO, line);
//	ft_putstr(*line);
}


int	pass_piece(char **line)
{
	char	**tab;
	int		nb_y_piece;
	
	tab = ft_strsplit(*line, ' ');
	nb_y_piece = ft_atoi(tab[1]);
	ft_free_tab_char(&tab);
	
	while (nb_y_piece > 0)
	{
		if (get_next_line_backslash(STDIN_FILENO, line) == 0)
			return (1);
//		ft_putstr(*line);
		nb_y_piece--;
	}
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
	return (0);
}

int		stock_map(t_visu *v, t_v **t, char **line)
{
	// Penser a free *line a chaque fois
	// Penser a check le retour de v->ret
	int		i;

	i = 0;
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
	if (ft_strstr(*line, "Piece") != 0) // Ennemi a perdu
	{
		case_ennemy_lost(line, v);
	}
	else if (ft_strstr(*line, "Plateau") == 0 || ft_strstr(*line, "fin") != 0)
	{
//		ft_putstr(*line);
//		ft_putendl("1 - Plateau");
		return (1);
	}
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
//	ft_putstr(*line); // numeros de lignes en X
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
//	ft_putstr(*line); // Premiere ligne du platea

	stock_map_in_list(v, *t, line);

	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		return (1);
//	ft_putstr(*line); // Piece
	if (ft_strstr(*line, "Piece") == 0)
	{
//		ft_putendl("1 - Piece");
		return (1);
	}

	if (pass_piece(line) == 1)
		return (1);
//	ft_putstr(*line); // Got
	if (ft_strstr(*line, "got") == 0)
	{
		ft_putendl("1 - got");
		return (1);
	}
	if (ft_strstr(*line, "X") != 0)
		(*t)->current_player = 2;
	else if (ft_strstr(*line, "O") != 0)
		(*t)->current_player = 1;

	return (0);
}


void	init_first_link(char **line, t_v **t, t_v **begin, t_visu *v)
{
	int	i;

	i = 0;
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
	{
		free(*line);
		exit(1);
	}
	ft_putendl("\nfirst line");
	ft_putstr(*line);
	if (get_next_line_backslash(STDIN_FILENO, line) == 0)
	{
		free(*line);
		exit(1);
	}
	*t = malloc(sizeof(t));
	*begin = *t;
	stock_map_in_list(v, *t, line);

	// PRINT
	while ((*t)->tab[i] && (*t)->tab[i] != NULL)
		ft_putendl((*t)->tab[i++]);
	ft_putchar('\n');
	//
	
	if (v->ret != 1)
		(*t)->next = NULL;
	while (ft_strstr(*line, "got") == 0)
	{
		if (get_next_line_backslash(STDIN_FILENO, line) == 0)
		{
			free(*line);
			exit (1);
		}
	}
	if (ft_strstr(*line, "X") != 0)
		(*t)->current_player = 2;
	else if (ft_strstr(*line, "O") != 0)
		(*t)->current_player = 1;
}

int	main(void)
{
	t_visu	v;
	t_v		*t;
	t_v		*begin;
	char	*line;

	init_first_link(&line, &t, &begin, &v);

	
	return (0);
}
