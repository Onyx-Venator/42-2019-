/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/09/07 16:59:45 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		free_stack(t_value *a)
{
	t_value	*tmp;
	t_value	*utils;

	tmp = a;
	while (tmp)
	{
		utils = tmp->next;
		free(tmp);
		tmp = utils;
	}
}

static int	stack_min(t_value *a)
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

static int	check_j(int *j)
{
	int	i;

	i = -1;
	while (j[++i])
	{
		if (j[i + 1] && (j[i] > j[i + 1]))
			return (0);
	}
	return (1);
}

static void	start_op_utils(int op, t_stack *stack)
{
	if (op == RRR)
	{
		write(1, "rrr\n", 4);
		ft_rrr(stack);
	}
	else if (op == PA)
	{
		write(1, "pa\n", 3);
		ft_pa(stack);
	}
	else if (op == PB)
	{
		write(1, "pb\n", 3);
		ft_pb(stack);
	}
	else if (op == SA)
	{
		write(1, "sa\n", 3);
		ft_sa(stack);
	}
}

void	strat_op(int op, t_stack *stack)
{
	if (op == RA)
	{
		write(1, "ra\n", 3);
		ft_ra(stack);
	}
	else if (op == RB)
	{
		write(1, "rb\n", 3);
		ft_rb(stack);
	}
	else if (op == RR)
	{
		write(1, "rr\n", 3);
		ft_rr(stack);
	}
	else if (op == RRA)
	{
		write(1, "rra\n", 4);
		ft_rra(stack);
	}
	else if (op == RRB)
	{
		write(1, "rrb\n", 4);
		ft_rrb(stack);
	}
}

void	init_case(t_stack *stack)
{
	if (stack->id_max == 2)
		case_two(stack);
	if (stack->id_max == 3)
		case_three(stack);
	if (stack->id_max == 4)
		case_four(stack);
	if (stack->id_max == 5)
		case_five(stack);
}

void	ft_exec_op(int op, t_stack *stack, int nb_ope)
{
	while (--nb_ope >= 0)
	{
		strat_op(op, stack);
		start_op_utils(op, stack);
		if (op == SB)
		{
			write(1, "sb\n", 3);
			ft_sb(stack);
		}
		else if (op == SS)
		{
			write(1, "ss\n", 3);
			ft_ss(stack);
		}
	}
}

void	align_stack(t_stack *stack)
{
	int	i;

	i = get_id(stack->a, stack_min(stack->a));
	while (stack->a->id != 1)
	{
		if (i < (stack->size_a / 2 + 1))
			ft_exec_op(RA, stack, 1);
		else
			ft_exec_op(RRA, stack, 1);
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;
	t_value	*tmp;
	int		i;
	int		*j;

	i = 0;
	if (ac == 1 || ft_verif(ac, av) == 0)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	stack.a = NULL;
	stack.b = NULL;
	j = malloc(sizeof(int) * (ac));
	if (j == NULL)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	j[ac - 1] = '\0';
	while (ac > ++i)
	{
		tmp = malloc(sizeof(t_value));
		if (tmp == NULL)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		tmp->next = NULL;
		tmp->value = ft_atoi(av[i]);
		j[i -1] = tmp->value;
		tmp->id = i;
		tmp->flag = 0;
		ft_lstadd_back(&(stack.a), tmp);
	}
	if (check_j(j) == 1)
	{
		free(j);
		free_stack(stack.a);
		return (0);
	}
	add_id(stack.a, j);
	id_max(&stack);
	if (stack.id_max <= 5)
		init_case(&stack);
	else
	{
		stack.op = 0;
		longer_chain(&stack);
		search_op(&stack);
		align_stack(&stack);
	}
	free_stack(stack.a);
	free(j);
	return (0);
}
