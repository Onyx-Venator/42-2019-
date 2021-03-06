/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:04:56 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/25 14:37:30 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	precision_u(unsigned int x, t_list *stock)
{
	int			y;

	y = stock->count_precision - stock->conv_len + 1;
	while (--y > 0)
		add_to_buff(stock, '0');
	if (stock->conv_len < stock->count_precision)
		stock->conv_len = stock->count_precision;
	ft_putnbr_u(x, stock);
	return ;
}

void	u_precision(unsigned int x, t_list *stock)
{
	ft_flag_zero(stock);
	if (x == 0 && stock->count_precision <= 0)
	{
		stock->conv_len = 0;
		ft_apply_width(stock);
	}
	else if (stock->count_precision >= stock->count_format)
		precision_u(x, stock);
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
		stock->conv_len = fact_u(x, 10);
		precision_u(x, stock);
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
			ft_apply_width(stock);
	}
	return ;
}

void	u_less_precision(unsigned int x, t_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		ft_putnbr_u(x, stock);
		ft_apply_width(stock);
	}
	else
	{
		if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			ft_apply_width(stock);
			ft_putnbr_u(x, stock);
		}
		else
		{
			ft_apply_width(stock);
			ft_putnbr_u(x, stock);
		}
	}
	return ;
}

void	ft_convert_u(unsigned int x, t_list *stock)
{
	stock->conv_len = fact_u(x, 10);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
		u_precision(x, stock);
	else
		u_less_precision(x, stock);
	return ;
}
