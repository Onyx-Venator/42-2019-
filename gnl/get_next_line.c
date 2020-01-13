/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2020/01/13 18:14:09 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

char		*ft_substr(char *s, int start)
{
	size_t	i;
	char	*dst;
	size_t	len;

	len = ft_strlen(s) - start;
	start += 1;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		dst[i] = s[start];
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1)
	{
		i = ft_strlen(s2);
		if (!(dst = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = -1;
		while (s2[++i])
			dst[i] = s2[i];
		dst[i] = '\0';
		//free(s2);
		s2 = NULL;
		return (dst);
	}
	else
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(dst = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			dst[i] = s1[i];
		j = -1;
		while (s2[++j])
			dst[++i - 1] = s2[j];
		//free(s2);
		free(s1);
		s2 = NULL;
		s1 = NULL;
		dst[i] = '\0';
		return (dst);
	}
}

int			ft_verif(char *buffer, char c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*save;
	char			*dst;
	int				ret;
	int				i;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[ret] = '\0';
		if ((save = ft_strjoin(save, buffer)) == 0)
			return (-1);
		printf("Save : - %s \n", save);
		if ((i = ft_verif(save, '\n')) != -1)
		{
			if (!(dst = malloc(sizeof(char) * (i + 1))))
				return (-1);
			dst[i] = '\0';
			ret = i;
			while (--i >= 0)
				dst[i] = save[i];
			while (save[ret])
			{
				++ret;
				save[++i] = save[ret];
			}
			save[i] = '\0';
			*line = dst;
			return (1);
		}
	}
	if (save[0] != '\0')
	{
		if ((i = ft_verif(save, '\n')) != -1)
		{
			write(1, "ok\n", 3);
			ret = i;
			if (!(dst = malloc(sizeof(char) * (i + 1))))
				return (-1);
			dst[i] = '\0';
			while (--i >= 0)
				dst[i] = save[i];
			*line = dst;
			while (save[ret])
			{
				++ret;
				save[++i] = save[ret];
			}
			save[i] = '\0';
			return (1);
		}
		i = ft_strlen(save);
		if (!(dst = malloc(sizeof(char) * (i + 1))))
			return (-1);
		dst[i] = '\0';
		while (--i >= 0)
			dst[i] = save[i];
		*line = dst;
		return (0);
	}
	return (0);
}

int	main(int ar, char **av)
{

	int fd = 0;
	int ret = 0;
	int	i = 0;
	char *line;

	line = NULL;
	(void) ar;
	if (av[2]) {
		fd = av[2][0];
	} else {
		fd = open(av[1], O_RDONLY);
	}
	printf("FILE DESCRIPTOR : %d\n---------------------\n", fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d - %d | %s\n", ret, i++, line);
		free(line);
	}
	printf("%d - %d | %s\n", ret, i++, line);
	if (ret <= 0)
		free(line);
	system("leaks a.out");
	return 0;
}

/*printf("Buffer : - %s \n", buffer);
write(1, "ok\n", 3);
printf("tmp Lecture : - %s \n", tmp);*/
//printf("Save : - %s \n", save);
