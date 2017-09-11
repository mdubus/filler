/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_flag_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:25:32 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:59:36 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	do_flag_zero3(t_f *cr, int i, int j, char **temp)
{
	if (cr->result[j + 1] == '+')
	{
		(*temp)[++i] = '0';
		(*temp)[0] = '+';
	}
	else if (cr->result[j + 1] == ' ')
	{
		(*temp)[++i] = '0';
		(*temp)[0] = ' ';
	}
	else if (cr->result[j + 1] == '-')
	{
		(*temp)[++i] = '0';
		(*temp)[0] = '-';
	}
}

static void	do_flag_zero2(t_f *cr, char **temp, int width_result, int i)
{
	int		j;

	width_result = ft_strlen_secure(cr->result);
	j = width_result;
	if (ft_strchr(cr->flag, '#'))
		if (cr->type[0] == 'x' || cr->type[0] == 'X')
			width_result = width_result - 2;
	while (width_result >= 0)
	{
		(*temp)[i--] = cr->result[j--];
		width_result--;
	}
	do_flag_zero3(cr, i, j, temp);
	if (ft_strchr(cr->flag, '#'))
	{
		if (cr->type[0] == 'x' || cr->type[0] == 'X')
		{
			if (cr->type[0] == 'x')
				(*temp)[1] = 'x';
			else
				(*temp)[1] = 'X';
		}
	}
	ft_swap_adress(&cr->result, temp);
	free(*temp);
}

void		do_flag_zero(t_f *cr)
{
	int		width;
	char	*temp;
	int		i;
	int		width_result;

	if (cr->type[0] != 's' || cr->type[0] != 'S' || cr->type[0] != 'p' ||
			cr->type[0] != 'c' || cr->type[0] != 'C')
	{
		i = 0;
		width_result = 0;
		if (cr->width)
		{
			width = ft_atoi(cr->width);
			if (width > (int)ft_strlen(cr->result))
			{
				temp = ft_strnew(width);
				while (i < width)
					temp[i++] = '0';
				do_flag_zero2(cr, &temp, width_result, i);
			}
		}
	}
}
