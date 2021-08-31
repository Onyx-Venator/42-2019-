/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:34:05 by cofoundo          #+#    #+#             */
/*   Updated: 2021/08/28 11:38:15 by cofoundo         ###   ########.fr       */
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
			max = tmp->value
		tmp = tmp->next;
	}
	free(tmp);
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
			min = tmp->value
		tmp = tmp->next;
	}
	free(tmp);
	return (min);
}

int		get_next_id(t_value *a, int val)
{
	t_value	*tmp;
	t_value	*last;
	int		min;
	int		max;
	int		index;

	index = 0;
	min = get_stack_min(a);
	max = get_stack_max(a);
	tmp = a;
	if (val < min || val > max)
		index = get_id(a, min);
	else
	{
		while (last->next)
			last = last->next;
		while (val > tmp->value)
			tmp = tmp->next;
		index = get_id(a, tmp->value);
		last->next = NULL;
	}
	return (index);
}
