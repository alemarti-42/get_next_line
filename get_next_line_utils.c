/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:52:22 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/29 18:51:01 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
 * this strjoin frees both string before returning.
 */
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		res[i] = s1[i];
	if (s1)
		free(s1);
	s1 = 0;
	j = i ;
	i = -1;
	while (s2[++i])
		res[j + i] = s2[i];
	if (s2)
		free(s2);
	s2 = 0;
	res[j + i] = 0;
	return (res);
}

/*
 * ft_nl_position return the position of the first newline if any, -1 otherwise
 */
int	ft_nl_position(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
