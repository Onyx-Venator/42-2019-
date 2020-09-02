/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:20:36 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/25 14:12:40 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

int		ft_fd_error(int fd)
{
	if (fd == -1)
	{
		write(0, "can't open the file.\n", 21);
		return (0);
	}
	if (read(fd, 0, 0) == -1)
	{
		write(0, "can't read the file.\n",21);
		return (0);
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (s1)
	{
		i = -1
		while (s1[++i])
			dst[i] = s1[i]
	}
	else
		i = 0;
	j = -1;
	while(s2[++j])
		dst[++i -1] = s2[j];
	if (s1)
		free(s1);
	s2 = NULL;
	s1 = NULL;
	dst[i] = '\0';
	return (dst);
}

int		ft_get_next_line(t_list *parse, char *config)
{
	int		i;
	int		fd;
	char	buffer[1024];

	i = -1;
	fd = open(config, O_RDONLY);
	if (!ft_fd_error(fd))
		return (0);
	while (i = read(fd, buffer, 1023) != 0)
	{
		buffer[i] = '\0';
		if (!ft_strjoin(parse->save, buffer))
			return (-1);
	}
	ft_srjoin(parse->save, buffer);
	return (1);
}
