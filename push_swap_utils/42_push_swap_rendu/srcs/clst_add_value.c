/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_add_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:32 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:32 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clst_add_before(t_stack *elem, int val)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem != NULL)
	{
		new_elem->val = val;
		new_elem->prev = elem->prev;
		new_elem->next = elem;
		elem->prev->next = new_elem;
		elem->prev = new_elem;
	}
}

void	clst_add_after(t_stack *elem, int val)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem != NULL)
	{
		new_elem->val = val;
		new_elem->prev = elem;
		new_elem->next = elem->next;
		elem->next->prev = new_elem;
		elem->next = new_elem;
	}
}

void	clst_add_front(t_stack *root, int val)
{
	clst_add_after(root, val);
}

void	clst_add_back(t_stack *root, int val)
{
	clst_add_before(root, val);
}
