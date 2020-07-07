/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:50:10 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/24 16:53:03 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	precision_neg_p(t_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_ox(stock);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		add_ox(stock);
	}
	return ;
}

void	p_less_precision(unsigned long x, t_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_ox(stock);
		ft_utoa_base_p(x, stock, "0123456789abcdef");
		ft_apply_width(stock);
	}
	else
	{
		if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			add_ox(stock);
			ft_apply_width(stock);
			ft_utoa_base_p(x, stock, "0123456789abcdef");
			return ;
		}
		ft_apply_width(stock);
		add_ox(stock);
		ft_utoa_base_p(x, stock, "0123456789abcdef");
	}
	return ;
}

void	p_precision_less_left(unsigned long x, t_list *stock)
{
	if (stock->conv_len < stock->count_precision)
		stock->conv_len = stock->count_precision;
	ft_apply_width(stock);
	add_ox(stock);
	add_zero_p(stock);
	ft_utoa_base_p(x, stock, "0123456789abcdef");
}

void	p_with_precision(unsigned long x, t_list *stock)
{
	if (stock->count_precision >= stock->count_format)
	{
		add_ox(stock);
		add_zero_p(stock);
		ft_utoa_base_p(x, stock, "0123456789abcdef");
	}
	else
	{
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
		{
			add_ox(stock);
			add_zero_p(stock);
			ft_utoa_base_p(x, stock, "0123456789abcdef");
			ft_apply_width(stock);
		}
		else
			p_precision_less_left(x, stock);
	}
	return ;
}

void	ft_convert_p(unsigned long x, t_list *stock)
{
	stock->conv_len = fact_unsigned(16, x) + 2;
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
	{
		if (x == 0 && stock->count_precision < 0)
			stock->conv_len--;
		if (x == 0 && stock->count_precision <= 0)
		{
			precision_neg_p(stock);
			return ;
		}
		ft_flag_zero(stock);
		if (stock->conv_len < stock->count_precision)
			p_with_precision(x, stock);
		else
			p_less_precision(x, stock);
	}
	else
		p_less_precision(x, stock);
	return ;
}
