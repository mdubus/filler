/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char_with_char_in_str.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:32:08 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/12 12:34:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_replace_char_with_char_in_str(char **str, char search, char replace)
{
	int		i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == search)
			(*str)[i++] = replace;
		else
			i++;
	}
}
