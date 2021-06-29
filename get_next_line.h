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

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_nl_position(char *str);
#endif
