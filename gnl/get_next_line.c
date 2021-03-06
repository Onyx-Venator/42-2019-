/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:37:52 by cofoundo          #+#    #+#             */
/*   Updated: 2020/01/28 15:39:25 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static	char	*save = NULL;
	int				i;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || !line || fd < 0)
		return (-1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[i] = '\0';
		if (!(save = ft_strjoin(save, buffer)))
			return (-1);
		if ((i = ft_verif(save, '\n')) != -1)
			return ((*line = ft_line(save, line, i)) ? 1 : -1);
	}
	while ((i = ft_verif(save, '\n')) != -1 && save)
		return ((*line = ft_line(save, line, i)) ? 1 : -1);
	if (!(*line = ft_eof(save, line)))
		return (-1);
	free(save);
	save = NULL;
	return (0);
}
