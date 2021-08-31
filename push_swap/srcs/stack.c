/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:21:00 by cofoundo          #+#    #+#             */
/*   Updated: 2021/08/29 21:25:09 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		end_stack(t_value *a)
{
	t_value tmp;

	tmp = a;
	while (tmp)
		tmp =tmp->next;
	return (tmp->id);
}

void	swap_stack(t_stack *stack)
{
	int	i;

	i = stack->a->id;
	if (stack->a->id == 1)
		ft_exec_op(RA, stack, 1);
	else
		ft_exec_op(PB, stack, 1);
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
