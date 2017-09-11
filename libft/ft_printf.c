/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:43:22 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 19:01:10 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void			ft_printf4(t_f *cr, size_t *size)
{
	if ((cr->type[0] == 'c' || cr->type[0] == 'C') && cr->result[0] == '\0')
	{
		ft_putchar('\0');
		(*size)++;
	}
	else if (cr->type[0] == 'c' || cr->type[0] == 'C')
	{
		if (cr->width)
			*size = ft_atoi(cr->width);
		else
			*size = ft_strlen_secure(cr->result);
	}
}

static size_t		ft_printf3(char **str, t_f **cr, int *i, int *nb_arg)
{
	int		j;
	size_t	size;
	t_f		*temp;

	j = 0;
	size = 0;
	while ((*str)[*i] != '%')
	{
		ft_putchar((*str)[(*i)++]);
		size++;
	}
	while ((*cr)->result[j] != '\0')
	{
		ft_putchar((*cr)->result[j++]);
		size++;
	}
	ft_printf4(*cr, &size);
	*i = *i + ft_strlen((*cr)->argument);
	(*nb_arg)--;
	j = 0;
	temp = *cr;
	*cr = (*cr)->next;
	return (size);
}

static void			ft_printf2(char **str, size_t *size, t_f *cr, va_list ap)
{
	int		nb_arg;
	int		i;

	i = 0;
	nb_arg = ft_count_args_printf(*str, '%');
	*str = ft_colors(*str);
	if (nb_arg > 0)
		do_parsing(*str, nb_arg, &cr, ap);
	while (nb_arg > 0)
		*size = *size + ft_printf3(str, &cr, &i, &nb_arg);
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '%')
		{
			ft_putchar('\0');
			i++;
			while ((*str)[i] == ' ')
				i++;
		}
		else
		{
			ft_putchar((*str)[i++]);
			(*size)++;
		}
	}
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	size_t		size;
	t_f			cr;

	size = 0;
	str = ft_strdup(format);
	va_start(ap, format);
	ft_printf2(&str, &size, &cr, ap);
	free(str);
	va_end(ap);
	return ((int)size);
}
