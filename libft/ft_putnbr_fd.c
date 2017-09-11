/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:09:23 by mdubus            #+#    #+#             */
/*   Updated: 2016/11/20 15:37:20 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n > -2147483648 && n < -10)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0 && n > -10)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((char)-n + '0', fd);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd((char)n + '0', fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
