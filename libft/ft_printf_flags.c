/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:19:09 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 14:25:09 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	flag_hash(t_f *cr)
{
	do_flag_hash(cr);
	if (ft_strchr(cr->flag, '-'))
		do_flag_minus(cr);
	else if (ft_strchr(cr->flag, '0'))
		do_flag_zero(cr);
}

void	flag_zero2(t_f *cr)
{
	if (ft_strchr(cr->flag, ' '))
	{
		do_flag_space(cr);
		do_flag_zero(cr);
	}
	else if (ft_strchr(cr->flag, '-'))
		do_flag_minus(cr);
	else if (ft_strchr(cr->flag, '+'))
	{
		do_flag_plus(cr);
		do_flag_zero(cr);
	}
	else
		do_flag_zero(cr);
}

void	flag_zero(t_f *cr)
{
	if (ft_strchr(cr->flag, '-') && ft_strchr(cr->flag, '+'))
	{
		do_flag_plus(cr);
		do_flag_minus(cr);
	}
	else if (ft_strchr(cr->flag, ' ') &&
			ft_strchr(cr->flag, '+'))
	{
		do_flag_plus(cr);
		do_flag_zero(cr);
	}
	else if (ft_strchr(cr->flag, ' ') &&
			ft_strchr(cr->flag, '-'))
	{
		do_flag_space(cr);
		do_flag_minus(cr);
	}
	else
		flag_zero2(cr);
}

void	flag_minus(t_f *cr)
{
	if (ft_strchr(cr->flag, '+'))
	{
		do_flag_plus(cr);
		do_flag_minus(cr);
	}
	else if (ft_strchr(cr->flag, ' '))
	{
		do_flag_space(cr);
		do_flag_minus(cr);
	}
	else
		do_flag_minus(cr);
}

void	check_flags(t_f *cr)
{
	if (cr->flag)
	{
		if (ft_strchr(cr->flag, '#'))
			flag_hash(cr);
		else if (ft_strchr(cr->flag, '0'))
			flag_zero(cr);
		else if (ft_strchr(cr->flag, '-'))
			flag_minus(cr);
		else if (ft_strchr(cr->flag, '+'))
			do_flag_plus(cr);
		else if (ft_strchr(cr->flag, ' '))
			do_flag_space(cr);
	}
}
