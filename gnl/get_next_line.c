/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2020/01/16 13:31:27 by cofoundo         ###   ########.fr       */
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
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int			ft_sale(char **line, char *save, int i)
{
	int		j;
	char	*dst;

	if (i != -1 && (j = i) != -1)
	{
		if (!(dst = malloc(sizeof(char) * (i + 1))))
			return (-1);
		dst[i] = '\0';
		while (--i >= 0)
			dst[i] = save[i];
		while (save[j])
			save[++i] = save[++j];
		save[i] = '\0';
		return ((*line = dst) != NULL ? 1 : 1);
	}
	i = ft_strlen(save);
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (-1);
	dst[i] = '\0';
	while (--i >= 0)
		dst[i] = save[i];
	*line = dst;
	return ((save[0] = '\0') ? 0 : 0);
}

int			get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*save[OPEN_MAX];
	int				i;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[i] = '\0';
		if ((save[fd] = ft_strjoin(save[fd], buffer)) == 0)
			return (-1);
		if ((i = ft_verif(save[fd], '\n')) != -1)
			return (ft_sale(line, save[fd], i));
	}
	if (save[fd])
	{
		i = ft_verif(save[fd], '\n');
		return (ft_sale(line, save[fd], i));
	}
	*line = malloc(1);
	return ((save[fd] = NULL) == NULL ? 0 : 0);
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
		printf("%d - %d | %s\n", ret, i, line);
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
/*if ((i = ft_verif(save, '\n')) != -1)
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
}*/
