/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:16:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:58:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_count_args_printf2(char *str, int *i, int *nb)
{
	if (is_flag(&(str)[*i]))
		while (is_flag(&(str)[*i]))
			(*i)++;
	if (ft_isdigit(str[*i]))
		while (ft_isdigit(str[*i]))
			(*i)++;
	if (str[*i] == '.')
		(*i)++;
	if (ft_isdigit(str[*i]))
		while (ft_isdigit(str[*i]))
			(*i)++;
	if (is_modifier(&(str)[*i]))
		while (is_modifier(&(str)[*i]))
			(*i)++;
	if (is_type(&(str)[*i]))
	{
		(*nb)++;
		(*i)++;
	}
	else
		(*i)++;
}

int			ft_count_args_printf(char *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] != c)
			i++;
		if (str[i] == c)
		{
			i++;
			ft_count_args_printf2(str, &i, &nb);
		}
	}
	return (nb);
}
