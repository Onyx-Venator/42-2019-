/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:10:30 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/23 20:30:33 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		fact_ui(unsigned int x, int y)
{
	unsigned int			i;
	int						j;

	i = x;
	j = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= y;
		j++;
	}
	return (j);
}

void	add_zero_x(t_list *stock)
{
	while (stock->conv_len++ < stock->count_precision)
		add_to_buff(stock, '0');
	stock->conv_len--;
	return ;
}
