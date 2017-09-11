/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:30:40 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/17 13:40:55 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (unsigned int)n && s1[i] != '\0' && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == n)
		return ((unsigned char)(s1[i - 1]) - (unsigned char)(s2[i - 1]));
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
