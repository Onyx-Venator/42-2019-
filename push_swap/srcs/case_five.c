/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:12:05 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/01 16:35:39 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.c"

void	three(t_stack *s, t_value *t_one, t_value *t_two, t_value *t_t)
{
	if (s->a->id == 2 && t_one->id = 5 && t_two->id == 1 && t_t->id == 3)
		write(1, "sa\nra\nsa\n", 9);
	else if (s->a->id == 2 && t_one->id = 5 && t_two->id == 1 && t_t->id == 4)
		write(1, "pb\nra\nra\nsa\npa\nrra\n", 19);
	else if (s->a->id == 2 && t_one->id = 5 && t_two->id == 3 && t_t->id == 1)
		write(1, "pb\nra\nsa\npa\nsa\n", 15);
	else if (s->a->id == 2 && t_one->id = 5 && t_two->id == 3 && t_t->id == 4)
		write(1, "sa\nrra\nsa\nra\n", 13);
	else if (s->a->id == 2 && t_one->id = 5 && t_two->id == 4 && t_t->id == 1)
		write(1, "pb\nsa\nrra\npa\nrra\n", 17);
	else if (s->a->id == 2 && t_one->id = 5 && t_two->id == 4 && t_t->id == 3)
		write(1, "ra\npb\nsa\nra\nra\npa\nra\n", 21);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 3 && t_t->id == 1)
		write(1, "ra\npb\nsa\nra\nra\npa\nra\n", 21);
	else if (s->a->id == 3 && t_one->id = 1 && t_two->id == 2 && t_t->id == 4)
		write(1, "sa\nra\nsa\nrra\n", 13);
	else if (s->a->id == 3 && t_one->id = 1 && t_two->id == 2 && t_t->id == 5)
		write(1, "ra\npb\npb\nsa\nrra\npa\npa\n", 22);
	else if (s->a->id == 3 && t_one->id = 1 && t_two->id == 4 && t_t->id == 2)
		write(1, "sa\nrra\nrra\nsa\nra\nsa\n", 20);
	else if (s->a->id == 3 && t_one->id = 1 && t_two->id == 4 && t_t->id == 5)
		write(1, "sa\nrra\nsa\n", 10);
	else
		four(s, t_one, t_two, t_t);
}

void	two(t_stack *s, t_value *t_one, t_value *t_two, t_value *t_t)
{
	if (s->a->id == 2 && t_one->id = 3 && t_two->id == 1 && t_t->id == 5)
		write(1, "ra\nra\npb\nsa\nra\nra\npa\n", 21);
	else if (s->a->id == 2 && t_one->id = 3 && t_two->id == 4 && t_t->id == 1)
		write(1, "rra\nrra\nsa\nra\n", 14);
	else if (s->a->id == 2 && t_one->id = 3 && t_two->id == 4 && t_t->id == 5)
		write(1, "rra\n", 4);
	else if (s->a->id == 2 && t_one->id = 3 && t_two->id == 5 && t_t->id == 1)
		write(1, "pb\nrra\nsa\npa\nrra\n", 17);
	else if (s->a->id == 2 && t_one->id = 3 && t_two->id == 5 && t_t->id == 4)
		write(1, "ra\nra\nsa\nra\nra\n", 15);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 1 && t_t->id == 3)
		write(1, "sa\nrra\nsa\nra\nra\nsa\n", 19);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 1 && t_t->id == 5)
		write(1, "ra\nra\npb\nra\nsa\npa\n", 18);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 3 && t_t->id == 1)
		write(1, "ra\nsa\nra\nra\nsa\nra\n", 18);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 3 && t_t->id == 5)
		write(1, "ra\nsa\nrra\nrra\n", 14);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 5 && t_t->id == 1)
		write(1, "rra\nsa\nrra\n", 11);
	else if (s->a->id == 2 && t_one->id = 4 && t_two->id == 5 && t_t->id == 3)
		write(1, "rra\npb\nrra\nsa\npa\n", 17);
	else
		three(s, t_one, t_two, t_t);
}

