/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:07:23 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/11 19:52:42 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_charset(char const *s2, char c)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		max;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	max = ft_strlen(s1);
	while (ft_charset(s2, s1[i]) && s1[i])
		i++;
	while (ft_charset(s2, s1[max - 1]) && i <= max)
		max--;
	if (!(dst = malloc(sizeof(char) * (max - i + 1))))
		return (NULL);
	while (i < max)
		dst[j++] = s1[i++];
	dst[j] = '\0';
	return (dst);
}
