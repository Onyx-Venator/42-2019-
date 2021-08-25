/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:01:14 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/25 12:20:13 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa(t_stack *t)
{
	t_value *tmp;

	write(1, "sa", 2);
	if (t->a && t->a->next)
	{
		tmp = t->a->next;
		t->a->next = t->a->next->next;
		tmp->next = t->a;
		t->a = tmp;
	}
}

void	ft_sb(t_stack *t)
{
	t_value *tmp;

	write(1, "sb", 2);
	if (t->b && t->b->next)
	{
		tmp = t->b->next;
		t->b->next = t->b->next->next;
		tmp->next = t->b;
		t->b = tmp;
	}
}

void	ft_ss(t_stack *t)
{
	write(1, "ss", 2);
	ft_sa(t);
	ft_sb(t);
}
