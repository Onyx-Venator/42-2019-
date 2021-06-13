/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:43 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:43 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return la position d'une valeur dans la stack
*/

int		get_index(t_stack *b, int val)
{
	int		index;
	t_stack	*tmp;

	index = 0;
	tmp = b->next;
	while (tmp != b)
	{
		if (tmp->val == val)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

/*
** return le tmp->index d'une valeur dans la stack
*/

int		get_stack_index(t_stack *a, int val)
{
	t_stack	*tmp;

	tmp = a->next;
	while (tmp != a)
	{
		if (tmp->val == val)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (tmp->index);
}

int		get_stack_min(t_stack *root)
{
	t_stack	*tmp;
	int		min;

	tmp = root->next;
	min = tmp->val;
	while (tmp != root)
	{
		if (tmp->val < min)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

int		get_stack_max(t_stack *root)
{
	t_stack	*tmp;
	int		max;

	tmp = root->next;
	max = tmp->val;
	while (tmp != root)
	{
		if (tmp->val > max)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

int		get_next_index(t_stack *a, int val)
{
	int		*t;
	int		min;
	int		max;
	int		index;
	int		i;

	index = 0;
	i = 0;
	min = get_stack_min(a);
	max = get_stack_max(a);
	t = clst_to_tab(a, clst_size(a));
	ft_quicksort(t, 0, clst_size(a) - 1);
	if (val < min || val > max)
		index = get_index(a, min);
	else
	{
		while (val > t[i])
			i++;
		index = get_index(a, t[i]);
	}
	free(t);
	return (index);
}
