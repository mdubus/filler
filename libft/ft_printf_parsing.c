/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:25 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 19:01:40 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		do_parsing2(char *str, t_f *cr, int i)
{
	int	j;

	j = 0;
	i++;
	i = i + (do_parsing_flag(str, cr, i));
	i = i + (do_parsing_width(str, cr, i));
	i = i + (do_parsing_precision(str, cr, i, j));
	i = i + (do_parsing_modifier(str, cr, i));
	i = i + (do_parsing_type(str, cr, i));
	return (i);
}

void			do_parsing(char *str, int nb_arg, t_f **cr, va_list ap)
{
	int		i;
	t_f		*begin;

	i = 0;
	begin = *cr;
	while (nb_arg > 0)
	{
		if (str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			i = do_parsing2(str, *cr, i);
			recup_argument(*cr);
			put_result(*cr, ap);
			if (nb_arg > 1)
				*cr = (*cr)->next;
			nb_arg--;
		}
	}
	(*cr)->next = NULL;
	*cr = begin;
}
