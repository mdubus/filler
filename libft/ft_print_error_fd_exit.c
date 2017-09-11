/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_fd_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:43:14 by mdubus            #+#    #+#             */
/*   Updated: 2017/09/08 15:44:20 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_error_fd_exit(void (*function)(const char *, int fd),
		const char *str, int fd)
{
	(*function)(str, fd);
	exit(1);
}
