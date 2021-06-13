/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:58:53 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:58:54 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, size_t maxlen)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	len = len > maxlen ? maxlen : len;
	if (!(cpy = malloc(sizeof(s1) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
