/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:05:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/25 12:17:05 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void        ft_pa(t_stack *t)
{
	t_value *tmp;

	write(1, "pa", 2);
	if (t->b)
	{
		tmp = t->b->next;
		t->b->next = t->a;
		t->a = t->b;
		t->b = tmp;
	}
}

void	ft_pb(t_stack *t)
{
	t_value *tmp;

	write(1, "pb", 2);
	if (t->a)
	{
		tmp = t->a->next;
		t->a->next = t->b;
		t->b = t->a;
		t->a = tmp;
	}
}
