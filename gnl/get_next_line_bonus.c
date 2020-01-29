/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:37:52 by cofoundo          #+#    #+#             */
/*   Updated: 2020/01/28 16:35:27 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*save[OPEN_MAX];
	int				i;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || !line || fd < 0)
		return (-1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[i] = '\0';
		if (!(save[fd] = ft_strjoin(save[fd], buffer)))
			return (-1);
		if ((i = ft_verif(save[fd], '\n')) != -1)
			return ((*line = ft_line(save[fd], line, i)) ? 1 : -1);
	}
	while ((i = ft_verif(save[fd], '\n')) != -1 && save[fd])
		return ((*line = ft_line(save[fd], line, i)) ? 1 : -1);
	if (!(*line = ft_eof(save[fd], line)))
		return (-1);
	free(save[fd]);
	save[fd] = NULL;
	return (0);
}
