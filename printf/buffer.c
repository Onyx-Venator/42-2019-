/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:05:09 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/24 17:41:41 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	dump_buffer(t_list *stock)
{
	write(1, stock->buffer, stock->coord_buf);
	stock->count_print += stock->coord_buf;
	stock->coord_buf = 0;
	return ;
}

void	add_to_buff(t_list *stock, char c)
{
	stock->buffer[stock->coord_buf] = c;
	stock->coord_buf++;
	if (stock->coord_buf == STOP)
		dump_buffer(stock);
	return ;
}

void	ft_apply_width_percent(t_list *stock)
{
	int		x;

	x = 0;
	if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
	{
		while (++x < (stock->count_format - stock->conv_len))
			add_to_buff(stock, '0');
		add_to_buff(stock, '%');
	}
	else if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_to_buff(stock, '%');
		while (++x < (stock->count_format - stock->conv_len))
			add_to_buff(stock, ' ');
	}
	else
	{
		while (++x < (stock->count_format - stock->conv_len))
			add_to_buff(stock, ' ');
		add_to_buff(stock, '%');
	}
}

void	ft_apply_width(t_list *stock)
{
	int		x;

	x = -1;
	if (stock->count_precision == -1)
		stock->count_precision = 0;
	if ((stock->count_format - stock->conv_len) < 0 || stock->conv_len < 0)
		return ;
	if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
	{
		while (++x < (stock->count_format - stock->conv_len))
			add_to_buff(stock, '0');
	}
	else
	{
		while (++x < (stock->count_format - stock->conv_len))
			add_to_buff(stock, ' ');
	}
	return ;
}
