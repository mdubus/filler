/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pourcent_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:36 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 19:00:00 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_printf_pourcent(t_f *cr)
{
	char	*c;

	c = ft_strnew(1);
	c[0] = '%';
	c[1] = '\0';
	cr->result = c;
}

static void	ft_printf_p2(t_f *cr, unsigned long int value)
{
	char	*temp;
	int		i;
	int		j;

	i = 2;
	j = 0;
	cr->result = ft_itoa_b_ullint(value, 16);
	if (cr->result[0] != '0')
	{
		temp = ft_strdup(cr->result);
		free(cr->result);
		cr->result = ft_strnew(ft_strlen_secure(temp) + 1);
		cr->result[0] = '0';
		cr->result[1] = 'x';
		while (temp[j] != '\0')
			cr->result[i++] = temp[j++];
		free(temp);
	}
}

void		ft_printf_p(t_f *cr, va_list ap)
{
	unsigned long int		value;

	value = va_arg(ap, unsigned long int);
	if (value == 0)
	{
		cr->result = ft_strnew(3);
		cr->result[0] = '0';
		cr->result[1] = 'x';
		cr->result[2] = '0';
	}
	else
		ft_printf_p2(cr, value);
}
