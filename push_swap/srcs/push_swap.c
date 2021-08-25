/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/25 13:05:46 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int		end_stack(t_value *a)
{
	t_value tmp;

	tmp = a;
	while (tmp)
		tmp =tmp->next;
	return (tmp->id);
}

void	ft_exec_op(int op, t_stack *stack, int nb_ope)
{
	while (nb_ope != 0)
	{
		if (op == RA)
			ft_ra(stack);
		else if (op == RB)
			ft_rb(stack);
		else if (op == RR)
			ft_rr(stack);
		else if (op == RRA)
			ft_rra(stack);
		else if (op == RRB)
			ft_rrb(stack);
		else if (op == RRR)
			ft_rrr(stack);
		else if (op == PA)
			ft_pa(stack);
		else if (op == PB)
			ft_pb(stack);
		else if (op == SA)
			ft_sa(stack);
		else if (op == SB)
			ft_sb(stack);
		else if (op == SS)
			ft_ss(stack);
		nb_ope--;
	}
}

void	exec_ope_n(t_stack *stack)
{
	if (stack->next_id < (stack->size_a / 2 + 1) && stack->id <
	(stack->size_b / 2 + 1))
	{
		ft_exec_op(RR, stack, min(stack->next_id, stack->id));
		ft_exec_op(RA, stack, max(0, stack->id - min(stack->next_id, stack->id)))
		ft_exec_op(RB, stack, max(0, stack->id - min(stack->next_id, stack->id)))
	}
	else if (stack->next_id >= (stack->size_a / 2 + 1) && stack->id >=
	(stack->size_b / 2 + 1))
	{
		ft_exec_op(RRR, stack, min(stack->size_a - stack->next_id, stack->size_b - stack->id));
		ft_exec_op(RRA, stack, max(0, stack->size_a - stack->next_id
			- min(stack->size_a - stack->next_id, stack->size_b - stack->id)));
		ft_exec_op(RRB, stack, max(0, stack->size_b - stack->id -
			min(stack->size_a - stack->next_id, stack->size_b - stack->id)));
	}
	else if (stack->next_id > (stack->size_a / 2 + 1) && stack->id >=
	(stack->size_b / 2 + 1))
	{
		ft_exec_op(RA, stack, stack->next_id);
		ft_exec_op(RRB, stack, stack->size_b - stack->id);
	}
	else if (stack->next_id >= (stack->size_a / 2 + 1) && stack->id <
	(stack->size_b / 2 + 1))
	{
		ft_exec_op(RRA, stack, stack->size_a - stack->next_id);
		ft_exec_op(RB, stack, stack->id);
	}
	ft_exec_op(PA, stack, 1);
}

int		*best_op(t_stack *stack)
{
	t_value	*tmp;
	int		op;

	tmp = stack->b->next;
	stack->next_id = get_next_id(stack->a, tmp->value);
	stack->id = get_id(stack->b, tmp->value);
	stack->size_a = ft_lstsize(stack->a);
	stack->size_b = ft_lstsize(stack->b);
}

void	search_op(t_stack *stack)
{
	int	op;

	while (stack->b->next != stack->b)
	{
		best_op(stack);
		apply_op(stack);
	}
	free(op);
}

void	swap_stack(t_stack *stack)
{
	int	i;

	i = stack->a->id;
	if (stack->a->id == 1)
		ft_exec_op(RA, stack);
	else
		ft_exec_op(PB, stack);
	while (stack->a->id != i)
	{
		if (stack->a->id == 1)
			ft_exec_op(RA, stack, 1);
		else
			ft_exec_op(PB, stack, 1);
	}
}

void	set_flags(t_stack *stack)
{
	t_value	tmp;
	int		i;
	int		*x;

	tmp = stack->a;
	if (tmp->id == stack->start_chain)
		tmp->flag = 1;
	x = &tmp;
	while (tmp)
	{
		i = tmp->id;
		if (tmp->id > i)
		{
			i = tmp->id;
			tmp->flag = 1;
		}
		tmp = tmp->next;
	}
	&tmp = x;
	stack->a = tmp;
}

void	id_max(t_stack *stack)
{
	t_value	tmp;

	tmp = stack->a;
	stack->id_max = tmp->id;
	while (tmp)
	{
		if (tmp->id > stack->id_max)
			stack->id_max = tmp->id;
		tmp = tmp->next;
	}
}

void	longer_chain(t_stack *stack)
{
	t_value	tmp;
	t_value	tmp_utils;
	t_value	best;
	int i[2];
	int cur_id;

	tmp = stack->a;
	i[1] = 0;
	while (tmp)
	{
		tmp_utils = tmp->next;
		i[0] = 0;
		cur_id = tmp->id;
		while (tmp_utils != tmp)
		{
			if (tmp_utils = NULL)
				tmp_utils = stack->a;
			if (cur_id < tmp_utils->id)
			{
				i[0]++;
				cur_id = tmp_utils->id;
			}
			tmp_utils = tmp_utils->next;
		}
		if (i > i[1])
		{
			best = tmp;
			i[1] = i[0];
		}
		tmp = tmp->next;
	}
	stack->start_chain = best->id;
}

int		ft_pos(t_value *a, int target)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 1;
	while (tmp->id != target)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	add_id(t_value *a, int *j)
{
	int	u;
	int	tmp;

	u = -1;
	while (j[++u])
	{
		if (j[u + 1] && (j[u] > j[u + 1]))
		{
			tmp = j[u];
			j[u] = j[u + 1];
			j[u + 1] = tmp;
			u = -1;
		}
	}
	while (a->next)
	{
		u = -1;
		while (a->value != j[++u])
			;
		a->id = u;
	}
}

int	verif_doublon(char **av)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while (av[++i])
	{
		x = -1;
		j = i + 1;
		while (av[i][++x])
		{
			if ((av[i][x] == av[j][x]) && (x == 0))
			{
				while (av[i][x] && av[j][x] && (av[i][x] == av[j][x]))
					x++;
				if (!av[i][x] && !av[j][x])
					return (0);
			}
		}
	}
	return (1);
}

int	verif_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		while (str[i++])
		;
		if (i > 11)
		return (0);
	}
	else
	{
		while (str[i++])
		;
		if (i > 10)
		return (0);
	}
	if (ft_atoiminmax(i, str) == 0)
		return (0);
	return (1);
}

int	ft_verif(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		i++;
		if (ft_isdigit(av[i]) == 0)
		return (0);
		if (verif_len(av[i]) == 0)
			return (0);
	}
	if (verif_doublon(av) == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	t_value	tmp;
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
	j = malloc(sizeof(int) * (ac + 1));
	if (j == NULL)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	j[ac] = NULL;
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
		ft_lstadd_back(&(stack->a), tmp);
	}
	add_id(stack.a, i, j);
	longer_chain(&stack);
	set_flags(&stack);
	id_max(&stack);
	swap_stack(&stack);
	return;
}
