/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:21:15 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 17:19:17 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	compare_return_error(char *s1, char *s2, char **tab)
{
	int	flag;

	flag = 0;
	if (!s1)
		flag = 1;
	if (!s2)
		flag = 1;
	if (!(*tab))
		flag = 1;
	if (ft_strcmp(s1, s2) != 0)
		flag = 1;
	if (flag == 1)
	{
		ft_free_tab_char(&tab);
		return (1);
	}
	return (0);
}
