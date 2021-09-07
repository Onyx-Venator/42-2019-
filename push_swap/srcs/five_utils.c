/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:41:52 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/02 18:21:15 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ten(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 5 && t_one->id == 4 && t_two->id == 3 && t_t->id == 1)
		write(1, "pb\nsa\nra\nra\npa\nra\n", 18);
	else if (s->a->id == 5 && t_one->id == 4 && t_two->id == 3 && t_t->id == 2)
		write(1, "sa\nrra\npb\nra\nra\nsa\npa\n", 22);
}

void	nine(t_stack *s, t_value *t_one, t_value *t_two,t_value *t_t)
{
	if (s->a->id == 5 && t_one->id == 2 && t_two->id == 4 && t_t->id == 3)
		write(1, "ra\nra\nsa\nra\nra\nsa\nra\n", 21);
	else if (s->a->id == 5 && t_one->id == 3 && t_two->id == 1 && t_t->id == 2)
		write(1, "sa\nrra\nsa\nrra\nrra\n", 18);
	else if (s->a->id == 5 && t_one->id == 3 && t_two->id == 1 && t_t->id == 4)
		write(1, "rra\npb\nra\nsa\npa\nsa\n", 19);
	else if (s->a->id == 5 && t_one->id == 3 && t_two->id == 2 && t_t->id == 1)
		write(1, "sa\nrra\nsa\nrra\nrra\nsa\n", 21);
	else if (s->a->id == 5 && t_one->id == 3 && t_two->id == 2 && t_t->id == 4)
		write(1, "rra\npb\nra\nsa\npa\n", 16);
	else if (s->a->id == 5 && t_one->id == 3 && t_two->id == 4 && t_t->id == 1)
		write(1, "sa\nra\nsa\nra\nra\n", 15);
	else if (s->a->id == 5 && t_one->id == 3 && t_two->id == 4 && t_t->id == 2)
		write(1, "sa\nra\nsa\nra\nra\nsa\n", 18);
	else if (s->a->id == 5 && t_one->id == 4 && t_two->id == 1 && t_t->id == 2)
		write(1, "sa\nra\nra\n", 9);
	else if (s->a->id == 5 && t_one->id == 4 && t_two->id == 1 && t_t->id == 3)
		write(1, "sa\nrra\nrra\nsa\nrra\n", 18);
	else if (s->a->id == 5 && t_one->id == 4 && t_two->id == 2 && t_t->id == 1)
		write(1, "sa\nra\nra\nsa\n", 12);
	else if (s->a->id == 5 && t_one->id == 4 && t_two->id == 2 && t_t->id == 3)
		write(1, "sa\nrra\nsa\nra\nsa\nra\n", 19);
	else
		ten(s, t_one, t_two, t_t);
}
