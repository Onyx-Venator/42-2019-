/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:03:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/05/27 12:04:16 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_ra(t_stack *t)
{
    t_lst *tmp;
    t_lst *tmp_last;

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

void    ft_rb(t_stack *t)
{
    t_lst *tmp;
    t_lst *tmp_last;

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

void    ft_rr(t_stack *t)
{
    ft_ra(t);
    ft_rb(t);
}
