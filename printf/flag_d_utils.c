/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:55:52 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/16 19:27:24 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		fact(int x, int y)
{
	int		i;
	int		j;

	j = x;
	i = 0;
	if (j == 0)
		return (1);
	if (j < 0)
		i++;
	while (j != 0)
	{
		i++;
		j /= y;
	}
	return (i);
}

void	ft_putnbr(int x, t_list *stock)
{
	char		str[stock->conv_len];
	long		i;
	int			j;

	i = x;
	j = stock->conv_len - 1;
	if (i < 0)
	{
		str[0] = '-';
		i -= 1;
	}
	while (i != 0)
	{
		str[j--] = i % 10;
		i /= 10;
	}
	while (j < stock->conv_len)
	{
		add_to_buff(stock, str[j]);
		j++;
	}
	return ;
}
