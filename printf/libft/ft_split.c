/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:53:46 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/16 14:40:53 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(char const *s, char c)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	if (s[0] != c)
		j++;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
			if (s[i] != c && s[i])
			{
				j++;
				while (s[i] != c && s[i])
					i++;
			}
		}
		if (s[i])
			i++;
	}
	return (j);
}

static	char	*ft_alloc(char const *s, char c)
{
	char	*dst;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dst[i] = '\0';
	i -= 1;
	while (i >= 0 && s[i] != c)
	{
		dst[i] = s[i];
		i--;
	}
	return (dst);
}

static	char	**ft_end(char **dst, int j)
{
	if (!(dst[j] = malloc(sizeof(char))))
		return (NULL);
	dst[j] = NULL;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**dst;

	if (s)
	{
		i = 0;
		j = -1;
		if (!(dst = malloc(sizeof(char*) * (ft_count(s, c) + 1))))
			return (NULL);
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
			{
				dst[++j] = ft_alloc(&s[i], c);
				while (s[i] && s[i] != c)
					i++;
			}
		}
		return (ft_end(dst, ++j));
	}
	return (NULL);
}
