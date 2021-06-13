/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:43:00 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:43:00 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*save_flags(t_stack *a, int size)
{
	int		*flags;
	t_stack	*tmp;
	int		i;

	i = -1;
	tmp = a->next;
	if (!(flags = malloc(sizeof(int) * size)))
		return (NULL);
	while (++i < size)
	{
		flags[i] = tmp->flag;
		tmp = tmp->next;
	}
	return (flags);
}

static void	restore_flags(t_stack **a, int *flags, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = (*a)->next;
	i = 0;
	while (i < size && tmp != *a)
	{
		tmp->flag = flags[i];
		tmp = tmp->next;
		i++;
	}
}

int			should_swap_a(t_stack *a, t_stack *b)
{
	int		actual_count;
	int		future_count;
	int		*flags;

	actual_count = count_flags(a, 1);
	flags = save_flags(a, clst_size(a));
	exec_one_ope("sa", a, b);
	add_best_flags(&a);
	future_count = count_flags(a, 1);
	exec_one_ope("sa", a, b);
	restore_flags(&a, flags, clst_size(a));
	free(flags);
	if (future_count > actual_count)
		return (1);
	return (0);
}
