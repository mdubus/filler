/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_name_vm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:14:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/07 10:35:17 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

static void	check_tab1(char *line, char **tab, int *i)
{
	if (!tab)
		put_error_fd(line, "bad player1\n");
	while (tab[*i] != NULL && ft_strstr(tab[*i], ".filler") == 0)
		(*i)++;
	if (tab[*i] == NULL)
	{
		ft_free_tab_char(&tab);
		exit(1);
	}
	else if (ft_strstr(tab[*i], ".filler") == 0)
	{
		ft_free_tab_char(&tab);
		exit(1);
	}
}

void		get_player_name_vm(char *line, char **player)
{
	char	**tab;
	char	**tab2;
	int		i;
	int		j;

	tab = NULL;
	tab2 = NULL;
	i = 0;
	j = 0;
	tab = ft_strsplit(line, '/');
	check_tab1(line, tab, &i);
	tab2 = ft_strsplit(tab[i], '.');
	ft_free_tab_char(&tab);
	if (!tab2)
		put_error_fd(line, "bad player1\n");
	free(line);
	while (tab2[j] != NULL && ft_strstr(tab2[j], "filler") == 0)
		j++;
	if (tab2[j] == NULL)
	{
		ft_free_tab_char(&tab2);
		exit(1);
	}
	*player = ft_strdup(tab2[j - 1]);
	ft_free_tab_char(&tab2);
}
