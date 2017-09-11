/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_flag_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:41:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:59:26 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	do_flag_hash_with_o(t_f *cr)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 0;
	j = 0;
	if (cr->result)
	{
		if (cr->result[0] != '0')
		{
			temp = ft_strnew(ft_strlen_secure(cr->result) + 1);
			temp[i++] = '0';
			while (cr->result[j] != '\0')
			{
				temp[i++] = cr->result[j++];
			}
			ft_swap_adress(&cr->result, &temp);
			free(temp);
		}
	}
}

static void	do_flag_hash_with_x(t_f *cr)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 0;
	j = 0;
	if (cr->result)
	{
		if (cr->result[0] != '0' && cr->result[0] != 0)
		{
			temp = ft_strnew(ft_strlen_secure(cr->result) + 1);
			temp[i++] = '0';
			temp[i++] = 'x';
			while (cr->result[j] != '\0')
			{
				temp[i++] = cr->result[j++];
			}
			ft_swap_adress(&cr->result, &temp);
			free(temp);
		}
		if (cr->type[0] == 'X')
			ft_strtoupper(&cr->result);
	}
}

void		do_flag_hash(t_f *cr)
{
	if (cr->type[0] == 'o' || cr->type[0] == 'O')
		do_flag_hash_with_o(cr);
	else if (cr->type[0] == 'x' || cr->type[0] == 'X')
		do_flag_hash_with_x(cr);
}
