/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:17:42 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:56:14 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	do_flag_minus(t_f *cr)
{
	int		width;
	char	*temp;
	int		i;

	i = 0;
	if (cr->width)
	{
		width = ft_atoi(cr->width);
		if (width > (int)ft_strlen(cr->result))
		{
			temp = ft_strnew(width);
			temp = ft_strcpy(temp, (cr->result));
			i = ft_strlen(cr->result);
			while (i < width)
				temp[i++] = ' ';
			ft_swap_adress(&cr->result, &temp);
			free(temp);
		}
	}
}

void	do_flag_space(t_f *cr)
{
	int		result;
	char	*temp;
	int		i;
	int		j;
	int		width;

	i = 0;
	j = 0;
	width = ft_strlen_secure(cr->result);
	result = ft_atoi(cr->result);
	if (cr->type[0] == 'd' || cr->type[0] == 'D' || cr->type[0] == 'i')
	{
		if (result >= 0)
			width++;
		temp = ft_strnew(width);
		if (result >= 0)
			temp[i++] = ' ';
		while (cr->result[j] != '\0')
			temp[i++] = cr->result[j++];
		ft_swap_adress(&cr->result, &temp);
		free(temp);
	}
}

void	do_flag_plus(t_f *cr)
{
	int		result;
	char	*temp;
	int		i;
	int		j;
	int		width;

	i = 0;
	j = 0;
	width = ft_strlen_secure(cr->result);
	result = ft_atoi(cr->result);
	if (cr->type[0] == 'd' || cr->type[0] == 'D' || cr->type[0] == 'i')
	{
		if (result >= 0)
			width++;
		temp = ft_strnew(width);
		if (result >= 0)
			temp[i++] = '+';
		while (cr->result[j] != '\0')
			temp[i++] = cr->result[j++];
		ft_swap_adress(&cr->result, &temp);
		free(temp);
	}
}
