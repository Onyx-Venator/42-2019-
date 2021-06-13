/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_fct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:41:14 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/02 13:14:45 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rra(t_stack *t)
{
	t_lst_int	*start;
	t_lst_int	*tmp;

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
	t_lst_int	*start;
	t_lst_int	*tmp;

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
