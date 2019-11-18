/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:50:35 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/13 16:38:56 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const	char	*s_;

	s_ = (char *)s;
	i = -1;
	while (++i < n)
		if (s_[i] == c)
			return ((void*)&s_[i]);
	return (NULL);
}
