/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/07/06 03:01:47 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	ft_exec_op(int op, t_stack *stack)
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
	longer_chain(&stack)
	/*blabla mettre les flags*/
	id_max(&stack);

	return ;
}
