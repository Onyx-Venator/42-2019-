/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:36:34 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/01 16:09:53 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static_void	four_utils(t_stack *s, t_value *t_one, t_value *t_two)
{
	if (s->a->id == 4 && t_one->id == 2  && t_two->id == 1)
		write(1, "ra\nsa\n", 6);
	else if (s->a->id == 4 && t_one->id == 2  && t_two->id == 3)
		write(1, "rra\nsa\nra\n", 10);
	else if (s->a->id == 4 && t_one->id == 3  && t_two->id == 1)
		write(1, "sa\nra\nra\n", 9);
	else if (s->a->id == 4 && t_one->id == 3  && t_two->id == 2)
		write(1, "sa\nra\nra\nsa\n", 12);
}

static_void	case_four_utils(t_stack *s, t_value *t_one, t_value *t_two)
{
	if (s->a->id == 2 && t_one->id == 4  && t_two->id == 1)
		write(1, "sa\nra\nsa\n", 9);
	else if (s->a->id == 2 && t_one->id == 4  && t_two->id == 3)
		write(1, "sa\nrra\nsa\nra\n", 13);
	else if (s->a->id == 3 && t_one->id == 1  && t_two->id == 2)
		write(1, "sa\nra\nsa\nrra\n", 13);
	else if (s->a->id == 3 && t_one->id == 1  && t_two->id == 4)
		write(1, "sa\nrra\nsa\n", 10);
	else if (s->a->id == 3 && t_one->id == 2  && t_two->id == 1)
		write(1, "sa\nra\nsa\nrra\nsa\n", 16);
	else if (s->a->id == 3 && t_one->id == 2  && t_two->id == 4)
		write(1, "sa\nrra\n", 7);
	else if (s->a->id == 3 && t_one->id == 4  && t_two->id == 1)
		write(1, "ra\nra\n", 6);
	else if (s->a->id == 3 && t_one->id == 4  && t_two->id == 2)
		write(1, "ra\nra\nsa\n", 9);
	else if (s->a->id == 4 && t_one->id == 1  && t_two->id == 2)
		write(1, "ra\n", 3);
	else if (s->a->id == 4 && t_one->id == 1  && t_two->id == 3)
		write(1, "ra\nra\nsa\nrra\n", 16);
	else
		four_utils(s, &t_one, &t_two);
}

void	case_four(t_stack *s)
{
	t_value	*t_one;
	t_value	*t_two;

	t_one = stack->a->next;
	t_two = t_one->next;
	if (s->a->id == 1 && t_one->id == 2  && t_two->id == 4)
		write(1, "pb\nsa ra pa\n", 12);
	else if (s->a->id == 1 && t_one->id == 3  && t_two->id == 2)
		write(1, "ra\nsa\nrra\n", 10);
	else if (s->a->id == 1 && t_one->id == 3  && t_two->id == 4)
		write(1, "rra\nsa\n", 7);
	else if (s->a->id == 1 && t_one->id == 4  && t_two->id == 2)
		write(1, "sa\nra\n", 6);
	else if (s->a->id == 1 && t_one->id == 4  && t_two->id == 3)
		write(1, "pa\nsa\nrra\npa\n", 13);
	else if (s->a->id == 2 && t_one->id == 1  && t_two->id == 3)
		write(1, "sa\n", 3);
	else if (s->a->id == 2 && t_one->id == 1  && t_two->id == 4)
		write(1, "sa\npb\nsa\nra\npa\n", 15);
	else if (s->a->id == 2 && t_one->id == 3  && t_two->id == 1)
		write(1, "ra\nsa\nrra\nsa\n", 13);
	else if (s->a->id == 2 && t_one->id == 3  && t_two->id == 4)
		write(1, "rra\n", 4);
	else
		case_four_utils(s, &t_one, &t_two);
}
