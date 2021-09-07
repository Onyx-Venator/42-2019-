/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:05:08 by anonymou          #+#    #+#             */
/*   Updated: 2021/09/03 20:10:05 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rra(t_stack *t)
{
	t_value	*start;
	t_value	*tmp;

	if (t->a && t->a->next)
	{
		start = t->a;
		while (t->a->next->next)
		{
			t->a = t->a->next;
		}
		tmp = t->a->next;
		t->a->next = NULL;
		t->a = start;
		tmp->next = t->a;
		t->a = tmp;
	}
}

void	ft_rrb(t_stack *t)
{
	t_value	*start;
	t_value	*tmp;

	if (t->b && t->b->next)
	{
		start = t->b;
		while (t->b->next->next)
		{
			t->b = t->b->next;
		}
		tmp = t->b->next;
		t->b->next = NULL;
		t->b = start;
		tmp->next = t->b;
		t->b = tmp;
	}
}

void	ft_rrr(t_stack *t)
{
	ft_rra(t);
	ft_rrb(t);
}
