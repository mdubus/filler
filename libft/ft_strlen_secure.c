/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_secure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:32:50 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/18 16:29:56 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen_secure(const char *s)
{
	if (s == NULL)
		return (0);
	else
		return (ft_strlen(s));
}
