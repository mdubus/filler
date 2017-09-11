/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_recup_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:48 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 19:00:36 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	recup_argument2(t_f *cr, int j, int i)
{
	if (cr->precision != NULL)
	{
		j = 0;
		if (cr->precision[0] != '.')
			cr->argument[i++] = '.';
		while (cr->precision[j] != '\0')
			cr->argument[i++] = cr->precision[j++];
	}
	if (cr->modifier != NULL)
	{
		j = 0;
		while (cr->modifier[j] != '\0')
			cr->argument[i++] = cr->modifier[j++];
	}
	if (cr->type != NULL)
	{
		j = 0;
		while (cr->type[j] != '\0')
			cr->argument[i++] = cr->type[j++];
	}
}

void		recup_argument(t_f *cr)
{
	size_t	length;
	int		i;
	int		j;

	i = 1;
	j = 0;
	length = ft_strlen_secure(cr->flag) + ft_strlen_secure(cr->width) +
		ft_strlen_secure(cr->precision) + ft_strlen_secure(cr->modifier) +
		ft_strlen_secure(cr->type);
	cr->argument = ft_strnew(length + 2);
	cr->argument[0] = '%';
	if (cr->flag != NULL)
	{
		while (cr->flag[j] != '\0')
			cr->argument[i++] = cr->flag[j++];
	}
	if (cr->width != NULL)
	{
		j = 0;
		while (cr->width[j] != '\0')
			cr->argument[i++] = cr->width[j++];
	}
	recup_argument2(cr, j, i);
}
