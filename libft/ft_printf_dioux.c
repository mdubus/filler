/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dioux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:54:11 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:55:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_printf_di(t_f *cr, va_list ap)
{
	if (cr->type[0] == 'D')
		cr->result = ft_itoa_llint(va_arg(ap, long int));
	else
	{
		if (cr->modifier == NULL)
			cr->result = ft_itoa(va_arg(ap, int));
		else if (ft_strstr(cr->modifier, "hh"))
			cr->result = ft_itoa((signed char)va_arg(ap, int));
		else if (ft_strchr(cr->modifier, 'h'))
			cr->result = ft_itoa((short int)va_arg(ap, int));
		else if (ft_strstr(cr->modifier, "ll"))
			cr->result = ft_itoa_llint(va_arg(ap, long long int));
		else if (ft_strchr(cr->modifier, 'l'))
			cr->result = ft_itoa_llint(va_arg(ap, long int));
		else if (ft_strchr(cr->modifier, 'j'))
			cr->result = ft_itoa_llint(va_arg(ap, intmax_t));
		else if (ft_strchr(cr->modifier, 'z'))
			cr->result = ft_itoa_ullint(va_arg(ap, size_t));
	}
}

void	ft_printf_o(t_f *cr, va_list ap)
{
	if (cr->type[0] == 'O')
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned long int), 8);
	else
	{
		if (cr->modifier == NULL)
			cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned int), 8);
		else if (ft_strstr(cr->modifier, "hh"))
			cr->result = ft_itoa_base((unsigned char)va_arg(ap, int), 8);
		else if (ft_strchr(cr->modifier, 'h'))
			cr->result = ft_itoa_base((unsigned short int)va_arg(ap, int), 8);
		else if (ft_strstr(cr->modifier, "ll"))
			cr->result = ft_itoa_b_ullint(va_arg(ap,
						unsigned long long int), 8);
		else if (ft_strchr(cr->modifier, 'l'))
			cr->result = ft_itoa_b_ullint(va_arg(ap,
						unsigned long int), 8);
		else if (ft_strchr(cr->modifier, 'j'))
			cr->result = ft_itoa_b_ullint(va_arg(ap, uintmax_t), 8);
		else if (ft_strchr(cr->modifier, 'z'))
			cr->result = ft_itoa_b_ullint(va_arg(ap, size_t), 8);
	}
}

void	ft_printf_u(t_f *cr, va_list ap)
{
	if (cr->type[0] == 'U')
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned long int), 10);
	else
	{
		if (cr->modifier == NULL)
			cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned int), 10);
		else if (ft_strstr(cr->modifier, "hh"))
			cr->result = ft_itoa_base((unsigned char)va_arg(ap, int), 10);
		else if (ft_strchr(cr->modifier, 'h'))
			cr->result = ft_itoa_base((unsigned short int)va_arg(ap, int), 10);
		else if (ft_strstr(cr->modifier, "ll"))
			cr->result = ft_itoa_b_ullint(va_arg(ap,
						unsigned long long int), 10);
		else if (ft_strchr(cr->modifier, 'l'))
			cr->result = ft_itoa_b_ullint(va_arg(ap,
						unsigned long int), 10);
		else if (ft_strchr(cr->modifier, 'j'))
			cr->result = ft_itoa_b_ullint(va_arg(ap, uintmax_t), 10);
		else if (ft_strchr(cr->modifier, 'z'))
			cr->result = ft_itoa_b_ullint(va_arg(ap, size_t), 10);
	}
}

void	ft_printf_x(t_f *cr, va_list ap)
{
	if (cr->modifier == NULL)
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned int), 16);
	else if (ft_strstr(cr->modifier, "hh"))
		cr->result = ft_itoa_base((unsigned char)va_arg(ap, int), 16);
	else if (ft_strchr(cr->modifier, 'h'))
		cr->result = ft_itoa_base((unsigned short int)va_arg(ap, int), 16);
	else if (ft_strstr(cr->modifier, "ll"))
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned long long int), 16);
	else if (ft_strchr(cr->modifier, 'l'))
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned long int), 16);
	else if (ft_strchr(cr->modifier, 'j'))
		cr->result = ft_itoa_b_ullint(va_arg(ap, uintmax_t), 16);
	else if (ft_strchr(cr->modifier, 'z'))
		cr->result = ft_itoa_b_ullint(va_arg(ap, size_t), 16);
}

void	ft_printf_x_upper(t_f *cr, va_list ap)
{
	if (cr->modifier == NULL)
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned int), 16);
	else if (ft_strstr(cr->modifier, "hh"))
		cr->result = ft_itoa_base((unsigned char)va_arg(ap, int), 16);
	else if (ft_strchr(cr->modifier, 'h'))
		cr->result = ft_itoa_base((unsigned short int)va_arg(ap, int), 16);
	else if (ft_strstr(cr->modifier, "ll"))
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned long long int), 16);
	else if (ft_strchr(cr->modifier, 'l'))
		cr->result = ft_itoa_b_ullint(va_arg(ap, unsigned long int), 16);
	else if (ft_strchr(cr->modifier, 'j'))
		cr->result = ft_itoa_b_ullint(va_arg(ap, uintmax_t), 16);
	else if (ft_strchr(cr->modifier, 'z'))
		cr->result = ft_itoa_b_ullint(va_arg(ap, size_t), 16);
	ft_strtoupper(&cr->result);
}
