/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:31:06 by tsantoni          #+#    #+#             */
/*   Updated: 2021/04/28 12:46:40 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	if (!(cpy = malloc(sizeof(s1) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = s1[i];
	return (cpy);
}
