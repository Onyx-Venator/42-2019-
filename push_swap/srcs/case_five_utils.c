/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:15:39 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/01 16:42:20 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	eight(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 5 && t_one->id = 1 && t_two->id == 2 && t_t->id == 3)
		write(1, "ra\n", 3);
	else if (s->a->id == 5 && t_one->id = 1 && t_two->id == 2 && t_t->id == 4)
		write(1, "rra\nrra\nsa\nrra\nrra\n", 19);
	else if (s->a->id == 5 && t_one->id = 1 && t_two->id == 3 && t_t->id == 2)
		write(1, "ra\nra\nsa\nrra\n", 13);
	else if (s->a->id == 5 && t_one->id = 1 && t_two->id == 3 && t_t->id == 4)
		write(1, "rra\nsa\nra\nsa\n", 13);
	else if (s->a->id == 5 && t_one->id = 1 && t_two->id == 4 && t_t->id == 2)
		write(1, "pb\nsa\nra\npa\nra\n", 15);
	else if (s->a->id == 5 && t_one->id = 1 && t_two->id == 4 && t_t->id == 3)
		write(1, "sa\npb\nsa\nra\nra\nsa\npa\n", 21);
	else if (s->a->id == 5 && t_one->id = 2 && t_two->id == 1 && t_t->id == 3)
		write(1, "ra\nsa\n", 6);
	else if (s->a->id == 5 && t_one->id = 2 && t_two->id == 1 && t_t->id == 4)
		write(1, "ra\nra\npb\nsa\nrra\npa\n", 19);
	else if (s->a->id == 5 && t_one->id = 2 && t_two->id == 3 && t_t->id == 1)
		write(1, "ra\nra\nsa\nrra\nsa\n", 16);
	else if (s->a->id == 5 && t_one->id = 2 && t_two->id == 3 && t_t->id == 4)
		write(1, "rra\nsa\nra\n", 10);
	else if (s->a->id == 5 && t_one->id = 2 && t_two->id == 4 && t_t->id == 1)
		write(1, "sa\npb\nsa\nrra\npa\nrra\n", 20);
	else
		nine(s, t_one, t_two, t_t);
}

void	seven(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 4 && t_one->id = 3 && t_two->id == 1 && t_t->id == 5)
		write(1, "sa\nra\nra\nsa\nra\n", 15);
	else if (s->a->id == 4 && t_one->id = 3 && t_two->id == 2 && t_t->id == 1)
		write(1, "sa\nra\nra\nsa\npb\nsa\nra\npa\n", 24);
	else if (s->a->id == 4 && t_one->id = 3 && t_two->id == 2 && t_t->id == 5)
		write(1, "sa\nra\nsa\nrra\nsa\nrra\n", 20);
	else if (s->a->id == 4 && t_one->id = 3 && t_two->id == 5 && t_t->id == 1)
		write(1, "sa\nrra\nrra\n", 11);
	else if (s->a->id == 4 && t_one->id = 3 && t_two->id == 5 && t_t->id == 2)
		write(1, "sa\nrra\nrra\nsa\n", 14);
	else if (s->a->id == 4 && t_one->id = 5 && t_two->id == 1 && t_t->id == 2)
		write(1, "ra\nra\n", 6);
	else if (s->a->id == 4 && t_one->id = 5 && t_two->id == 1 && t_t->id == 3)
		write(1, "rra\nrra\nsa\nrra\n", 15);
	else if (s->a->id == 4 && t_one->id = 5 && t_two->id == 2 && t_t->id == 1)
		write(1, "ra\nra\nsa\n", 9);
	else if (s->a->id == 4 && t_one->id = 5 && t_two->id == 2 && t_t->id == 3)
		write(1, "rra\nsa\nra\nsa\nra\n",16);
	else if (s->a->id == 4 && t_one->id = 5 && t_two->id == 3 && t_t->id == 1)
		write(1, "ra\nsa\nrra\nsa\nrra\nrra\n", 21);
	else if (s->a->id == 4 && t_one->id = 5 && t_two->id == 3 && t_t->id == 2)
		write(1, "rra\npb\nra\nra\nsa\npa\n", 19);
	else
		eight(s, t_one, t_two, t_t);
}

