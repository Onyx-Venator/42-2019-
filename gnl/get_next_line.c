/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/27 19:47:34 by cofoundo         ###   ########.fr       */
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

char	*ft_substr(char *s, int start)
{
	size_t	i;
	char	*dst;

	i = ft_strlen(s) - start;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s[start++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s2)
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
	free(s1);
	dst[i] = '\0';
	return (dst);
}

int		get_next_line(int fd, char **line)
{
	static	char	buffer[BUFFER_SIZE] =  NULL;
	char			*tmp;
	int				count;
	size_t			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!buffer)
	{
		if (!(tmp = malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
		tmp[0] = 0;
		while (tmp[i] != '\n')
		{
			i = 0;
			if ((count = read(fd, tmp, BUFFER_SIZE)) == -1)
				return (-1);
			if (count == 0 && tmp[0] == NULL)
				return (0);
			if ((buffer = ft_strjoin(buffer, tmp)) == NULL)
				return (-1);
			while (i <= count && tmp[i] != '\n')
				i++;
			if (tmp[i] != '\n')
			{
				free(tmp);
				if (!(tmp = malloc(sizeof(char) * BUFFER_SIZE)))
					return (-1);
			}
		}
		free(tmp);
		count = 0;
		i = 0;
		while (buffer[i] != '\n')
		{
			i++;
			count++;
		}
		i = 0;
		if (!(tmp = malloc(sizeof(char) * (count + 1))))
			return (-1);
		while (i <= count && buffer != '\n')
		{
			tmp[i++] = buffer;
			buffer++;
		}
		tmp[i] = '\0';
		*line = tmp;
		buffer = ft_substr(buffer, count);
		return (1);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		if (!(tmp = malloc(sizeof(char) * i))
			return (-1);
		i = 0;
		while (buffer[i] != '\n')
		{
			tmp[i] = buffer[i];
			i++;
		}
		tmp[i] = '\0';
		return (1);
	}
	else
		{
			if (!(tmp = malloc(sizeof(char) * BUFFER_SIZE)))
				return (-1);
			tmp[0] = 0;
			while (tmp[i] != '\n')
			{
				i = 0;
				if ((count = read(fd, tmp, BUFFER_SIZE)) == -1)
					return (-1);
				if (count == 0 && tmp[0] == NULL)
					return (0);
				if ((buffer = ft_strjoin(buffer, tmp)) == NULL)
					return (-1);
				while (i <= count && tmp[i] != '\n')
					i++;
				if (tmp[i] != '\n')
				{
					free(tmp);
					if (!(tmp = malloc(sizeof(char) * BUFFER_SIZE)))
						return (-1);
				}
			}
			free(tmp);
			count = 0;
			i = 0;
			while (buffer[i] != '\n')
			{
				i++;
				count++;
			}
			i = 0;
			if (!(tmp = malloc(sizeof(char) * (count + 1))))
				return (-1);
			while (i <= count && buffer != '\n')
			{
				tmp[i++] = buffer;
				buffer++;
			}
			tmp[i] = '\0';
			*line = tmp;
			buffer = ft_substr(buffer, count);
			return (1);
		}
}
