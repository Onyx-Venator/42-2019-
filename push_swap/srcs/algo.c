/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:29:39 by cofoundo          #+#    #+#             */
/*   Updated: 2021/08/31 13:53:34 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static_void	case_b(t_stack *stack)
{
	ft_exec_op(RR, stack, min(stack->size_a - stack->next_id, stack->size_b
		- stack->id));
	ft_exec_op(RRA, stack, max(0, stack->size_a - stack->next_id
		- min(stack->size_a - stack->next_id, stack->size_b - stack->id)));
	ft_exec_op(RRB, stack, max(0, stack->size_b - stack->id -
		min(stack->size_a - stack->next_id, stack->size_b - stack->id)));
}

void	exec_op_n(t_stack *stac)
{
	if (stac->check == A)
	{
		ft_exec_op(RR, stac, min(stac->next_id, stac->id));
		ft_exec_op(RA, stac, max(0, stac->id - min(stac->next_id, stac->id)))
		ft_exec_op(RB, stac, max(0, stac->id - min(stac->next_id, stac->id)))
	}
	else if (stac->check == B)
		b(stac);
	else if (stac->check == C)
	{
		ft_exec_op(RA, stac, stac->next_id);
		ft_exec_op(RRB, stac, stac->size_b - stac->id);
	}
	else if (stac->check == D)
	{
		ft_exec_op(RRA, stac, stac->size_a - stac->next_id);
		ft_exec_op(RB, stac, stac->id);
	}
	ft_exec_op(PA, stac, 1);
}

void	search_case(t_stack *stack)
{
	if (stack->next_id < (stack->size_a / 2 + 1) && stack->id <
	(stack->size_b / 2 + 1))
	{
		stack->check = A;
		stack->op = max(stack->next_id, stack->id);
	}
	else if (stack->next_id >= (stack->size_a / 2 + 1) && stack->id >=
	(stack->size_b / 2 + 1))
	{
		stack->check = B;
		stack->op = max(stack->size_a - stack->next_id, stack->size_b -
		stack->id);
	}
	else if (stack->next_id > (stack->size_a / 2 + 1) && stack->id >=
	(stack->size_b / 2 + 1))
	{
		stack->check = C;
		stack->op = stack->next_id + stack->size_b - stack->id;
	}
	else if (stack->next_id >= (stack->size_a / 2 + 1) && stack->id <
	(stack->size_b / 2 + 1))
	{
		stack->check = D;
		stack->op = stack->id + stack->size_a - stack->next_id;
	}
}

void		best_op(t_stack *stack)
{
	t_value	*tmp;
	int		min;
	int		value;

	tmp = stack->b;
	stack->next_id = get_next_id(stack->a, tmp->value);
	stack->id = get_id(stack->b, tmp->value);
	stack->size_a = ft_lstsize(stack->a);
	stack->size_b = ft_lstsize(stack->b);
	search_case(stack);
	min = stack->op;
	value = tmp->value;
	while (tmp)
	{
		search_case(stack);
		if (stack->op < min)
		{
			min = stack->op;
			value = tmp->value;
		}
		tmp = tmp->next;
	}
	tmp = stack->b;
	while (tmp->value != value)
		tmp = tmp->next;
	search_case(stack);
}

void	search_op(t_stack *stack)
{
	int		op;
	t_value	tmp;

	tmp = stack->b;
	while (tmp)
	{
		best_op(stack);
		exec_op_n(stack);
		tmp = tmp->next;
	}
}
