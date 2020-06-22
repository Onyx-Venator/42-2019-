/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:07:03 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/16 19:30:00 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_strlen(char *s)
{
	int		x;

	x = -1;
	while (s[++x] && s)
		;
	return (x);
}

int	ft_verif(const char *s, char c, t_list *stock)
{
	if (s[stock->coord_s] == c)
		return (-1);
	return (0);
}
