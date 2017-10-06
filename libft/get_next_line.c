/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:30:33 by mdubus            #+#    #+#             */
/*   Updated: 2017/10/06 10:56:47 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static void	mew_lst(t_dlist **mew, int fd)
{
	*mew = (t_dlist *)malloc(sizeof(**mew));
	(*mew)->reste = ft_strnew(0);
	(*mew)->fd = fd;
	(*mew)->next = NULL;
}

static void	multi_fd_gnl(t_dlist **mew, t_dlist **mew2, int fd)
{
	static t_dlist	*begin;

	if (begin)
	{
		*mew = begin;
		while (*mew != NULL)
		{
			if ((*mew)->fd == fd)
				break ;
			*mew2 = *mew;
			*mew = (*mew)->next;
		}
		if (*mew == NULL)
		{
			mew_lst(mew, fd);
			(*mew2)->next = *mew;
		}
	}
	else
	{
		mew_lst(mew, fd);
		begin = *mew;
	}
}

static int	backslash_in_buffer(char *buffer, int length, t_dlist **mew,
		char **line)
{
	char	*temp;
	size_t	n;

	n = 0;
	temp = NULL;
	if (buffer[0] == '\0')
		return (-1);
	buffer[length] = '\0';
	if ((*mew)->reste == NULL)
		(*mew)->reste = ft_strdup("");
	if (ft_strchr(buffer, '\n'))
	{
		n = (size_t)ft_strclen(buffer, '\n');
		buffer[n] = '\0';
		*line = ft_strjoin((*mew)->reste, buffer);
		free((*mew)->reste);
		(*mew)->reste = ft_strdup(&buffer[n + 1]);
		free(buffer);
		return (1);
	}
	temp = (*mew)->reste;
	(*mew)->reste = ft_strjoin((*mew)->reste, buffer);
	free(temp);
	return (0);
}

static int	backslash_in_rest(int fd, char **line, t_dlist **mew, char **buffer)
{
	size_t		n;
	char		*temp;
	t_dlist		*mew2;

	temp = NULL;
	mew2 = NULL;
	*line = NULL;
	multi_fd_gnl(mew, &mew2, fd);
	*buffer = ft_strnew(BUFF_SIZE);
	if ((*mew)->reste && ft_strchr((*mew)->reste, '\n'))
	{
		n = (size_t)ft_strclen((*mew)->reste, '\n');
		(*mew)->reste[n] = '\0';
		*line = ft_strdup((*mew)->reste);
		temp = (*mew)->reste;
		(*mew)->reste = ft_strdup(&(*mew)->reste[n + 1]);
		free(temp);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	t_gnl			gnl;

	gnl.length = 0;
	gnl.ret = -1;
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if ((backslash_in_rest(fd, line, &gnl.mew, &gnl.buffer)) == 1)
		return (1);
	while ((gnl.length = (int)read(fd, gnl.buffer, BUFF_SIZE)) > 0)
	{
		gnl.ret = backslash_in_buffer(gnl.buffer, gnl.length, &gnl.mew, line);
		if (gnl.ret == 1 || gnl.ret == -1)
			return (gnl.ret);
	}
	if (gnl.length < 0 ||
			((gnl.mew->reste && (*line = ft_strdup(gnl.mew->reste)) == NULL)))
		return (-1);
	free(gnl.mew->reste);
	free(gnl.buffer);
	gnl.buffer = NULL;
	gnl.mew->reste = NULL;
	if (gnl.length == 0 && *line && (*line)[0] != '\0')
		return (1);
	return (0);
}
