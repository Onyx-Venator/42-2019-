/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:53 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:53 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack_before_sort(t_stack **a, t_stack **b, int size)
{
	if ((*a)->next->index == 2)
	{
		if ((*a)->next->next->index == 3)
			exec_ope("rra", a, b, 1);
		else
			exec_ope("sa", a, b, 1);
	}
	else if (size == 5 && (*a)->next->index == 3)
	{
		if ((*a)->next->next->index == 2)
		{
			if ((*a)->prev->index == 4)
				exec_ope("rra", a, b, 1);
			else
				exec_ope("rra", a, b, 2);
		}
		else if ((*a)->prev->index == 2)
			exec_ope("ra", a, b, 1);
		else if ((*a)->next->next->index == 1)
			exec_ope("ra", a, b, 1);
		else
			exec_ope("sa", a, b, 1);
	}
}

/*
** 3 2 1
** 1 3 2
** 2 1 3
** 3 1 2
** 2 3 1
*/

void	sort_3(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if (tmp->val > tmp->next->val && tmp->next->val > tmp->next->next->val)
	{
		exec_ope("sa", a, b, 1);
		exec_ope("rra", a, b, 1);
	}
	else if (tmp->val < tmp->next->val && tmp->val < tmp->next->next->val &&
		tmp->next->val > tmp->next->next->val)
	{
		exec_ope("sa", a, b, 1);
		exec_ope("ra", a, b, 1);
	}
	else if (tmp->next->next->val > tmp->next->val &&
		tmp->next->next->val > tmp->val && tmp->val > tmp->next->val)
		exec_ope("sa", a, b, 1);
	else if (tmp->val > tmp->next->val && tmp->val > tmp->next->next->val)
		exec_ope("ra", a, b, 1);
	else if (tmp->next->val > tmp->val && tmp->val > tmp->next->next->val &&
		tmp->next->val > tmp->next->next->val)
		exec_ope("rra", a, b, 1);
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*t;

	if (are_sorted(clst_size(*a), *a, *b))
		return ;
	t = create_index_tab(a);
	clean_stack_before_sort(a, b, 4);
	exec_ope("pb", a, b, 1);
	tmp = (*b)->next;
	sort_3(a, b);
	if ((tmp->index == 0 || tmp->index == 1 || tmp->index == 3) &&
		exec_ope("pa", a, b, 1))
		tmp = (*a)->next;
	if (tmp->index == 1)
		exec_ope("sa", a, b, 1);
	else if (tmp->index == 2)
	{
		exec_ope("rra", a, b, 1);
		exec_ope("pa", a, b, 1);
		exec_ope("ra", a, b, 2);
	}
	else if (tmp->index == 3)
		exec_ope("ra", a, b, 1);
	free(t);
}

void	sort_cleaned_5(t_stack *tmp, t_stack **a, t_stack **b)
{
	if (tmp->index == 1)
		exec_ope("sa", a, b, 1);
	else if (tmp->index == 2)
	{
		exec_ope("ra", a, b, 1);
		exec_ope("pa", a, b, 1);
		exec_ope("sa", a, b, 1);
		exec_ope("rra", a, b, 1);
	}
	else if (tmp->index == 3)
	{
		exec_ope("rra", a, b, 1);
		exec_ope("pa", a, b, 1);
		exec_ope("ra", a, b, 2);
	}
	else if (tmp->index == 4)
		exec_ope("ra", a, b, 1);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*t;

	if (are_sorted(clst_size(*a), *a, *b))
		return ;
	t = create_index_tab(a);
	clean_stack_before_sort(a, b, 5);
	exec_ope("pb", a, b, 1);
	tmp = (*b)->next;
	sort_4(a, b);
	if (tmp->index == 0 || tmp->index == 1 || tmp->index == 4)
	{
		exec_ope("pa", a, b, 1);
		tmp = (*a)->next;
	}
	sort_cleaned_5(tmp, a, b);
	free(t);
}
