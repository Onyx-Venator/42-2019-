/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:40:32 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/14 18:05:34 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	const	char	*srcs;
	char			tmp;

	dest = dst;
	srcs = src;
	if (!len && src)
		return (dst);
	if (dest < srcs)
		return (ft_memcpy(dst, src, len));
	while (0 < len-- && dst)
	{
		tmp = srcs[len];
		dest[len] = tmp;
	}
	return (dst);
}
