/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/30 20:14:45 by cofoundo         ###   ########.fr       */
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
		free(s2);
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
		free(s2);
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
			return (i);
		i++;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	char	*buffer = NULL;
	size_t		i;
	size_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	if (*buffer)
	{
		i = -1;
		if ((ret = ft_verif(buffer, '\n')) == 0)
		{
			if (!(*line = ft_strjoin(*line, buffer)))
				return (-1);
			free(buffer);
			buffer = NULL;

		}
		else
		{
			if (!(*line = malloc(sizeof(char) * (ret + 1))))
				return (-1);
			while (++i < ret)
				*line[i] = buffer[i];
			*line[i] = '\0';
			i = 1;
			while (buffer[i + ret])
			{
				buffer[i] = buffer[i + ret];
				i++;
			}
			buffer[i] = '\0';
			return (1);
		}
	}
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		i = -1;
		buffer[ret] = '\0';
		if ((ret = ft_verif(buffer, '\n')) == 0)
		{
			if (!(*line = ft_strjoin(*line, buffer)))
                                return (-1);
                        free(buffer);
                        buffer = NULL;
		}
		else
		{
			if (!(*line = malloc(sizeof(char) * (ret + 1))))
				return (-1);
                        while (++i < ret)
                                *line[i] = buffer[i];
                        *line[i] = '\0';
                        i = 1;
                        while (buffer[i + ret])
                        {
                                buffer[i] = buffer[i + ret];
                                i++;
                        }
                        buffer[i] = '\0';
                        return (1);
		}
	}
	*line = buffer;
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

/*if (buffer[0] != '\0' && BUFFER_SIZE > 1)
{
	if ((count = ft_verif(buffer, '\n')))
	{
		while ((++i) < count && buffer[i] != '\n')
			*line[i] = buffer[i];
		*line[i] = '\0';
		if (!(dst = ft_substr(buffer, count)))
			return (-1);
		return (1);
	}
	save = ft_strjoin(buffer, save);
}
while ((count = read(fd, buffer, BUFFER_SIZE)))
{
	count = ft_verif(buffer, '\n');
	buffer[count] = '\0';
	if (count != 0)
	{
		while (++i < count)
			save[i] =  buffer[i];
		save[i] = '\0';
		*line = save;
		buffer = ft_substr(buffer, count);
		return (1);
	}
	save = ft_strjoin(buffer, save);
	if (count == -1)
		return (-1);
	tmp[count] = '\0';
	if (!(buffer = ft_strjoin(buffer, dst)))
		return (-1);
	if (!(buffer = ft_strjoin(buffer, tmp)))
		return (-1);
} *line = save;*/
