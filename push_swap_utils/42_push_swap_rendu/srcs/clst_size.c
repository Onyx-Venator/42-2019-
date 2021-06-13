/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:39 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:40 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		clst_size(t_stack *root)
{
	int		size;
	t_stack	*it;

	size = 0;
	it = root->next;
	while (it != root)
	{
		size++;
		it = it->next;
	}
	return (size);
}

int		clst_max_size(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;

	size_a = 0;
	size_b = 0;
	if (a)
		size_a = clst_size(a);
	if (b)
		size_b = clst_size(b);
	if (size_a > size_b)
		return (size_a);
	else
		return (size_b);
}
