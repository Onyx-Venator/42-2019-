/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:30:27 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/02 13:14:52 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_ra(t_stack *t)
{
	t_lst_int *tmp;
	t_lst_int *tmp_last;
	
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

void	ft_rb(t_stack *t)
{
	t_lst_int *tmp;
	t_lst_int *tmp_last;
	
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

void	ft_rr(t_stack *t)
{
	ft_ra(t);
	ft_rb(t);
}