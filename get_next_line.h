/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:44:06 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/28 15:36:03 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

int		get_next_line(int fd, char **line);
char	*head(char **buf);
int		builder(int fd, char **line, char **buf);
int		init_memory(int fd, char **buf, char **line);
int		fill_buffer(int fd, char *buf);
int		ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		nl_position(char *str);
#endif
