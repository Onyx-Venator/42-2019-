/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:56:43 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/25 14:37:10 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	precision_d(int x, t_list *stock)
{
	int			y;

	y = stock->count_precision - stock->conv_len + 1;
	if (x < 0)
	{
		add_to_buff(stock, '-');
		y++;
	}
	while (--y > 0)
		add_to_buff(stock, '0');
	if (stock->conv_len <= stock->count_precision)
	{
		stock->conv_len = stock->count_precision;
		if (x < 0)
			stock->conv_len++;
	}
	ft_putnbr(x, stock);
	return ;
}

void	d_precision(int x, t_list *stock)
{
	ft_flag_zero(stock);
	if (x == 0 && stock->count_precision <= 0)
	{
		stock->conv_len = 0;
		ft_apply_width(stock);
	}
	else if (stock->count_precision >= stock->count_format)
		precision_d(x, stock);
	else
	{
		if (stock->conv_len <= stock->count_precision)
		{
			stock->conv_len = stock->count_precision;
			if (x < 0)
				stock->conv_len++;
		}
		if ((stock->bin & TYPE_LEFT) != TYPE_LEFT)
			ft_apply_width(stock);
		stock->conv_len = fact(x, 10);
		precision_d(x, stock);
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
			ft_apply_width(stock);
	}
	return ;
}

void	d_less_precision(int x, t_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		if (x < 0)
			add_to_buff(stock, '-');
		ft_putnbr(x, stock);
		ft_apply_width(stock);
	}
	else
	{
		if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			if (x < 0)
				add_to_buff(stock, '-');
			ft_apply_width(stock);
			ft_putnbr(x, stock);
		}
		else
		{
			ft_apply_width(stock);
			if (x < 0)
				add_to_buff(stock, '-');
			ft_putnbr(x, stock);
		}
	}
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
