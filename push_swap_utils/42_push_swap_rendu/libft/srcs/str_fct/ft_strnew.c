/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:59:04 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:59:06 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(int i)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_bzero(str, i + 1);
	return (str);
}
