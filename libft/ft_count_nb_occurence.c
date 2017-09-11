/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_occurence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:56:17 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/12 14:40:46 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_count_nb_occurence(char *str, char *search, int *nb_oc)
{
	char	*temp;
	int		len_search;

	temp = str;
	len_search = 0;
	len_search = ft_strlen_secure(search);
	while (str)
	{
		if ((str = ft_strstr(str, search)))
		{
			(*nb_oc)++;
			str = str + len_search;
		}
	}
}
