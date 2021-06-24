/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:52:22 by alemarti          #+#    #+#             */
/*   Updated: 2021/06/24 18:57:24 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	printf("\n\tINICIO STRLEN:|%s|\n", s);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	printf("\n\tINICIO JOIN(1):|%s|+|%s|\n", s1, s2);
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (0);
	i = -1;
	j = 0;
	printf("\nBUG\n");
	while (s1[++i])
		res[i] = s1[i];
	printf("\n|%s|\n", s1);
	free(s1);
	s1 = 0;
	printf("\n|%s|\n", s1);
	j = i ;
	i = -1;
	while (s2[++i])
		res[j + i] = s2[i];
	free(s2);
	s2 = 0;
	res[j + i] = 0;
	printf("\n\tFIN JOIN(1):|%s|+|%s| = |%s|\n", s1, s2, res);
	return (res);
}

int		nl_position(char *str)
{
	int	i;

	i = 0;
	printf("\nINICIO NL_POSITION:|%s|\n", str);
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
