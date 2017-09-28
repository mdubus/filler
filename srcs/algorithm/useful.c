/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:21:15 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/23 15:13:21 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	compare_return_error(char *s1, char *s2, int fd)
{
	if (ft_strcmp(s1, s2) != 0)
		ft_print_error_fd_exit(ft_putstr_fd, "Error", fd);
}
