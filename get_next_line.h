/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:44:06 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/29 20:56:32 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_head(char **buf);
int		ft_builder(int fd, char **line, char **buf);
int		ft_init_memory(int fd, char **buf, char **line);
int		ft_fill_buffer(int fd, char *buf);
int		ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_nl_position(char *str);
#endif
