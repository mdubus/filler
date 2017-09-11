/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:47:07 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:59:17 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_printf_c2(va_list ap, t_f *cr, char *c, char *temp3)
{
	char	temp2;

	temp2 = (char)va_arg(ap, int);
	if (!temp2 || temp2 == 0)
		cr->result = ft_strnew(1);
	else if (temp2 == '0')
	{
		cr->result = ft_strnew(1);
		cr->result[0] = '0';
	}
	else
	{
		c[0] = *ft_strdup(&temp2);
		c[1] = '\0';
		temp3 = ft_strdup(c);
		cr->result = ft_strdup(temp3);
		free(temp3);
	}
}

void		ft_printf_c(t_f *cr, va_list ap)
{
	char	*c;
	int		temp;
	char	*temp3;

	temp = 0;
	temp3 = NULL;
	c = ft_strnew(1);
	if ((cr->modifier && cr->modifier[0] == 'l') || cr->type[0] == 'C')
	{
		temp = va_arg(ap, int);
		temp3 = ft_getwchar(temp);
		cr->result = ft_strdup(temp3);
		free(temp3);
	}
	else
		ft_printf_c2(ap, cr, c, temp3);
	free(c);
}

static void	ft_printf_s2(t_f *cr, va_list ap, wchar_t *str, char *str2)
{
	str = va_arg(ap, wchar_t*);
	if (str == NULL)
		cr->result = ft_strdup("(null)");
	else if (str[0] == 0)
		cr->result = ft_strnew(1);
	else
	{
		str2 = ft_getwstring(str);
		cr->result = str2;
	}
}

void		ft_printf_s(t_f *cr, va_list ap)
{
	wchar_t	*str;
	char	*str2;
	char	*str3;

	str = NULL;
	str2 = NULL;
	if ((cr->modifier && cr->modifier[0] == 'l') || cr->type[0] == 'S')
		ft_printf_s2(cr, ap, str, str2);
	else
	{
		str3 = (char*)va_arg(ap, void*);
		if (str3 != NULL)
			cr->result = ft_strdup(str3);
		else
			cr->result = ft_strdup("(null)");
	}
}
