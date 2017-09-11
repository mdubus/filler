/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_width.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:54:47 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 19:00:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		check_precision(t_f *cr)
{
	size_t		size;
	size_t		precision;
	char		*temp;

	size = 0;
	precision = 0;
	temp = NULL;
	size = ft_strlen_secure(cr->result);
	if (cr->precision && cr->type[0] != 'C')
	{
		precision = (size_t)ft_atoi(cr->precision);
		preci2(cr, precision, size, temp);
		if (ft_strchr(cr->result, '-'))
			preci3(cr, temp);
	}
}

static void	check_width2(t_f *cr, size_t width)
{
	size_t	i;
	size_t	size;
	int		nb;

	i = 0;
	size = 0;
	nb = 0;
	nb = ft_atoi(cr->result);
	if (cr->flag && ft_strchr(cr->flag, '0'))
	{
		size = (size_t)ft_atoi(cr->precision);
		if (width > size && nb >= 0)
		{
			i = 0;
			while (width > size)
			{
				cr->result[i] = ' ';
				i++;
				size++;
			}
		}
	}
}

void		check_width_sup_size(t_f *cr, size_t size, size_t width)
{
	char	*temp;
	size_t	i;
	size_t	j;

	temp = NULL;
	i = 0;
	j = 0;
	temp = ft_strdup(cr->result);
	free(cr->result);
	cr->result = ft_fill_with(width - 1, ' ');
	i = width - size;
	while (i < width)
		cr->result[i++] = temp[j++];
	free(temp);
}

void		check_width(t_f *cr)
{
	size_t		size;
	size_t		width;

	width = 0;
	size = ft_strlen_secure(cr->result);
	if (cr->width)
	{
		width = (size_t)ft_atoi(cr->width);
		if ((cr->type[0] == 'c' || cr->type[0] == 'C') && cr->result[0] == '\0')
			width--;
		if (width > size)
			check_width_sup_size(cr, size, width);
	}
	if (cr->precision)
		check_width2(cr, width);
}
