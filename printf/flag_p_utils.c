/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:48:07 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/24 16:49:04 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			add_zero_p(t_list *stock)
{
	int				y;

	y = stock->conv_len - 2;
	while (y++ < stock->count_precision)
		add_to_buff(stock, '0');
	return ;
}

unsigned long	fact_unsigned(unsigned long y, unsigned long x)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = x;
	if (j == 0)
		i = 1;
	while (j > 0)
	{
		i++;
		j /= y;
	}
	return (i);
}

void			ft_utoa_base_p(unsigned long x, t_list *stock, char *base)
{
	unsigned long	len_base;
	unsigned long	j;
	unsigned long	tmp;

	len_base = ft_strlen(base);
	j = fact_unsigned(len_base, x);
	tmp = j;
	dump_buffer(stock);
	if (j == 0)
	{
		add_to_buff(stock, '0');
		return ;
	}
	while (j-- > 0)
	{
		stock->buffer[stock->coord_buf + j] = base[x % len_base];
		x /= len_base;
	}
	stock->coord_buf += tmp;
	return ;
}

void			add_ox(t_list *stock)
{
	add_to_buff(stock, '0');
	add_to_buff(stock, 'x');
	return ;
}
