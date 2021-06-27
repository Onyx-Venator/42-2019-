/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:02 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:03 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_tab(char ***t)
{
	int	i;

	i = 0;
	while ((*t) && (*t)[i])
	{
		free((*t)[i]);
		(*t)[i] = NULL;
		i++;
	}
	free(*t);
	(*t) = NULL;
	return (1);
}