/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:38:05 by mdubus            #+#    #+#             */
/*   Updated: 2016/12/03 11:47:40 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	count_length(int len, int i, char const *s)
{
	while ((ft_isblank(s[len - 1]) == 1) || s[len - 1] == 10)
		len--;
	if (len <= 0)
		return (0);
	while (ft_isblank(s[i]) == 1 || s[i] == 10)
	{
		i++;
		len--;
	}
	return (len);
}

static char	*do_strtrim(char *str, int i, int len, const char *s)
{
	int	j;

	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (len)
	{
		str[j] = s[i];
		j++;
		i++;
		len--;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (s == 0)
		return (0);
	len = ft_strlen_secure(s);
	len = count_length(len, i, s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (len == 0)
	{
		str[i] = '\0';
		return (str);
	}
	if (str == 0)
		return (0);
	if (len != 0)
		str = do_strtrim(str, i, len, s);
	return (str);
}
