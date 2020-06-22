/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:56:43 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/16 19:27:39 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	precision_d(int x, t_list *stock)
{
	int			y;

	y = stock->count_precision - stock->conv_len + 1;
	while (--y > 0)
		add_to_buff(stock, '0');
	ft_putnbr(x, stock);
	return ;
}

void	format_d(t_list *stock)
{
	int			x;

	if (stock->count_precision > stock->conv_len)
		x = stock->count_format - stock->count_precision + 1;
	else
		x = stock->count_format - stock->conv_len + 1;
	while (--x > 0)
		add_to_buff(stock, ' ');
	return ;
}

void	d_precision(int x, t_list *stock)
{
	ft_flag_zero(stock);
	if (x == 0 && stock->count_precision <= 0)
	{
		format_d(stock);
		return ;
	}
	if (stock->count_precision >= stock->count_format ||
		stock->conv_len >= stock->count_format)
		precision_d(x, stock);
	else
	{
		if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
			format_d(stock);
		precision_d(x, stock);
		ft_putnbr(x, stock);
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
			format_d(stock);
	}
	return ;
}

void	d_less_precision(int x, t_list *stock)
{
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
		format_d(stock);
	ft_putnbr(x, stock);
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
		format_d(stock);
	return ;
}

void	ft_convert_d(int x, t_list *stock)
{
	stock->conv_len = fact(x, 10);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
		d_precision(x, stock);
	else
		d_less_precision(x, stock);
	return ;
}
