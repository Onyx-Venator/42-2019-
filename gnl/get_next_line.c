/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/26 20:39:10 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (i +1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[++i - 1] = s2[j];
	free(s2);
	free(s1);
	dst[i] = '\0';
	return (dst);
}
//faire une structure
int		get_next_line(int fd, char **line)
{
	static	char	BUFFER[OPEN_MAX][BUFFER_SIZE];
	char			*tmp;
	int				count;

	count = 0;
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!BUFFER)
	{
		if ((read(fd, BUFFER[0], BUFFER_SIZE)) == -1)
			return (-1);
		mv = 0;
		while (mv <= BUFFER_SIZE)
		{
			while (BUFFER[0][mv] != )
		}
	}
	else
	{
		//reinitialiser le mv avant le return si mv<BUFFER_SIZE
	}
}
