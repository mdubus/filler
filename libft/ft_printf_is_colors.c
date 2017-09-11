/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:17:17 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 14:25:23 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		is_color(char *str)
{
	if (ft_strstr(str, "{black}") || ft_strstr(str, "{red}") ||
			ft_strstr(str, "{green}") || ft_strstr(str, "{yellow}") ||
			ft_strstr(str, "{blue}") || ft_strstr(str, "{purple}") ||
			ft_strstr(str, "{cyan}") || ft_strstr(str, "{white}") ||
			ft_strstr(str, "{grey}") || ft_strstr(str, "{eoc}"))
		return (1);
	else
		return (0);
}

int		is_bgcolor(char *str)
{
	if (ft_strstr(str, "{bg_black}") || ft_strstr(str, "{bg_red}") ||
			ft_strstr(str, "{bg_green}") || ft_strstr(str, "{bg_yellow}") ||
			ft_strstr(str, "{bg_blue}") || ft_strstr(str, "{bg_purple}") ||
			ft_strstr(str, "{bg_cyan}") || ft_strstr(str, "{bg_white}") ||
			ft_strstr(str, "{bg_grey}") || ft_strstr(str, "{eoc}"))
		return (1);
	else
		return (0);
}

int		is_effect(char *str)
{
	if (ft_strstr(str, "{bold}") || ft_strstr(str, "{underline}") ||
			ft_strstr(str, "{highlighted}"))
		return (1);
	else
		return (0);
}
