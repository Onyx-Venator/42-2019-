/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:25:44 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/06 20:07:52 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	flag_utils(t_value *a, int value)
{
	t_value	*tmp;
	int		max;

	max = -1;
	tmp = a;
	while (tmp->value != value && tmp)
	{
		if (!tmp)
			tmp = a;
		tmp->flag = 0;
		tmp = tmp->next;
	}
	if (!tmp)
		tmp = a;
	if (tmp != a)
	{
		tmp->flag = 1;
		max = tmp->value;
		tmp = tmp->next;
	}
	if (!tmp)
		tmp = a;
	while (tmp != a)
	{
		if (tmp->value > max)
		{
			tmp->flag = 1;
			max = tmp->value;
		}
		else
			tmp->flag = 0;
		tmp = tmp->next;
		if (!tmp)
			tmp = a;
	}
}

int		count_flag(t_value *a, int i)
{
	t_value	*tmp;
	int		count;

	count = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->flag == i)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	set_flag(t_value *a)
{
	t_value	*tmp;
	int		count;
	int		max;
	int		best;

	tmp = a;
	max = 0;
	while (tmp)
	{
		flag_utils(a, tmp->value);
		count = count_flag(a, 1);
		if (count > max)
		{
			max = count;
			best = tmp->value;
		}
		tmp = tmp->next;
	}
	flag_utils(a, best);
}
