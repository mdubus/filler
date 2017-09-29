/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstartcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:42:20 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/29 12:45:58 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstartcpy(char *s, size_t i)
{
	size_t	len;
	char	*str;
	size_t	j;

	str = NULL;
	len = ft_strlen(s) - i;
	j = 0;
	str = malloc(sizeof(char) * len + 1);
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
