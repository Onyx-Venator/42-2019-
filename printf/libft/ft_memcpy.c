/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:01:17 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/10 16:47:08 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dest;
	const	char	*srcs;
	int				i;

	dest = dst;
	srcs = src;
	i = 0;
	if (dst == src)
		return (dst);
	while (0 < n--)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dst);
}
