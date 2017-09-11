/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:08 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 14:23:07 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+' ||
			str[i] == ' ' || str[i] == '*' || str[i] == '$' || str[i] == 'L' ||
			str[i] == '\'')
		return (1);
	else
		return (0);
}

int		is_modifier(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		return (1);
	else
		return (0);
}

int		is_type(char *str)
{
	int		i;

	i = 0;
	if (str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd' ||
	str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O' ||
	str[i] == 'u' || str[i] == 'U' || str[i] == 'x' || str[i] == 'X' ||
	str[i] == 'c' || str[i] == 'C' || str[i] == 'e' || str[i] == 'E' ||
	str[i] == 'f' || str[i] == 'F' || str[i] == 'g' || str[i] == 'G' ||
	str[i] == 'a' || str[i] == 'A' || str[i] == 'n' || str[i] == '%' ||
	str[i] == 'b')
		return (1);
	else
		return (0);
}
