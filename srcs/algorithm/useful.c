/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:21:15 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 12:04:15 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	compare_return_error(char *s1, char *s2, char **tab)
{
	if (ft_strcmp(s1, s2) != 0)
	{
		ft_free_tab_char(&tab);
		return (1);
	}
	return (0);
}
