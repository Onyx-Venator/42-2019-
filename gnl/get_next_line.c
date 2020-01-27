/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2020/01/27 18:46:53 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

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

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i])
			dst[i] = s1[i];
	}
	else
		i = 0;
	j = -1;
	while (s2[++j])
		dst[++i - 1] = s2[j];
	if (s1)
		free(s1);
	s2 = NULL;
	s1 = NULL;
	dst[i] = '\0';
	return (dst);
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
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_eof(char *save, char **line)
{
	int	i;

	i = ft_strlen(save);
	if (!(*line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	(*line)[i] = '\0';
	while (--i >= 0)
		(*line)[i] = save[i];
	return (*line);
}

char	*ft_line(char *save, char **line, int i)
{
	int	j;

	j = i;
	if (!(*line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	(*line)[i] = '\0';
	while (--i >= 0)
		(*line)[i] = save[i];
	while (save[j])
		save[++i] = save[++j];
	save[i] = '\0';
	return (*line);
}

int			get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*save = NULL;
	int				i;
	int				j;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || !line || fd < 0)
		return (-1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[i] = '\0';
		if (!(save = ft_strjoin(save, buffer)))
			return (-1);
		if ((i = ft_verif(save, '\n')) != -1)
		{
			j = i;
			if (!(*line = malloc(sizeof(char) * (j + 1))))
				return (-1);
			(*line)[i] = '\0';
			while (--i >= 0)
				(*line)[i] = save[i];
			while (save[j])
				save[++i] = save[++j];
			save[i] = '\0';
			return (1);
		}
	}
	while ((i = ft_verif(save, '\n')) != -1 && save)
	{
		if (!(*line = ft_line(save, line, i)))
			return (-1);
		return (1);
	}
	if (!(*line = ft_eof(save, line)))
		return (-1);
	free(save);
	save = NULL;
	return (0);
}

int	main(int ar, char **av)
{
	int fd = 0;
	int ret = 0;
	char *line;

	line = NULL;
	int 	i2;

	i2 = 0;
	if (ar == 1)
	{
		while ((ret = get_next_line(0, &line)) > 0)
		{
			printf("%d - %d | %s\n", ret, i2, line);
			free(line);
			line = NULL;
		}
		printf("%d - %d | %s\n", ret, i2++, line);
		if (ret <= 0)
		{
			free(line);
			line = NULL;
		}
		return (0);
	}
	for (int i = 1; i < ar; i++)
	{
		fd = open(av[i], O_RDONLY);
			//continue ;
		printf("FILE DESCRIPTOR : %d\n---------------------\n", fd);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d - %d | %s\n", ret, i, line);
			free(line);
			line = NULL;
		}
		printf("%d - %d | %s\n", ret, i++, line);
		if (ret <= 0)
		{
			free(line);
			line = NULL;
		}
		close(fd);
	}
	//system("leaks a.out");
	return 0;
}

/*printf("Buffer : - %s \n", buffer);
write(1, "ok\n", 3);
printf("tmp Lecture : - %s \n", tmp);*/
//printf("Save : - %s \n", save);
