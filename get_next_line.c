/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:53:15 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/23 22:18:27 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*buffer[4096];
	int			buf_len;

	if (BUFFER_SIZE < 1 || fd < 0 || !line || !init_memory(&buffer[fd], line))
		return (-1);
	buf_len = fill_buffer(fd, buffer[fd]);
	if (buf_len == -1)
	{
		free(*line);
		free(buffer[fd]);
		return (-1);
	}
	if (buf_len == 0)
	{
		free(buffer[fd]);
		return (0);
	}
	printf("\n\tBUFFER:|%s|\n\tLINE:|%s|\n", buffer[fd], *line);
	return (builder(fd, line, &buffer[fd]));
}

char	*head(char *buf)
{
	int		i;
	int		count;
	int		nl_pos;
	char	*res;

	printf("\nHEAD\n");
	i = 0;
	count = 0;
	nl_pos = nl_position(buf);
	res = (char *)malloc(sizeof(char) * (nl_pos + 1));
	if (!res)
		return (NULL);
	while (i < nl_pos)
	{
		res[i] = buf[i];
		i++;
	}
	res[i] = 0;
	while (buf[i])
	{
		buf[i - nl_pos] = buf[i];
		i++;
	}
	buf[i - nl_pos] = 0;
	return (res);
}

int		builder(int fd, char **line, char **buf)
{
	int	nl_pos;
	int	buf_len;
	int	flag_nl;

	flag_nl = 0;
	buf_len = ft_strlen(*buf);
	while (buf_len > 0 )
	{
		if (nl_position(*buf) != ft_strlen(*buf))
			flag_nl = 1;
//TODO
		printf("\nFLAGNL%d\n", flag_nl);
		*line = ft_strjoin(*line, head(buf[fd]));
		printf("\nFLAGNL%d\n", flag_nl);
		buf_len = ft_strlen(*buf);
		if (flag_nl == 1)
			return (1);
		if (buf_len == 0)
			buf_len = read(fd, *buf, BUFFER_SIZE);
		if (buf_len == 0)
		   return (0);
		if (buf_len < 0)
			return (-1);	
	}
	return (-1);
}

int		init_memory(char **buf, char **line)
{
	int	i;

	i = 0;
	if (!*line)
	{
		*line = (char *)malloc(sizeof(char *));
	}
	if (!*line)
	{
		return (0);
	}
	**line = 0;
	if (!*buf)
	{
		*buf = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (!*buf)
		{
			free (*line);
			return (0);
		}
		while (i <= BUFFER_SIZE)
		{
			(*buf)[i] = 0;
			i++;
		}
	}
	return (1);
}

int		fill_buffer(int fd, char *buf)
{
	int	buf_len;

	buf_len = ft_strlen(buf);
	if (buf_len == 0)
		buf_len = read(fd, buf, BUFFER_SIZE);
	if (buf_len == -1)
		return (-1);
	if (buf_len == 0)
		return (0);
	return (buf_len);
}
