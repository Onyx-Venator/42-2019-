/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:57:13 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:57:14 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(int size)
{
	char	*new;

	if (!(new = malloc(size)))
		return (NULL);
	while (size > 0)
		new[--size] = '\0';
	return (new);
}
