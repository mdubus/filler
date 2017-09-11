/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:16:16 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:59:01 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_text_colors(char *str)
{
	char	*temp;

	temp = str;
	if (ft_strstr(str, "{black}"))
		str = search_and_replace_all(str, "{black}", "\033[30m");
	else if (ft_strstr(str, "{red}"))
		str = search_and_replace_all(str, "{red}", "\033[31m");
	else if (ft_strstr(str, "{green}"))
		str = search_and_replace_all(str, "{green}", "\033[32m");
	else if (ft_strstr(str, "{yellow}"))
		str = search_and_replace_all(str, "{yellow}", "\033[33m");
	else if (ft_strstr(str, "{blue}"))
		str = search_and_replace_all(str, "{blue}", "\033[34m");
	else if (ft_strstr(str, "{purple}"))
		str = search_and_replace_all(str, "{purple}", "\033[35m");
	else if (ft_strstr(str, "{cyan}"))
		str = search_and_replace_all(str, "{cyan}", "\033[36m");
	else if (ft_strstr(str, "{white}"))
		str = search_and_replace_all(str, "{white}", "\033[37m");
	else if (ft_strstr(str, "{grey}"))
		str = search_and_replace_all(str, "{grey}", "\033[02m");
	else if (ft_strstr(str, "{eoc}"))
		str = search_and_replace_all(str, "{eoc}", "\033[0m");
	free(temp);
	return (str);
}

static char	*ft_bg_colors(char *str)
{
	char	*temp;

	temp = str;
	if (ft_strstr(str, "{bg_black}"))
		str = search_and_replace_all(str, "{bg_black}", "\033[40m");
	else if (ft_strstr(str, "{bg_red}"))
		str = search_and_replace_all(str, "{bg_red}", "\033[41m");
	else if (ft_strstr(str, "{bg_green}"))
		str = search_and_replace_all(str, "{bg_green}", "\033[42m");
	else if (ft_strstr(str, "{bg_yellow}"))
		str = search_and_replace_all(str, "{bg_yellow}", "\033[43m");
	else if (ft_strstr(str, "{bg_blue}"))
		str = search_and_replace_all(str, "{bg_blue}", "\033[44m");
	else if (ft_strstr(str, "{bg_purple}"))
		str = search_and_replace_all(str, "{bg_purple}", "\033[45m");
	else if (ft_strstr(str, "{bg_cyan}"))
		str = search_and_replace_all(str, "{bg_cyan}", "\033[46m");
	else if (ft_strstr(str, "{bg_white}"))
		str = search_and_replace_all(str, "{bg_white}", "\033[47m");
	else if (ft_strstr(str, "{eoc}"))
		str = search_and_replace_all(str, "{eoc}", "\033[0m");
	free(temp);
	return (str);
}

static char	*ft_effects(char *str)
{
	char	*temp;

	temp = str;
	if (ft_strstr(str, "{bold}"))
		str = search_and_replace_all(str, "{bold}", "\033[01m");
	else if (ft_strstr(str, "{underline}"))
		str = search_and_replace_all(str, "{underline}", "\033[04m");
	else if (ft_strstr(str, "{highlighted}"))
		str = search_and_replace_all(str, "{highlighted}", "\033[07m");
	else if (ft_strstr(str, "{eoc}"))
		str = search_and_replace_all(str, "{eoc}", "\033[0m");
	free(temp);
	return (str);
}

char		*ft_colors(char *str)
{
	while (is_color(str))
		str = ft_text_colors(str);
	while (is_bgcolor(str))
		str = ft_bg_colors(str);
	while (is_effect(str))
		str = ft_effects(str);
	return (str);
}
