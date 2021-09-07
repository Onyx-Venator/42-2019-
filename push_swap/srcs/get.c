/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:34:05 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/06 20:37:56 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		get_id(t_value *b, int val)
{
	t_value	*tmp;
	int		id;

	id = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->value == val)
			return (id);
		id++;
		tmp = tmp->next;
	}
	return (id);
}

int		get_stack_max(t_value *a)
{
	t_value	*tmp;
	int		max;

	tmp = a;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int		get_stack_min(t_value *a)
{
	t_value	*tmp;
	int		min;

	tmp = a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int		get_next_id(t_value *a, int val)
{
	t_value	*tmp;
	int		min;
	int		max;
	int		id;

	id = 0;
	min = get_stack_min(a);
	max = get_stack_max(a);
	tmp = a;
	if (val < min || val > max)
		id = get_id(a, min);
	else
	{
		while (tmp->value != min)
			tmp = tmp->next;
		while (val > tmp->value)
		{
			if (!tmp->next)
				tmp = a;
			else
				tmp = tmp->next;
		}
		id = get_id(a, tmp->value);
	}
	return (id);
}
