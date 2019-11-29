/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/29 17:51:08 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char		*ft_substr(char *s, int start)
{
	size_t	i;
	char	*dst;
	size_t	len;

	i = ft_strlen(s) - start;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	len = i;
	i = -1;
	while (++i < len)
		dst[i] = s[start++];
	dst[i] = '\0';
	return (dst);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[++i - 1] = s2[j];
	free(s1);
	dst[i] = '\0';
	return (dst);
}

int			ft_verif(char *buffer, int i)
{
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	char	*buffer;
	char			tmp[BUFFER_SIZE + 1];
	char			*dst;
	int				count;
	size_t			i;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, tmp, BUFFER_SIZE) == -1)
		return (-1);
	i = 0;
	while ((count = read(fd, tmp, BUFFER_SIZE)))
	{
		tmp[count] = '\0';
		if ((buffer = ft_strjoin(buffer, tmp)) == NULL)
			return (-1);
		count = ft_verif(buffer, 0);
		if (!(dst = malloc(sizeof(char) * (count + 1))))
			return (-1);
		while ((++i - 1) <= count && buffer[i - 1] != '\n')
			dst[i - 1] = buffer[i - 1];
		dst[i - 1] = '\0';
		*line = dst;
		buffer = ft_substr(buffer, count);
		return (1);
	}
	return (0);
}
