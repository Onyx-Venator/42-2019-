/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:05:00 by cofoundo          #+#    #+#             */
/*   Updated: 2019/12/03 18:52:35 by cofoundo         ###   ########.fr       */
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
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	char	*buffer = NULL;
	char			*save;
	char			*tmp;
	size_t		i;
	size_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
		save = NULL;
	if (buffer != NULL)
	{
		i = -1;
		if ((ret = ft_verif(buffer, '\n')) == 0)
		{
			if (!(save = ft_strjoin(0, buffer)))
				return (-1);
		}
		else
		{
			if (!(save = malloc(sizeof(char) * (ret + 1))))
				return (-1);
			while (++i < ret)
				save[i] = buffer[i];
			save[i] = '\0';
			i = 0;
			while (buffer[i + ret])
			{
				buffer[i] = buffer[i + ret];
				i++;
			}
			buffer[i] = '\0';
			*line = save;
			return (1);
		}
	}
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		if (ft_verif(buffer, '\n') != 0)
		{
			if (!(tmp = malloc(sizeof(char) * (ft_verif(buffer, '\n') + 1))))
				return (-1);
			i = -1;
			while (buffer[++i] != '\n')
				tmp[i] = buffer[i];
			tmp[i] = '\0';
			if (*save)
			{
				write(1, "ok\n", 3);
				if ((tmp = ft_strjoin(tmp, save)) == 0)
					return (-1);
			}
			ret = 0;
			while (buffer[++i])
			{
				buffer[ret] = buffer[i];
				ret++;
			}
			buffer[ret] = '\0';
			*line = tmp;
			return (1);
		}
		else
		{
			if (!(save = malloc(sizeof(char) * (ret + 1))))
				return (-1);
			while (ret >= 0)
			{
				save[ret] = buffer[ret];
				ret--;
			}
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
	buffer[count] = '\0';
	count = ft_verif(buffer, '\n');
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
/*printf("Buffer : - %s \n", buffer);
write(1, "ok\n", 3);
printf("tmp Lecture : - %s \n", tmp);*/
