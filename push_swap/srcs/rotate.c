/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:03:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/09/03 20:10:17 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_ra(t_stack *stack)
{
	t_value *tmp;
	t_value *tmp_last;

	if (stack->a && stack->a->next)
	{
		tmp_last = stack->a;
		stack->a = stack->a->next;
		tmp = stack->a;
		tmp_last->next = NULL;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = tmp_last;
	}
}

void	ft_rb(t_stack *stack)
{
	t_value *tmp;
	t_value *tmp_last;

	if (stack->b && stack->b->next)
	{
		tmp_last = stack->b;
		stack->b = stack->b->next;
		tmp = stack->b;
		tmp_last->next = NULL;
		while(tmp->next)
		tmp = tmp->next;
		tmp->next = tmp_last;
	}
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}
