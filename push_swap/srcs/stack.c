/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:21:00 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/06 18:13:29 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	*save_flag(t_value *a, int size)
{
	t_value	*tmp;
	int		*save;
	int		i;

	i = -1;
	tmp = a;
	save = malloc(sizeof(int) * (size));
	if (!save)
		return (NULL);
	while (++i < size)
	{
		save[i] = tmp->flag;
		tmp = tmp->next;
	}
	return (save);
}

int			swap_a(t_stack *stack)
{
	int		i;
	int		count;
	int		next_count;
	int		*save;
	t_value	*tmp;

	count = count_flag(stack->a, 1);
	save = save_flag(stack->a, ft_lstsize(stack->a));
	ft_sa(stack);
	set_flag(stack->a);
	next_count = count_flag(stack->a, 1);
	ft_sa(stack);
	tmp = stack->a;
	i = -1;
	while (tmp)
	{
		tmp->flag = save[++i];
		tmp = tmp->next;
	}
	free(save);
	if (count < next_count)
		return (1);
	return (0);
}

void		longer_chain(t_stack *stack)
{
	set_flag(stack->a);
	while (count_flag(stack->a, 0) > 0)
	{
		if (swap_a(stack) == 1)
		{
			ft_sa(stack);
			write(1, "sa\n", 3);
			set_flag(stack->a);
		}
		else if (stack->a->flag == 0)
		{
			ft_pb(stack);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_ra(stack);
			write(1, "ra\n", 3);
		}
	}
}
