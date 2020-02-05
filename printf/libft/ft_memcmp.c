/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:35:18 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/11 13:32:03 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*s1_;
	unsigned	char	*s2_;
	size_t				i;

	s1_ = (unsigned char *)s1;
	s2_ = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
	return (0);
}
