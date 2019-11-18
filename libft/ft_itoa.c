/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:51:56 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/14 19:55:02 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_zero(long x)
{
	char	*tab;

	if (x == 0)
	{
		if (!(tab = malloc(sizeof(char) * 2)))
			return (NULL);
		tab[0] = '0';
		tab[1] = '\0';
		return (tab);
	}
	return (NULL);
}

static	int		ft_fact(long x)
{
	long	j;
	int		i;

	j = x;
	i = 0;
	while (j != 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

static	char	*ft_alloc(int i, int n)
{
	char	*dst;

	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dst[i] = '\0';
	if (n < 0)
		dst[0] = '-';
	return (dst);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		i;
	long	x;

	x = n;
	i = ft_fact(x);
	if (!ft_zero(x))
	{
		if (x < 0)
		{
			i++;
			x *= -1;
		}
		if (!(dst = ft_alloc(i, n)))
			return (NULL);
		while (x)
		{
			i--;
			dst[i] = x % 10 + '0';
			x /= 10;
		}
		return (dst);
	}
	return (ft_zero(x));
}
