/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:25:16 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/16 19:27:12 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_c(int x, t_list *stock)
{
	stock->conv_len = 1;
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_to_buff(stock, x);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		add_to_buff(stock, x);
	}
	return ;
}
