/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:24 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:24 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_a(t_stack **a, t_stack **b)
{
	int	to_do;

	to_do = get_index(*a, get_stack_min(*a));
	if (to_do < clst_size(*a) / 2 + 1)
		exec_ope("ra", a, b, to_do);
	else
		exec_ope("rra", a, b, clst_size(*a) - to_do);
}
