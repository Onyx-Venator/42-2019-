/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:48:57 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/16 19:29:32 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag(va_list ap, const char *s, t_list *stock)
{
	(void)s;
	if ((stock->bin & TYPE_C) == TYPE_C)
		ft_convert_c(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_S) == TYPE_S)
		ft_convert_s(va_arg(ap, char*), stock);
	if ((stock->bin & TYPE_P) == TYPE_P)
		ft_convert_p((unsigned long)va_arg(ap, unsigned long*), stock);
	if ((stock->bin & TYPE_D) == TYPE_D)
		ft_convert_d(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_I) == TYPE_I)
		ft_convert_d(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_U) == TYPE_U)
		ft_convert_u(va_arg(ap, unsigned int), stock);
	if ((stock->bin & TYPE_X) == TYPE_X)
		ft_convert_x(va_arg(ap, unsigned int), stock, "0123456789abcdef");
	if ((stock->bin & BIG_X) == BIG_X)
		ft_convert_x(va_arg(ap, unsigned int), stock, "0123456789ABCDEF");
	return ;
}

void	convert(va_list ap, const char *s, t_list *stock)
{
	ft_flag_zero(stock);
	ft_flag(ap, s, stock);
	return ;
}

void	start_convert(va_list ap, const char *s, t_list *stock)
{
	ft_parse(s, stock, ap);
	convert(ap, s, stock);
	return ;
}

void	ft_init(t_list *stock)
{
	stock->bin = 0;
	stock->count_precision = -1;
	stock->count_format = 0;
	stock->conv_len = 0;
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	t_list	stock;

	stock.coord_s = 0;
	stock.count_print = 0;
	stock.coord_buf = 0;
	va_start(ap, s);
	while (s[stock.coord_s])
	{
		ft_init(&stock);
		if (ft_verif(s, '%', &stock) != 0)
		{
			stock.coord_s++;
			start_convert(ap, s, &stock);
		}
		else
			add_to_buff(&stock, s[stock.coord_s]);
		stock.coord_s++;
	}
	dump_buffer(&stock);
	return (stock.count_print);
}
