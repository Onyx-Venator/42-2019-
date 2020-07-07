/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:22:54 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/24 17:53:01 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_verif_convert(const char *s, t_list *stock)
{
	if (s[stock->coord_s] == 'c')
		return (stock->bin |= 1);
	if (s[stock->coord_s] == 's')
		return (stock->bin |= 1 << 1);
	if (s[stock->coord_s] == 'p')
		return (stock->bin |= 1 << 2);
	if (s[stock->coord_s] == 'd')
		return (stock->bin |= 1 << 3);
	if (s[stock->coord_s] == 'i')
		return (stock->bin |= 1 << 4);
	if (s[stock->coord_s] == 'u')
		return (stock->bin |= 1 << 5);
	if (s[stock->coord_s] == 'x')
		return (stock->bin |= 1 << 6);
	if (s[stock->coord_s] == 'X')
		return (stock->bin |= 1 << 7);
	return (-1);
}

void	wildcard(int x, t_list *stock, char const *s)
{
	if (s[stock->coord_s - 1] == '.')
	{
		stock->bin &= ~(1 << 8);
		stock->count_precision = x;
		if (x < 0)
			stock->bin &= ~(1 << 11);
		else if (x < 0)
		{
			stock->count_precision *= -1;
			stock->bin &= ~(1 << 8);
		}
	}
	else
	{
		stock->count_format = x;
		if (x < 0)
		{
			stock->count_format *= -1;
			stock->bin |= 1 << 9;
			stock->bin &= ~(1 << 10);
		}
	}
	return ;
}

void	ft_count(const char *s, t_list *stock)
{
	if (s[stock->coord_s - 1] == '-' || s[stock->coord_s - 1] == '0')
	{
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT &&
			(stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			stock->bin &= ~(1 << 10);
			count_format(s, stock);
			return ;
		}
		count_format(s, stock);
	}
	else if (s[stock->coord_s - 1] == '.')
		count_precision(s, stock);
	else if (s[stock->coord_s - 1] == '%')
		count_format(s, stock);
	else
		return ;
}

void	ft_parse(const char *s, t_list *stock, va_list ap)
{
	while (ft_verif_convert(s, stock) == -1)
	{
		if (s[stock->coord_s] == '*')
		{
			stock->bin |= 1 << 8;
			wildcard(va_arg(ap, int), stock, s);
		}
		if (s[stock->coord_s] == '-')
			stock->bin |= 1 << 9;
		if (s[stock->coord_s] == '0' && s[stock->coord_s - 1] != '.')
			stock->bin |= 1 << 10;
		if (s[stock->coord_s] == '.')
			stock->bin |= 1 << 11;
		if (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
			ft_count(s, stock);
		if (s[stock->coord_s] == '%')
		{
			ft_apply_width_percent(stock);
			dump_buffer(stock);
			return ;
		}
		stock->coord_s++;
	}
	return ;
}
