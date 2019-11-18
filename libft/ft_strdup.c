/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:03:37 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/11 13:44:27 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dst[i] = 0;
	while (j < i)
	{
		dst[j] = s1[j];
		j++;
	}
	return (dst);
}
