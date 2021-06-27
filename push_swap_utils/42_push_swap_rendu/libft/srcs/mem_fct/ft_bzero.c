/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:28:16 by tsantoni          #+#    #+#             */
/*   Updated: 2019/10/16 17:19:09 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			*((char *)(s + i)) = '\0';
			i++;
		}
	}
}