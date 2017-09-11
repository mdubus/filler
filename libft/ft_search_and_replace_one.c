/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:50:46 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/18 16:31:42 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*search_and_replace_one(char *str, char *old, char *mew)
{
	size_t	oldlen;
	size_t	newlen;
	char	*new_str;
	char	*temp;
	size_t	char_begin;

	char_begin = 0;
	oldlen = ft_strlen_secure(str);
	newlen = oldlen - (ft_strlen_secure(old) - ft_strlen_secure(mew));
	new_str = ft_strnew(newlen);
	temp = ft_strstr(str, old);
	char_begin = ft_strlen_secure(str) - ft_strlen_secure(temp);
	new_str = ft_strncpy(new_str, str, char_begin);
	new_str = ft_strcat(new_str, mew);
	temp = temp + ft_strlen_secure(old);
	new_str = ft_strcat(new_str, temp);
	return (new_str);
}
