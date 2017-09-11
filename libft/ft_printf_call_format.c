/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:16:06 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:58:12 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	put_result2(t_f *cr, va_list ap)
{
	if (cr->type[0] == 'c' || cr->type[0] == 'C')
		ft_printf_c(cr, ap);
	if (cr->type[0] == 's' || cr->type[0] == 'S')
		ft_printf_s(cr, ap);
	if (cr->type[0] == '%')
		ft_printf_pourcent(cr);
	if (cr->type[0] == 'p')
		ft_printf_p(cr, ap);
	if (cr->result != NULL)
	{
		check_precision(cr);
		check_flags(cr);
		check_width(cr);
	}
}

void		put_result(t_f *cr, va_list ap)
{
	if (cr->flag && ft_strchr(cr->flag, '*'))
		cr->width = ft_itoa(va_arg(ap, int));
	if (cr->type[0] == 'd' || cr->type[0] == 'i' || cr->type[0] == 'D')
		ft_printf_di(cr, ap);
	if (cr->type[0] == 'o' || cr->type[0] == 'O')
		ft_printf_o(cr, ap);
	if (cr->type[0] == 'u' || cr->type[0] == 'U')
		ft_printf_u(cr, ap);
	if (cr->type[0] == 'x')
		ft_printf_x(cr, ap);
	if (cr->type[0] == 'X')
		ft_printf_x_upper(cr, ap);
	put_result2(cr, ap);
}
