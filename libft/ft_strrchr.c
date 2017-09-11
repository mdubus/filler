/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:01:49 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/11 14:41:30 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	search_char;
	int		i;
	char	*adresse;

	i = 0;
	search_char = (char)c;
	adresse = 0;
	if (s[i] == '\0')
		adresse = 0;
	while (s[i] != '\0')
	{
		if (s[i] == search_char)
			adresse = (char *)&s[i];
		i++;
	}
	if (search_char == '\0')
		adresse = (char *)&s[i];
	return (adresse);
}
