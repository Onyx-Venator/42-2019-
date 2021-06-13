/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:57:25 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:57:26 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_realloc(char *str, int new_size, int old_size)
{
	char	*new;

	new = NULL;
	if (new_size)
	{
		if (!(new = ft_memalloc(new_size)))
			return (NULL);
	}
	if (str && new)
	{
		ft_memcpy((void *)new, str, (size_t)old_size);
		new[old_size] = '\0';
		ft_strdel(&str);
	}
	new[new_size - 1] = '\0';
	return (new);
}
