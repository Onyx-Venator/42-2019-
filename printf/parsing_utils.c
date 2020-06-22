/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:11:54 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/19 16:45:27 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	count_precision(const char *s, t_list *stock)
{
	stock->count_precision = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
		stock->count_precision = stock->count_precision * 10 +
			s[stock->coord_s++] - '0';
	stock->coord_s--;
	return ;
}

void	count_format(const char *s, t_list *stock)
{
	stock->count_format = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
		stock->count_format = stock->count_format * 10 +
			s[stock->coord_s++] - '0';
	stock->coord_s--;
	return ;
}

void	ft_flag_zero(t_list *stock)
{
	if ((stock->bin & TYPE_ZERO) == TYPE_ZERO &&
		(stock->bin & TYPE_POINT) == TYPE_POINT)
		stock->bin &= ~(1 << 10);
	return ;
}
