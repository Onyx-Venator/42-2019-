/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:25:44 by cofoundo          #+#    #+#             */
/*   Updated: 2021/08/29 21:42:55 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static_void	advance(int *cur_id, int i, t_value *tmp_utils)
{
	i++,
	cur_id = tmp_utils->id;
}

static_int	set_variable(t_value *tmp, t_value *tmp_utils, int cur_id)
{
	tmp_utils = tmp->next;
	cur_id = tmp->id;
}

static_void	set_best(t_value *best, t_value *tmp, int i, int j)
{
	best = tmp;
	i = j;
}

void	add_id(t_value *a, int *j)
{
	int	u;
	int	tmp;

	u = -1;
	while (j[++u])
	{
		if (j[u + 1] && (j[u] > j[u + 1]))
		{
			tmp = j[u];
			j[u] = j[u + 1];
			j[u + 1] = tmp;
			u = -1;
		}
	}
	while (a->next)
	{
		u = -1;
		while (a->value != j[++u])
			;
		a->id = u;
	}
}

void	longer_chain(t_stack *stack)
{
	t_value	tmp;
	t_value	tmp_utils;
	t_value	best;
	int i[2];
	int cur_id;

	tmp = stack->a;
	i[1] = 0;
	while (tmp)
	{
		i[0] = set_variable(&tmp, &tmp_utils, cur_id);
		while (tmp_utils != tmp)
		{
			if (tmp_utils = NULL)
				tmp_utils = stack->a;
			if (cur_id < tmp_utils->id)
				advance(cur_id, i[0], &tmp_utils)
			tmp_utils = tmp_utils->next;
		}
		if (i[0] > i[1])
			set_best(&best, &tmp, i[1], i[0]);
		tmp = tmp->next;
	}
	stack->start_chain = best->id;
}
