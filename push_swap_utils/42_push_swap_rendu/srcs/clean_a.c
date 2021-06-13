/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:27 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:28 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_flags(t_stack *a, int flag)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = a->next;
	while (tmp != a)
	{
		if (tmp->flag == flag)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

static void	add_flags_from(t_stack **a, int value)
{
	t_stack	*tmp;
	int		last_max;

	last_max = -1;
	tmp = (*a)->next;
	while (tmp->val != value && tmp != (*a))
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
	if (tmp != (*a))
	{
		tmp->flag = 1;
		last_max = tmp->val;
		tmp = tmp->next;
	}
	while (tmp != (*a))
	{
		if (tmp->val > last_max && (tmp->flag = 1))
			last_max = tmp->val;
		else
			tmp->flag = 0;
		tmp = tmp->next;
	}
}

void		add_best_flags(t_stack **a)
{
	t_stack	*tmp;
	int		count;
	int		max_count;
	int		best;

	tmp = (*a)->next;
	max_count = -1;
	while (tmp != (*a))
	{
		add_flags_from(a, tmp->val);
		count = count_flags(*a, 1);
		if (count > max_count)
		{
			max_count = count;
			best = tmp->val;
		}
		tmp = tmp->next;
	}
	add_flags_from(a, best);
}

void		fill_list_index(t_stack **a, int *t, int size)
{
	int		i;
	t_stack	*tmp;

	tmp = (*a)->next;
	while (tmp != (*a))
	{
		i = -1;
		while (++i < size)
		{
			if (t[i] == tmp->val)
				tmp->index = i;
		}
		tmp = tmp->next;
	}
}

void		clean_a(t_stack **a, t_stack **b)
{
	int		*t;

	t = create_index_tab(a);
	add_best_flags(a);
	while (count_flags(*a, 0) > 0)
	{
		if (should_swap_a(*a, *b) == 1)
		{
			exec_ope("sa", a, b, 1);
			add_best_flags(a);
		}
		else if ((*a)->next->flag == 0)
			exec_ope("pb", a, b, 1);
		else
			exec_ope("ra", a, b, 1);
	}
	free(t);
}
