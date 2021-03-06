/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:58:13 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:58:16 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
