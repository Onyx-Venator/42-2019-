/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:27:57 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/22 14:01:53 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	write_s(t_list *stock, int x, char *s)
{
	if (s != NULL)
	{
		while (++x < stock->conv_len)
			add_to_buff(stock, s[x]);
	}
	else
	{
		while (++x < stock->conv_len)
			;
		dump_buffer(stock);
		write(1, "(null)", x);
		stock->count_print += x;
	}
	return ;
}

void	add_s(t_list *stock, int x, char *s)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		write_s(stock, x, s);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		write_s(stock, x, s);
	}
	return ;
}

void	add_precision_s(t_list *stock, int x, char *s)
{
	if (stock->count_precision == -1)
		stock->count_precision = 0;
	stock->conv_len = stock->count_precision;
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		write_s(stock, x, s);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		write_s(stock, x, s);
	}
	return ;
}

void	ft_convert_s(char *s, t_list *stock)
{
	int		x;

	x = -1;
	if (s != NULL)
		stock->conv_len = ft_strlen(s);
	else
		stock->conv_len = 6;
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
	{
		if (stock->conv_len >= stock->count_precision)
			add_precision_s(stock, x, s);
		else
			add_s(stock, x, s);
	}
	else
		add_s(stock, x, s);
	return ;
}
