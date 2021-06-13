/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:04:30 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/02 13:14:59 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		ft_sa(t_stack *t)
{
	t_lst_int *tmp;

	if (t->a && t->a->next)
	{
		tmp = t->a->next;
		t->a->next = t->a->next->next;
		tmp->next = t->a;
		t->a = tmp;
	}
}

void		ft_sb(t_stack *t)
{
	t_lst_int *tmp;

	if (t->b && t->b->next)
	{
		tmp = t->b->next;
		t->b->next = t->b->next->next;
		tmp->next = t->b;
		t->b = tmp;
	}
}

void		ft_ss(t_stack *t)
{
	ft_sa(t);
	ft_sb(t);
}