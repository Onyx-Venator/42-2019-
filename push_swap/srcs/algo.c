/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:29:39 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/06 20:29:45 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	print_case(t_stack *a)
{
	printf("next_id : %d\n", a->next_id);
	printf("id : %d\n", a->id);
	printf("size a : %d\n", a->size_a);
	printf("size b : %d\n", a->size_b);
}

static void	printf_stack(t_value *a)
{
	t_value *aff;

	aff = a;
	while (aff)
	{
		printf("id = %d\n", aff->id);
		aff = aff->next;
	}
}

static void	init_data(t_stack *stack, int value)
{
	stack->id = get_id(stack->b, value);;
	stack->next_id = get_next_id(stack->a, value);
	stack->size_a = ft_lstsize(stack->a);
	stack->size_b = ft_lstsize(stack->b);
	/*printf("stack->id : %d\n", stack->id);
	printf("stack->next_id : %d\n", stack->next_id);
	printf("stack->size_a : %d\n", stack->size_a);
	printf("stack->size_b : %d\n", stack->size_b);*/
}

static void	case_b(t_stack *stack)
{
	print_case(stack);
	ft_exec_op(RRR, stack, min(stack->size_a - stack->next_id, stack->size_b
		- stack->id));
	ft_exec_op(RRA, stack, max(0, stack->size_a - stack->next_id
		- min(stack->size_a - stack->next_id, stack->size_b - stack->id)));
	ft_exec_op(RRB, stack, max(0, stack->size_b - stack->id -
		min(stack->size_a - stack->next_id, stack->size_b - stack->id)));
}

void		exec_op_n(t_stack *stac)
{
	printf("cas : %d\n", stac->check);
	if (stac->check == A)
	{
		print_case(stac);
		ft_exec_op(RR, stac, min(stac->next_id, stac->id));
		ft_exec_op(RA, stac, max(0, stac->next_id - min(stac->next_id, stac->id)));
		ft_exec_op(RB, stac, max(0, stac->id - min(stac->next_id, stac->id)));
	}
	else if (stac->check == B)
		case_b(stac);
	else if (stac->check == C)
	{
		print_case(stac);
		ft_exec_op(RA, stac, stac->next_id);
		ft_exec_op(RRB, stac, stac->size_b - stac->id);
	}
	else if (stac->check == D)
	{
		print_case(stac);
		ft_exec_op(RRA, stac, stac->size_a - stac->next_id);
		ft_exec_op(RB, stac, stac->id);
	}
	printf("a : \n");
	printf_stack(stac->a);
	printf("b : \n");
	printf_stack(stac->b);
	//if (stac->b->id == (stac->a->id - 1))
		ft_exec_op(PA, stac, 1);
	/*else
		return ;*/
}

void		search_case(t_stack *stack)
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
	else if (stack->next_id < (stack->size_a / 2 + 1) && stack->id >=
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
	init_data(stack, tmp->value);
	search_case(stack);
	min = stack->op;
	value = tmp->value;
	while (tmp)
	{
		init_data(stack, tmp->value);
		search_case(stack);
		if (stack->op < min)
		{
			min = stack->op;
			value = tmp->value;
		}
		tmp = tmp->next;
	}
	init_data(stack, value);
	printf("value : %d\n", value);
	search_case(stack);
}

void		search_op(t_stack *stack)
{
	//t_value *aff;

	while (stack->b)
	{
		// aff = stack->a;
		// while (aff)
		// {
		// 	printf("value = %d\nid = %d\n", aff->value, aff->id);
		// 	aff = aff->next;
		// }
		best_op(stack);
		exec_op_n(stack);
	}
}
