/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:58:42 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/19 16:49:01 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = (char *)dst;
	source = (const char *)src;
	if (dest || source || len)
	{
		if (dest <= source)
			ft_memcpy(dest, source, len);
		else
		{
			if (len == 0)
				return (dest);
			while (len > 0)
			{
				dest[len - 1] = source[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
