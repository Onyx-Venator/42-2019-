/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/31 14:08:38 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	case_two(t_stack *stack)
{
	if (stack->a->id == 2)
		write(1, "sa\n", 3);
}

void	case_three(t_stack *stack)
{
	if (stack->a->id == 1 && stack->a->next->id == 3)
		write(1, "sa\nra\n", 6);
	else if (stack->a->->id == 2 && stack->a->next->id == 1)
		write(1, "sa\n", 3);
	else if (stack->a->->id == 2 && stack->a->next->id == 3)
		write(1, "rra\n", 4);
	else if (stack->a->->id == 3 && stack->a->next->id == 1)
		write(1, "ra\n", 3);
	else if (stack->a->->id == 3 && stack->a->next->id == 2)
		write(1, "sa\nrra\n", 7);
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
	else if (s->a->id == 2 && t_one->id == 4  && t_two->id == 1)
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
	else if (s->a->id == 4 && t_one->id == 2  && t_two->id == 1)
		write(1, "ra\nsa\n", 6);
	else if (s->a->id == 4 && t_one->id == 2  && t_two->id == 3)
		write(1, "rra\nsa\nra\n", 10);
	else if (s->a->id == 4 && t_one->id == 3  && t_two->id == 1)
		write(1, "sa\nra\nra\n", 9);
	else if (s->a->id == 4 && t_one->id == 3  && t_two->id == 2)
		write(1, "sa\nra\nra\nsa\n", 12);
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
	else if (s->a->id == 1 && t_one->id = 3 && t_two->id == 4 && t_t->id == 5)
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
	else if (s->a->id == 1 && t_one->id = 5 && t_two->id == 3 && t_t->id == 2)
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
	else if (s->a->id == 2 && t_one->id = 3 && t_two->id == 1 && t_t->id == 5)
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
	else if (s->a->id == 2 && t_one->id = 5 && t_two->id == 1 && t_t->id == 3)
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
		{ 5, { 3, 1, 4, 5, 2 }, { "sa", "rra", "sa" } },
		{ 5, { 3, 1, 5, 2, 4 }, { "sa", "pb", "sa", "ra", "sa", "pa" } },
		{ 5, { 3, 1, 5, 4, 2 }, { "ra", "pb", "sa", "ra", "ra", "pa" } },
		{ 5, { 3, 2, 1, 4, 5 }, { "sa", "ra", "sa", "rra", "sa" } },
		{ 5, { 3, 2, 1, 5, 4 }, { "ra", "pb", "pb", "sa", "rr"r "pa", "pa" } },
		{ 5, { 3, 2, 4, 1, 5 }, { "sa", "rra", "rra", "sa", "ra" } },
		{ 5, { 3, 2, 4, 5, 1 }, { "sa", "rra" } },
		{ 5, { 3, 2, 5, 1, 4 }, { "sa", "pb", "rra", "sa", "pa", "rra" } },
		{ 5, { 3, 2, 5, 4, 1 }, { "sa", "ra", "ra", "sa", "ra", "ra" } },
		{ 5, { 3, 4, 1, 2, 5 }, { "ra", "ra", "pb", "sa", "ra", "pa" } },
		{ 5, { 3, 4, 1, 5, 2 }, { "ra", "ra", "sa", "ra" } },
		{ 5, { 3, 4, 2, 1, 5 }, { "ra", "ra", "sa", "pb", "sa", "ra", "pa" } },
		{ 5, { 3, 4, 2, 5, 1 }, { "ra", "sa", "rra", "sa", "rra" } },
		{ 5, { 3, 4, 5, 1, 2 }, { "rra", "rra" } },
		{ 5, { 3, 4, 5, 2, 1 }, { "rra", "rra", "sa" } },
		{ 5, { 3, 5, 1, 2, 4 }, { "rra", "sa", "rra", "rra" } },
		{ 5, { 3, 5, 1, 4, 2 }, { "ra", "pb", "sa", "ra", "pa", "ra" } },
		{ 5, { 3, 5, 2, 1, 4 }, { "rra", "sa", "rra", "rra", "sa" } },
		{ 5, { 3, 5, 2, 4, 1 }, { "sa", "rra", "pb", "ra", "sa", "pa" } },
		{ 5, { 3, 5, 4, 1, 2 }, { "ra", "sa", "ra", "ra" } },
		{ 5, { 3, 5, 4, 2, 1 }, { "ra", "sa", "ra", "ra", "sa" } },
		{ 5, { 4, 1, 2, 3, 5 }, { "rra", "sa", "ra", "ra" } },
		{ 5, { 4, 1, 2, 5, 3 }, { "ra", "pb", "sa", "ra", "pa" } },
		{ 5, { 4, 1, 3, 2, 5 }, { "rra", "sa", "rra", "rra", "sa", "rra" } },
		{ 5, { 4, 1, 3, 5, 2 }, { "sa", "pb", "sa", "rra", "pa" } },
		{ 5, { 4, 1, 5, 2, 3 }, { "ra", "sa", "ra" } },
		{ 5, { 4, 1, 5, 3, 2 }, { "ra", "pb", "ra", "sa", "pa" } },
		{ 5, { 4, 2, 1, 3, 5 }, { "rra", "sa", "ra", "ra", "sa" } },
		{ 5, { 4, 2, 1, 5, 3 }, { "ra", "sa", "pb", "sa", "ra", "pa" } },
		{ 5, { 4, 2, 3, 1, 5 }, { "sa", "ra", "sa", "ra", "ra", "sa", "ra" } },
		{ 5, { 4, 2, 3, 5, 1 }, { "sa", "ra", "sa", "rra", "rra" } },
		{ 5, { 4, 2, 5, 1, 3 }, { "sa", "rra", "sa", "rra" } },
		{ 5, { 4, 2, 5, 3, 1 }, { "sa", "rra", "pb", "rra", "sa", "pa" } },
		{ 5, { 4, 3, 1, 2, 5 }, { "sa", "ra", "ra", "pb", "sa", "ra", "pa" } },
		{ 5, { 4, 3, 1, 5, 2 }, { "sa", "ra", "ra", "sa", "ra" } },
		{ 5, { 4, 3, 2, 1, 5 }, { "sa", "ra", "ra", "sa", "pb", "sa", "ra", "pa" } },
		{ 5, { 4, 3, 2, 5, 1 }, { "sa", "ra", "sa", "rra", "sa", "rra" } },
		{ 5, { 4, 3, 5, 1, 2 }, { "sa", "rra", "rra" } },
		{ 5, { 4, 3, 5, 2, 1 }, { "sa", "rra", "rra", "sa" } },
		{ 5, { 4, 5, 1, 2, 3 }, { "ra", "ra" } },
		{ 5, { 4, 5, 1, 3, 2 }, { "rra", "rra", "sa", "rra" } },
		{ 5, { 4, 5, 2, 1, 3 }, { "ra", "ra", "sa" } },
		{ 5, { 4, 5, 2, 3, 1 }, { "rra", "sa", "ra", "sa", "ra" } },
		{ 5, { 4, 5, 3, 1, 2 }, { "ra", "sa", "rra", "sa", "rra", "rra" } },
		{ 5, { 4, 5, 3, 2, 1 }, { "rra", "pb", "ra", "ra", "sa", "pa" } },
		{ 5, { 5, 1, 2, 3, 4 }, { "ra" } },
		{ 5, { 5, 1, 2, 4, 3 }, { "rra", "rra", "sa", "rra", "rra" } },
		{ 5, { 5, 1, 3, 2, 4 }, { "ra", "ra", "sa", "rra" } },
		{ 5, { 5, 1, 3, 4, 2 }, { "rra", "sa", "ra", "sa" } },
		{ 5, { 5, 1, 4, 2, 3 }, { "pb", "sa", "ra", "pa", "ra" } },
		{ 5, { 5, 1, 4, 3, 2 }, { "sa", "pb", "sa", "ra", "ra", "sa", "pa" } },
		{ 5, { 5, 2, 1, 3, 4 }, { "ra", "sa" } },
		{ 5, { 5, 2, 1, 4, 3 }, { "ra", "ra", "pb", "sa", "rra", "pa" } },
		{ 5, { 5, 2, 3, 1, 4 }, { "ra", "ra", "sa", "rra", "sa" } },
		{ 5, { 5, 2, 3, 4, 1 }, { "rra", "sa", "ra" } },
		{ 5, { 5, 2, 4, 1, 3 }, { "sa", "pb", "sa", "rra", "pa", "rra" } },
		{ 5, { 5, 2, 4, 3, 1 }, { "ra", "ra", "sa", "ra", "ra", "sa", "ra" } },
		{ 5, { 5, 3, 1, 2, 4 }, { "sa", "rra", "sa", "rra", "rra" } },
		{ 5, { 5, 3, 1, 4, 2 }, { "rra", "pb", "ra", "sa", "pa", "sa" } },
		{ 5, { 5, 3, 2, 1, 4 }, { "sa", "rra", "sa", "rra", "rra", "sa" } },
		{ 5, { 5, 3, 2, 4, 1 }, { "rra", "pb", "ra", "sa", "pa" } },
		{ 5, { 5, 3, 4, 1, 2 }, { "sa", "ra", "sa", "ra", "ra" } },
		{ 5, { 5, 3, 4, 2, 1 }, { "sa", "ra", "sa", "ra", "ra", "sa" } },
		{ 5, { 5, 4, 1, 2, 3 }, { "sa", "ra", "ra" } },
		{ 5, { 5, 4, 1, 3, 2 }, { "sa", "rra", "rra", "sa", "rra" } },
		{ 5, { 5, 4, 2, 1, 3 }, { "sa", "ra", "ra", "sa" } },
		{ 5, { 5, 4, 2, 3, 1 }, { "sa", "rra", "sa", "ra", "sa", "ra" } },
		{ 5, { 5, 4, 3, 1, 2 }, { "pb", "sa", "ra", "ra", "pa", "ra" } },
		{ 5, { 5, 4, 3, 2, 1 }, { "sa", "rra", "pb", "ra", "ra", "sa", "pa" } },
}

