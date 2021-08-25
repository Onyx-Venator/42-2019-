/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:03:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/25 12:19:19 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_ra(t_stack *stack)
{
	t_value *tmp;
	t_value *tmp_last;

	write(1, "ra", 2);
	if (t->a && t->a->next)
	{
		tmp_last = t->a;
		t->a = t->a->next;
		tmp = t->a;
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

	write(1, "rb", 2);
	if (t->b && t->b->next)
	{
		tmp_last = t->b;
		t->b = t->b->next;
		tmp = t->b;
		tmp_last->next = NULL;
		while(tmp->next)
		tmp = tmp->next;
		tmp->next = tmp_last;
	}
}

void	ft_rr(t_stack *stack)
{
	ft_ra(t);
	ft_rb(t);
}