void	six(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 4 && t_one->id = 1 && t_two->id == 3 && t_t->id == 2)
		write(1, "rra\nsa\nrra\nrra\nsa\nrra\n", 22);
	else if (s->a->id == 4 && t_one->id = 1 && t_two->id == 3 && t_t->id == 5)
		write(1, "sa\npb\nsa\nrra\npa\n", 16);
	else if (s->a->id == 4 && t_one->id = 1 && t_two->id == 5 && t_t->id == 2)
		write(1, "ra\nsa\nra\n", 9);
	else if (s->a->id == 4 && t_one->id = 1 && t_two->id == 5 && t_t->id == 3)
		write(1, "ra\npb\nra\nsa\npa\n", 15);
	else if (s->a->id == 4 && t_one->id = 2 && t_two->id == 1 && t_t->id == 3)
		write(1, "rra\nsa\nra\nra\nsa\n", 16);
	else if (s->a->id == 4 && t_one->id = 2 && t_two->id == 1 && t_t->id == 5)
		write(1, "ra\nsa\npb\nsa\nra\npa\n", 18);
	else if (s->a->id == 4 && t_one->id = 2 && t_two->id == 3 && t_t->id == 1)
		write(1, "sa\nra\nsa\nra\nra\nsa\nra\n", 21);
	else if (s->a->id == 4 && t_one->id = 2 && t_two->id == 3 && t_t->id == 5)
		write(1, "sa\nra\nsa\nrra\nrra\n", 17);
	else if (s->a->id == 4 && t_one->id = 2 && t_two->id == 5 && t_t->id == 1)
		write(1, "sa\nrra\nsa\nrra\n", 14);
	else if (s->a->id == 4 && t_one->id = 2 && t_two->id == 5 && t_t->id == 3)
		write(1, "sa\nrra\npb\nrra\nsa\npa\n", 20);
	else if (s->a->id == 4 && t_one->id = 3 && t_two->id == 1 && t_t->id == 2)
		write(1, "sa\nra\nra\npb\nsa\nra\npa\n", 21);
	else
		seven(s, t_one, t_two, t_t);
}

void	four(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 3 && t_one->id = 4 && t_two->id == 2 && t_t->id == 5)
		write(1, "ra\nsa\nrra\nsa\nrra\n", 17);
	else if (s->a->id == 3 && t_one->id = 4 && t_two->id == 5 && t_t->id == 1)
		write(1, "rra\nrra\n", 8);
	else if (s->a->id == 3 && t_one->id = 4 && t_two->id == 5 && t_t->id == 2)
		write(1, "rra\nrra\nsa\n", 10);
	else if (s->a->id == 3 && t_one->id = 5 && t_two->id == 1 && t_t->id == 2)
		write(1, "rra\nsa\nrra\nrra\n", 15);
	else if (s->a->id == 3 && t_one->id = 5 && t_two->id == 1 && t_t->id == 4)
		write(1, "ra\npb\nsa\nra\npa\nra\n", 18);
	else if (s->a->id == 3 && t_one->id = 5 && t_two->id == 2 && t_t->id == 1)
		write(1, "rra\nsa\nrra\nrra\nsa\n", 18);
	else if (s->a->id == 3 && t_one->id = 5 && t_two->id == 2 && t_t->id == 4)
		write(1, "sa\nrra\npb\nra\nsa\npa\n", 19);
	else if (s->a->id == 3 && t_one->id = 5 && t_two->id == 4 && t_t->id == 1)
		write(1, "ra\nsa\nra\nra\n", 12);
	else if (s->a->id == 3 && t_one->id = 5 && t_two->id == 4 && t_t->id == 2)
		write(1, "ra\nsa\nra\nra\nsa\n", 15);
	else if (s->a->id == 4 && t_one->id = 1 && t_two->id == 2 && t_t->id == 3)
		write(1, "rra\nsa\nra\nra\n", 13);
	else if (s->a->id == 4 && t_one->id = 1 && t_two->id == 2 && t_t->id == 5)
		write(1, "ra\npb\nsa\nra\npa\n", 15);
	else
		six(s, t_one, t_two, t_t);
}

void	four(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 3 && t_one->id = 1 && t_two->id == 5 && t_t->id == 2)
		write(1, "sa\npb\nsa\nra\nsa\npa\n", 18);
	else if (s->a->id == 3 && t_one->id = 1 && t_two->id == 5 && t_t->id == 4)
		write(1, "ra\npb\nsa\nra\nra\npa\n", 18);
	else if (s->a->id == 3 && t_one->id = 2 && t_two->id == 1 && t_t->id == 4)
		write(1, "sa\nra\nsa\nrra\nsa\n", 16);
	else if (s->a->id == 3 && t_one->id = 2 && t_two->id == 1 && t_t->id == 5)
		write(1, "ra\npb\npb\nsa\nrrr\npa\npa\n", 22);
	else if (s->a->id == 3 && t_one->id = 2 && t_two->id == 4 && t_t->id == 1)
		write(1, "sa\nrra\nrra\nsa\nra\n", 17);
	else if (s->a->id == 3 && t_one->id = 2 && t_two->id == 4 && t_t->id == 5)
		write(1, "sa\nrra\n", 7);
	else if (s->a->id == 3 && t_one->id = 2 && t_two->id == 5 && t_t->id == 1)
		write(1, "sa\npb\nrra\nsa\npa\nrra\n", 20);
	else if (s->a->id == 3 && t_one->id = 2 && t_two->id == 5 && t_t->id == 4)
		write(1, "sa\nra\nra\nsa\nra\nra\n", 18);
	else if (s->a->id == 3 && t_one->id = 4 && t_two->id == 1 && t_t->id == 2)
		write(1, "ra\nra\npb\nsa\nra\npa\n", 18);
	else if (s->a->id == 3 && t_one->id = 4 && t_two->id == 1 && t_t->id == 5)
		write(1, "ra\nra\nsa\nra\n", 12);
	else if (s->a->id == 3 && t_one->id = 4 && t_two->id == 2 && t_t->id == 1)
		write(1, "ra\nra\nsa\npb\nsa\nra\npa\n", 21);
	else
		five(s, t_one, t_two, t_t);
}