void	ft_exec_op(int op, t_stack *stack, int nb_ope)
{
	while (nb_ope != 0)
	{
		if (op == RA)
			ft_ra(stack);
		else if (op == RB)
			ft_rb(stack);
		else if (op == RR)
			ft_rr(stack);
		else if (op == RRA)
			ft_rra(stack);
		else if (op == RRB)
			ft_rrb(stack);
		else if (op == RRR)
			ft_rrr(stack);
		else if (op == PA)
			ft_pa(stack);
		else if (op == PB)
			ft_pb(stack);
		else if (op == SA)
			ft_sa(stack);
		else if (op == SB)
			ft_sb(stack);
		else if (op == SS)
			ft_ss(stack);
		write(1, "\n", 1);
		nb_ope--;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;
	t_value	tmp;
	int		i;
	int		*j;

	i = 0;
	if (ac == 1 || ft_verif(ac, av) == 0)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	stack.a = NULL;
	stack.b = NULL;
	j = malloc(sizeof(int) * (ac + 1));
	if (j == NULL)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	j[ac] = NULL;
	while (ac > ++i)
	{
		tmp = malloc(sizeof(t_value));
		if (tmp == NULL)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		tmp->next = NULL;
		tmp->value = ft_atoi(av[i]);
		j[i -1] = tmp->value;
		tmp->id = i;
		tmp->flag = 0;
		ft_lstadd_back(&(stack->a), tmp);
	}
	add_id(stack.a, i, j);
	longer_chain(&stack);
	set_flags(&stack);
	id_max(&stack);
	if (stack->id_max <= 5)
	{
		if (stack->id_max == 2)
			case_two(&stack);
		if (stack->id_max == 3)
			case_three(&stack);
		if (stack->id_max == 4)
			case_four(&stack);
		if (stack->id_max == 5)
			case_five(&stack);
	}
	else
	{
		swap_stack(&stack);
		search_op(&stack);
	}
	free(stack);
	return;
}
