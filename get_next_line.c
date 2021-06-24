/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:53:15 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/24 19:05:11 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*buffer[4096];
	int			buf_len;

	if (BUFFER_SIZE < 1 || fd < 0 || !line || !init_memory(fd, buffer, line))
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
	return (builder(fd, line, buffer));
}

char	*head(char **buf)
{
	int		i;
	int		count;
	int		nl_pos;
	char	*res;

	printf("\nINICIO HEAD\n");
	i = 0;
	count = 0;
	printf("\t%s\n", *buf);
	nl_pos = nl_position(*buf);
	if (nl_pos < 0)
		nl_pos = ft_strlen(*buf);
	res = (char *)malloc(sizeof(char) * (nl_pos));
	if (!res)
		return (NULL);
	while (i < nl_pos)
	{
		res[i] = (*buf)[i];
		i++;
	}
	res[i] = 0;
	while ((*buf)[i])
	{
		(*buf)[i - nl_pos] = (*buf)[i + 1];
		i++;
	}
	(*buf)[i - nl_pos] = 0;
	return (res);
}

int		builder(int fd, char **line, char **buf)
{
	int	nl_pos;
	int	buf_len;
	int	flag_nl;

	printf("\nINICIO BUILDER:|%s|\n", buf[fd]);
	flag_nl = 0;
	buf_len = ft_strlen(buf[fd]);
	while (buf_len > 0 )
	{
		if (nl_position(buf[fd]) >= 0)
			flag_nl = 1;
//TODO
		printf("\t%s\n", buf[fd]);
		*line = ft_strjoin(*line, head(&buf[fd]));
		printf("\nFLAGNL%d\n", flag_nl);
		buf_len = ft_strlen(buf[fd]);
		printf("\nBUF[FD]:|%s|%d\n", buf[fd],  flag_nl);
		if (flag_nl == 1)
			return (1);
		if (buf_len == 0)
			buf_len = read(fd, buf[fd], BUFFER_SIZE);
		if (buf_len == 0)
		{
			printf("\nFInAL\n");
			free(*buf);
			*buf = 0;
		   return (0);
		}
		if (buf_len < 0)
			return (-1);	
	}
	return (-1);
}

int		init_memory(int fd, char **buf, char **line)
{
	int	i;

	i = 0;
	printf("\nINIT_MEMORY |%s| |%s|\n", *line, buf[fd]);
	if (!**line)
	{
		printf("\n\tINICIALIZO LINEA\n");
		*line = (char *)malloc(sizeof(char *));
	}
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
