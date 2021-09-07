/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:05:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/09/03 20:10:57 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void        ft_pa(t_stack *t)
{
	t_value *tmp;

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

	if (t->a)
	{
		tmp = t->a->next;
		t->a->next = t->b;
		t->b = t->a;
		t->a = tmp;
	}
}
