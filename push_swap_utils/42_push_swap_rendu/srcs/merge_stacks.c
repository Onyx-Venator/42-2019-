/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:51 by tsantoni          #+#    #+#             */
/*   Updated: 2021/09/06 19:59:24 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_case_data(t_case *c, t_stack *a, t_stack *b, int val)
{
	c->val = val;
	c->i = get_next_index(a, val);
	c->j = get_index(b, val);
	c->size_a = clst_size(a);
	c->size_b = clst_size(b);
	c->half_a = clst_size(a) / 2 + 1;
	c->half_b = clst_size(b) / 2 + 1;
}

static int	fill_case_data(t_stack *a, t_stack *b, int val, t_case *c)
{
	init_case_data(c, a, b, val);
	if (c->i < c->half_a && c->j < c->half_b)
	{
		c->case_nb = CASE_A;
		c->ope_necess = ft_max(c->i, c->j);
	}
	else if (c->i >= c->half_a && c->j >= c->half_b)
	{
		c->case_nb = CASE_B;
		c->ope_necess = ft_max(c->size_a - c->i, c->size_b - c->j);
	}
	else if (c->i < c->half_a && c->j >= c->half_b)
	{
		c->case_nb = CASE_C;
		c->ope_necess = c->i + c->size_b - c->j;
	}
	else if (c->i >= c->half_a && c->j < c->half_b)
	{
		c->case_nb = CASE_D;
		c->ope_necess = c->j + c->size_a - c->i;
	}
	return (c->ope_necess);
}

static void	apply_case(t_stack **a, t_stack **b, t_case *c)
{
	if (c->case_nb == CASE_A)
	{
		exec_ope("rr", a, b, ft_min(c->i, c->j));
		exec_ope("ra", a, b, ft_max(0, c->i - ft_min(c->i, c->j)));
		exec_ope("rb", a, b, ft_max(0, c->j - ft_min(c->i, c->j)));
	}
	else if (c->case_nb == CASE_B)
	{
		exec_ope("rrr", a, b, ft_min(c->size_a - c->i, c->size_b - c->j));
		exec_ope("rra", a, b, ft_max(0, c->size_a - c->i -
			ft_min(c->size_a - c->i, c->size_b - c->j)));
		exec_ope("rrb", a, b, ft_max(0, c->size_b - c->j -
			ft_min(c->size_a - c->i, c->size_b - c->j)));
	}
	else if (c->case_nb == CASE_C)
	{
		exec_ope("ra", a, b, c->i);
		exec_ope("rrb", a, b, c->size_b - c->j);
	}
	else if (c->case_nb == CASE_D)
	{
		exec_ope("rra", a, b, c->size_a - c->i);
		exec_ope("rb", a, b, c->j);
	}
	exec_ope("pa", a, b, 1);
}

static void	find_best_case(t_stack *a, t_stack *b, t_case *c)
{
	t_stack	*tmp;
	int		best;
	int		min;

	tmp = b->next;
	fill_case_data(a, b, tmp->val, c);
	best = tmp->val;
	min = c->ope_necess;
	while (tmp != b)
	{
		fill_case_data(a, b, tmp->val, c);
		if (c->ope_necess < min)
		{
			min = c->ope_necess;
			best = tmp->val;
		}
		tmp = tmp->next;
	}
	fill_case_data(a, b, best, c);

}

void		merge_stacks(t_stack **a, t_stack **b)
{
	t_case	c;
	t_stack *tmp;

	tmp = (*b)->next;
	// if (!(c = malloc(sizeof(t_case))))
	// 	return ;
	while ((*b)->next != *b)
	{
		find_best_case(*a, *b, &c);
		apply_case(a, b, &c);
	}
	free(c);
}
