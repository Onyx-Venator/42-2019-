/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:07:23 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/13 17:01:28 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (needle[j] && h[i + j] == needle[j] && (j + i) < len)
		{
			j++;
			if ((i + j) == len && needle[j] != 0)
				return (NULL);
		}
		if (j == len || needle[j] == '\0')
			return ((char*)&h[i]);
		i++;
	}
	if (needle[0] != '\0')
		return (0);
	return ((char*)h);
}
