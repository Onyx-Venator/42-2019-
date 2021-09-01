/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/09/01 16:12:37 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		write(1, "\n", 1);
		nb_ope--;
	}
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
	if (stack->id_max <= 5)
	{
		if (stack->id_max == 2)
			case_two(&stack);
		if (stack->id_max == 3)
			case_three(&stack);
		if (stack->id_max == 4)
			case_four(&stack);
		if (stack->id_max == 5)
			case_five(&stack);
	}
	else
	{
		swap_stack(&stack);
		search_op(&stack);
	}
	free(stack);
	return;
}
