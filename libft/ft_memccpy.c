/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:08:09 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/10 16:57:46 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dest;
	const	char	*srcs;

	dest = dst;
	srcs = src;
	while (0 < n--)
		if ((*dest++ = *srcs++) == (char)c)
			return (dest);
	return (NULL);
}
