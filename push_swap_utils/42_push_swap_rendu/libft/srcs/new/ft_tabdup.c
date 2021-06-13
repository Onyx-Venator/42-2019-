/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:16 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:17 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **t)
{
	char	**new;
	int		i;

	i = 0;
	if (t == NULL)
		return (NULL);
	while (t[i])
		i++;
	if (!(new = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (t[i])
	{
		if (!(new[i] = malloc(sizeof(char) * (ft_strlen(t[i]) + 1))))
			return (NULL);
		new[i] = ft_strcpy(new[i], t[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
