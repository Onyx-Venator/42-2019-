/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:25:36 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/24 17:51:24 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int		fact_u(unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;

	j = x;
	i = 0;
	if (j == 0)
		return (1);
	while (j != 0)
	{
		i++;
		j /= y;
	}
	return (i);
}

void				ft_putnbr_u(unsigned int x, t_list *stock)
{
	char			str[stock->conv_len];
	unsigned int	i;
	int				j;

	i = x;
	j = stock->conv_len;
	if (i == 0)
	{
		add_to_buff(stock, '0');
		return ;
	}
	while (i != 0)
	{
		str[j--] = i % 10 + '0';
		i /= 10;
	}
	while (j < stock->conv_len)
	{
		++j;
		add_to_buff(stock, str[j]);
	}
	return ;
}
