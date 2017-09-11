/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:42:54 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 19:00:13 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	preci21(char *temp, t_f *cr, size_t i, size_t precision)
{
	temp = ft_strdup(cr->result);
	free(cr->result);
	cr->result = ft_strnew(precision);
	while (i < precision)
	{
		cr->result[i] = temp[i];
		i++;
	}
}

static void	preci22(char *temp, t_f *cr, size_t precision, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	temp = ft_strdup(cr->result);
	free(cr->result);
	cr->result = ft_fill_with(precision - 1, '0');
	i = precision - size;
	while (i < precision)
		cr->result[i++] = temp[j++];
	free(temp);
}

void		preci2(t_f *cr, size_t precision, size_t size, char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((cr->type[0] != 's' && cr->type[0] != 'S' && cr->type[0] != 'c')
			&& precision > size)
		preci22(temp, cr, precision, size);
	else if (precision < size && (cr->type[0] == 's' || cr->type[0] == 'S'))
		preci21(temp, cr, i, precision);
	else if ((cr->precision[0] == '.' || cr->precision[0] == '0') &&
			(cr->result[0] == '0' || cr->result == NULL))
	{
		free(cr->result);
		cr->result = ft_strnew(0);
	}
}

void		preci3(t_f *cr, char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_replace_char_with_char_in_str(&cr->result, '-', '0');
	temp = ft_strdup(cr->result);
	free(cr->result);
	cr->result = ft_strnew(ft_strlen_secure(temp + 1));
	i = ft_strlen_secure(temp) + 1;
	j = i - 1;
	while (i > 0)
		cr->result[i--] = temp[j--];
	cr->result[0] = '-';
}
