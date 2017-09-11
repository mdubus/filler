/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:26:04 by mdubus            #+#    #+#             */
/*   Updated: 2017/01/12 14:49:46 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_put_in_mask(char **mask3, char *temp2)
{
	int		i;
	int		j;

	i = (int)ft_strlen(*mask3);
	j = (int)ft_strlen(temp2) - 1;
	while (i > 0)
	{
		if ((*mask3)[i] == 'x' && j >= 0)
			(*mask3)[i--] = temp2[j--];
		else
			i--;
	}
}

void	ft_putwchar_2(char *temp2)
{
	char	*mask;
	char	result;

	mask = ft_strdup("110xxxxx10xxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = (char)ft_binary_to_decimal(mask);
	ft_putchar(result);
	result = (char)ft_binary_to_decimal(&mask[8]);
	ft_putchar(result);
}

void	ft_putwchar_3(char *temp2)
{
	char	*mask;
	char	result;

	mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = (char)ft_binary_to_decimal(mask);
	ft_putchar(result);
	result = (char)ft_binary_to_decimal(&mask[8]);
	ft_putchar(result);
	result = (char)ft_binary_to_decimal(&mask[16]);
	ft_putchar(result);
}

void	ft_putwchar_4(char *temp2)
{
	char	*mask;
	char	result;

	mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	ft_put_in_mask(&mask, temp2);
	ft_replace_char_with_char_in_str(&mask, 'x', '0');
	result = (char)ft_binary_to_decimal(mask);
	ft_putchar(result);
	result = (char)ft_binary_to_decimal(&mask[8]);
	ft_putchar(result);
	result = (char)ft_binary_to_decimal(&mask[16]);
	ft_putchar(result);
	result = (char)ft_binary_to_decimal(&mask[24]);
	ft_putchar(result);
}

void	ft_putwchar(wchar_t c)
{
	size_t	length;
	char	*temp2;

	temp2 = ft_strdup(ft_itoa_base(c, 2));
	length = ft_strlen(temp2);
	if (length <= 7)
		ft_putchar((char)c);
	else if (length > 7 && length <= 11)
		ft_putwchar_2(temp2);
	else if (length > 11 && length <= 16)
		ft_putwchar_3(temp2);
	else if (length > 16 && length <= 21)
		ft_putwchar_4(temp2);
}
