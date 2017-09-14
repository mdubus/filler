/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_proper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 21:28:04 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/14 21:29:10 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_proper(char *s1, int free1, char *s2, int free2)
{
	char	*temp1;
	char	*temp2;
	char	*mew;

	temp1 = s1;
	temp2 = s2;
	mew = ft_strjoin(s1, s2);
	if (free1 == 1)
		free(temp1);
	if (free2 == 1)
		free(temp2);
	return (mew);
}
