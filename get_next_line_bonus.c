/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:53:15 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/29 21:33:20 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static char	*buffer[256];
	int			buf_len;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 256 || !line)
		return (-1);
	if (!ft_init_memory(fd, buffer, line))
		return (-1);
	buf_len = ft_fill_buffer(fd, buffer[fd]);
	if (buf_len == -1)
	{
		free(buffer[fd]);
		return (-1);
	}
	if (buf_len == 0)
	{
		free(buffer[fd]);
		buffer[fd] = 0;
		return (0);
	}
	return (ft_builder(fd, line, buffer));
}

char	*ft_head(char **buf)
{
	int		i;
	int		count;
	int		nl_pos;
	char	*res;

	i = -1;
	count = 0;
	nl_pos = ft_nl_position(*buf);
	if (nl_pos < 0)
		nl_pos = ft_strlen(*buf);
	res = (char *)malloc(sizeof(char) * (nl_pos + 1));
	if (!res)
		return (NULL);
	while (++i < nl_pos)
		res[i] = (*buf)[i];
	res[i] = 0;
	while ((*buf)[i])
	{
		(*buf)[i - nl_pos] = (*buf)[i + 1];
		i++;
	}
	(*buf)[i - nl_pos] = 0;
	return (res);
}

int	ft_builder(int fd, char **line, char **buf)
{
	int	buf_len;
	int	flag_nl;

	flag_nl = 0;
	buf_len = ft_strlen(buf[fd]);
	while (buf_len > 0 )
	{
		if (ft_nl_position(buf[fd]) >= 0)
			flag_nl = 1;
		*line = ft_strjoin_gnl(*line, ft_head(&buf[fd]));
		buf_len = ft_strlen(buf[fd]);
		if (flag_nl == 1)
			return (1);
		buf_len = read(fd, buf[fd], BUFFER_SIZE);
		if (buf_len <= 0)
		{
			free(buf[fd]);
			buf[fd] = 0;
			if (buf_len < 0)
				return (-1);
			return (0);
		}
		buf[fd][buf_len] = 0;
	}
	return (-1);
}

int	ft_init_memory(int fd, char **buf, char **line)
{
	int	i;

	i = 0;
	*line = (char *)malloc(sizeof(char *));
	if (!*line)
	{
		return (0);
	}
	**line = 0;
	if (!buf[fd])
	{
		buf[fd] = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (!buf[fd])
		{
			free (*line);
			return (0);
		}
		while (i <= BUFFER_SIZE)
		{
			buf[fd][i] = 0;
			i++;
		}
	}
	return (1);
}

int	ft_fill_buffer(int fd, char *buf)
{
	int	buf_len;

	buf_len = ft_strlen(buf);
	if (buf_len == 0)
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len < 0)
			return (-1);
		buf[buf_len] = 0;
	}
	if (buf_len == 0)
		return (0);
	return (buf_len);
}
