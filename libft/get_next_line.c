/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:55:23 by agrosset          #+#    #+#             */
/*   Updated: 2016/02/22 11:55:44 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_buf(int fd, char *tmp, char buf[256][BUFF_SIZE + 1])
{
	ssize_t	length;

	length = ft_strlen(tmp + 1);
	ft_strncpy(buf[fd], tmp + 1, length);
	ft_bzero(buf[fd] + length, BUFF_SIZE + 1 - length);
	return (1);
}

static int		loop(int const fd, char **line,
		char buf[256][BUFF_SIZE + 1])
{
	char	*tmp;
	ssize_t	length;

	while ((length = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		ft_bzero(buf[fd] + length, BUFF_SIZE + 1 - length);
		tmp = *line;
		if ((*line = ft_strnew((*line != NULL ? ft_strlen(*line) : 0)
						+ length)) == NULL)
			return (-1);
		if (tmp != NULL)
		{
			ft_strncat(*line, tmp, ft_strlen(tmp));
			free(tmp);
		}
		if ((tmp = ft_strchr(buf[fd], '\n')) != NULL)
			length = tmp - buf[fd];
		ft_strncat(*line, buf[fd], length);
		if (tmp)
			return (set_buf(fd, tmp, buf));
	}
	return (length);
}

static int		return_state(int const fd, char buf[256][BUFF_SIZE + 1],
		ssize_t length, char **line)
{
	if (length == -1)
		return (-1);
	if (length == 0)
	{
		ft_bzero(buf[fd], BUFF_SIZE);
		if (*line != NULL)
			return (1);
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		buf[256][BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			length;

	if (fd < 0 || fd > 256 || line == NULL)
		return (-1);
	*line = NULL;
	if ((length = ft_strlen(buf[fd])) != 0)
	{
		if ((tmp = ft_strchr(buf[fd], '\n')) != NULL)
		{
			*line = ft_strnew(tmp - buf[fd]);
			ft_strncat(*line, buf[fd], tmp - buf[fd]);
			length = ft_strlen(tmp + 1);
			ft_strncpy(buf[fd], tmp + 1, length);
			ft_bzero(buf[fd] + length, BUFF_SIZE + 1 - length);
			return (1);
		}
		if ((*line = ft_strnew(length)) == NULL)
			return (-1);
		ft_strncpy(*line, buf[fd], length);
	}
	return (return_state(fd, buf, loop(fd, line, buf), line));
}
