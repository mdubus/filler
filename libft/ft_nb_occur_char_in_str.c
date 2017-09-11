/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_occur_char_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:36:55 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/08 14:38:33 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_nb_occur_char_in_str(char *str, char *search)
{
	char	*temp;
	size_t	len_search;
	int		nb_occur;

	temp = str;
	len_search = 0;
	nb_occur = 0;
	len_search = ft_strlen_secure(search);
	while (str)
	{
		if ((str = ft_strstr(str, search)))
		{
			nb_occur++;
			str = str + len_search;
		}
	}
	return (nb_occur);
}