void	one(t_stack *s, t_value *t_one, t_value *t_two, t_value *t_t)
{
	if (s->a->id == 1 && t_one->id = 5 && t_two->id == 3 && t_t->id == 2)
		write(1, "pb\nra\nsa\npa\n", 12);
	else if (s->a->id == 1 && t_one->id = 5 && t_two->id == 3 && t_t->id == 4)
		write(1, "sa\nrra\nsa\nra\nsa\n", 16);
	else if (s->a->id == 1 && t_one->id = 5 && t_two->id == 4 && t_t->id == 2)
		write(1, "pb\nsa\nra\nra\npa\n", 15);
	else if (s->a->id == 1 && t_one->id = 5 && t_two->id == 4 && t_t->id == 3)
		write(1, "pb\nsa\nra\nra\nsa\npa\n", 18);
	else if (s->a->id == 2 && t_one->id = 1 && t_two->id == 3 && t_t->id == 4)
		write(1, "sa\n", 3);
	else if (s->a->id == 2 && t_one->id = 1 && t_two->id == 3 && t_t->id == 5)
		write(1, "sa\nrra\nrra\nsa\nra\nra\n", 20);
	else if (s->a->id == 2 && t_one->id = 1 && t_two->id == 4 && t_t->id == 3)
		write(1, "ra\npb\nsa\nrra\npa\n", 16);
	else if (s->a->id == 2 && t_one->id = 1 && t_two->id == 4 && t_t->id == 5)
		write(1, "sa\npb\nrra\nsa\npa\n", 16);
	else if (s->a->id == 2 && t_one->id = 1 && t_two->id == 5 && t_t->id == 3)
		write(1, "sa\npb\nsa\nra\npa\n", 15);
	else if (s->a->id == 2 && t_one->id = 1 && t_two->id == 5 && t_t->id == 4)
		write(1, "pb\npb\nsa\nrrr\npa\npa\n", 19);
	else if (s->a->id == 2 && t_one->id = 3 && t_two->id == 1 && t_t->id == 4)
		write(1, "ra\nsa\nrra\nsa\n", 13);
	else
		two(s, t_one, t_two, t_t);
}

void	five_utils(t_stack *s, t_value *t_one, t_value *t_two, t_value *t_t)
{
	if (s->a->id == 1 && t_one->id = 3 && t_two->id == 4 && t_t->id == 5)
		write(1, "rra\nsa\n", 7);
	else if (s->a->id == 1 && t_one->id = 3 && t_two->id == 5 && t_t->id == 2)
		write(1, "pb\nsa\nra\nsa\npa\n", 15);
	else if (s->a->id == 1 && t_one->id = 3 && t_two->id == 5 && t_t->id == 4)
		write(1, "ra\nra\nsa\nra\nra\nsa\n", 18);
	else if (s->a->id == 1 && t_one->id = 4 && t_two->id == 2 && t_t->id == 3)
		write(1, "sa\nrra\nsa\nra\nra\n", 16);
	else if (s->a->id == 1 && t_one->id = 4 && t_two->id == 2 && t_t->id == 5)
		write(1, "pb\nsa\nrra\nsa\npa\n", 16);
	else if (s->a->id == 1 && t_one->id = 4 && t_two->id == 3 && t_t->id == 2)
		write(1, "sa\nrra\nsa\nrra\nrra\nsa\nrra\n", 25);
	else if (s->a->id == 1 && t_one->id = 4 && t_two->id == 3 && t_t->id == 5)
		write(1, "pb\nsa\nrra\npa\n", 13);
	else if (s->a->id == 1 && t_one->id = 4 && t_two->id == 5 && t_t->id == 2)
		write(1, "sa\nra\nsa\nra\n", 12);
	else if (s->a->id == 1 && t_one->id = 4 && t_two->id == 5 && t_t->id == 3)
		write(1, "pb\nra\nra\nsa\npa\n", 15);
	else if (s->a->id == 1 && t_one->id = 5 && t_two->id == 2 && t_t->id == 3)
		write(1, "sa\nra\n", 6);
	else if (s->a->id == 1 && t_one->id = 5 && t_two->id == 2 && t_t->id == 4)
		write(1, "sa\nrra\nrra\nsa\nrra\nrra\n", 22);
	else
		one(s, t_one, t_two, t_t);
}

void	case_five(t_stack *s)
{
	t_value	*t_one;
	t_value	*t_two;
	t_value	*t_t;

	t_one = stack->a->next;
	t_two = t_one->next;
	t_t = t_two->next;
	if (s->a->id == 1 && t_one->id = 2 && t_two->id == 3 && t_t->id == 5)
		write(1, "rra\nrra\nsa\nra\nra\n", 17);
	else if (s->a->id == 1 && t_one->id = 2 && t_two->id == 4 && t_t->id == 3)
		write(1, "ra\nra\nsa\nrra\nrra\n", 17);
	else if (s->a->id == 1 && t_one->id = 2 && t_two->id == 4 && t_t->id == 5)
		write(1, "pb\nrra\nsa\npa\n", 14);
	else if (s->a->id == 1 && t_one->id = 2 && t_two->id == 5 && t_t->id == 3)
		write(1, "pb\nsa\nra\npa\n", 12);
	else if (s->a->id == 1 && t_one->id = 2 && t_two->id == 5 && t_t->id == 4)
		write(1, "pb\npb\nsa\nrra\npa\npa\n", 19);
	else if (s->a->id == 1 && t_one->id = 3 && t_two->id == 2 && t_t->id == 4)
		write(1, "ra\nsa\nrra\n", 10);
	else if (s->a->id == 1 && t_one->id = 3 && t_two->id == 2 && t_t->id == 5)
		write(1, "ra\nsa\nra\nra\nsa\nra\nra\n", 21);
	else if (s->a->id == 1 && t_one->id = 3 && t_two->id == 4 && t_t->id == 2)
		write(1, "rra\nrra\nsa\nra\nsa\n", 17);
	else
		five_utils(s, &t_one, &t_two, &t_t);
}
