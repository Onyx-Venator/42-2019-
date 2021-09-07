/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:38:11 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/06 19:15:27 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	while (a)
	{
		u = -1;
		while (a->value != j[++u])
			;
		a->id = u + 1;
		a = a->next;
	}
}

int		end_stack(t_value *a)
{
	t_value *tmp;

	tmp = a;
	while (tmp)
		tmp = tmp->next;
	return (tmp->id);
}


void	id_max(t_stack *stack)
{
	t_value	*tmp;

	tmp = stack->a;
	stack->id_max = tmp->id;
	while (tmp)
	{
		if (tmp->id > stack->id_max)
			stack->id_max = tmp->id;
		tmp = tmp->next;
	}
}
