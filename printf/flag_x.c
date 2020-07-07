/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:11:29 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/23 20:32:36 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_utoa_base_x(unsigned int x, t_list *stock, char *base)
{
	unsigned int	len_base;
	unsigned int	j;
	unsigned int	tmp;

	len_base = ft_strlen(base);
	j = fact_ui(x, len_base);
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

void	x_less_precision(unsigned int x, t_list *stock, char *str)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		ft_utoa_base_x(x, stock, str);
		ft_apply_width(stock);
	}
	else
	{
		if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			ft_apply_width(stock);
			ft_utoa_base_x(x, stock, str);
			return ;
		}
		ft_apply_width(stock);
		ft_utoa_base_x(x, stock, str);
	}
	return ;
}

void	x_precision_less_left(unsigned int x, t_list *stock, char *str)
{
	int		y;

	y = stock->conv_len;
	stock->conv_len = stock->count_precision;
	ft_apply_width(stock);
	while (y++ < stock->count_precision)
		add_to_buff(stock, '0');
	ft_utoa_base_p(x, stock, str);
	return ;
}

void	x_with_precision(unsigned int x, t_list *stock, char *str)
{
	if (stock->count_precision >= stock->count_format)
	{
		add_zero_x(stock);
		ft_utoa_base_x(x, stock, str);
	}
	else if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_zero_x(stock);
		ft_utoa_base_x(x, stock, str);
		ft_apply_width(stock);
	}
	else
		x_precision_less_left(x, stock, str);
	return ;
}

void	ft_convert_x(unsigned int x, t_list *stock, char *str)
{
	stock->conv_len = fact_ui(x, 16);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
	{
		ft_flag_zero(stock);
		if (stock->count_precision <= 0 && x == 0)
		{
			stock->conv_len = 0;
			ft_apply_width(stock);
			return ;
		}
		if (stock->conv_len < stock->count_precision)
			x_with_precision(x, stock, str);
		else
			x_less_precision(x, stock, str);
	}
	else
		x_less_precision(x, stock, str);
	return ;
}
