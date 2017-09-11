/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getwchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:16:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/26 18:59:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_getwchar_1(char *temp2, char **result2)
{
	char	*mask;
	int		result;

	*result2 = ft_strnew(1);
	mask = ft_strdup("0xxxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = ft_binary_to_decimal(mask);
	(*result2)[0] = (char)result;
	free(mask);
}

static void	ft_getwchar_2(char *temp2, char **result2)
{
	char	*mask;
	int		result;

	*result2 = ft_strnew(2);
	mask = ft_strdup("110xxxxx10xxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = ft_binary_to_decimal(mask);
	(*result2)[0] = (char)result;
	result = ft_binary_to_decimal(&mask[8]);
	(*result2)[1] = (char)result;
	free(mask);
}

static void	ft_getwchar_3(char *temp2, char **result2)
{
	char	*mask;
	int		result;

	*result2 = ft_strnew(3);
	mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = ft_binary_to_decimal(mask);
	(*result2)[0] = (char)result;
	result = ft_binary_to_decimal(&mask[8]);
	(*result2)[1] = (char)result;
	result = ft_binary_to_decimal(&mask[16]);
	(*result2)[2] = (char)result;
	free(mask);
}

static void	ft_getwchar_4(char *temp2, char **result2)
{
	char	*mask;
	int		result;

	*result2 = ft_strnew(4);
	mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = ft_binary_to_decimal(mask);
	(*result2)[0] = (char)result;
	result = ft_binary_to_decimal(&mask[8]);
	(*result2)[1] = (char)result;
	result = ft_binary_to_decimal(&mask[16]);
	(*result2)[2] = (char)result;
	result = ft_binary_to_decimal(&mask[24]);
	(*result2)[3] = (char)result;
	free(mask);
}

char		*ft_getwchar(int c)
{
	int		length;
	char	*temp2;
	char	*result2;
	char	*temp3;

	temp3 = ft_itoa_base(c, 2);
	temp2 = ft_strdup(temp3);
	free(temp3);
	length = (int)ft_strlen(temp2);
	result2 = NULL;
	if (length <= 7)
		ft_getwchar_1(temp2, &result2);
	else if (length > 7 && length <= 11)
		ft_getwchar_2(temp2, &result2);
	else if (length > 11 && length <= 16)
		ft_getwchar_3(temp2, &result2);
	else if (length > 16 && length <= 21)
		ft_getwchar_4(temp2, &result2);
	free(temp2);
	return (result2);
}
