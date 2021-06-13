/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_add_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:29 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:30 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clst_add_elem_before(t_stack *elem, t_stack new)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem != NULL)
	{
		new_elem->val = new.val;
		new_elem->flag = new.flag;
		new_elem->index = new.index;
		new_elem->prev = elem->prev;
		new_elem->next = elem;
		elem->prev->next = new_elem;
		elem->prev = new_elem;
	}
}

void	clst_add_elem_after(t_stack *elem, t_stack new)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem != NULL)
	{
		new_elem->val = new.val;
		new_elem->flag = new.flag;
		new_elem->index = new.index;
		new_elem->prev = elem;
		new_elem->next = elem->next;
		elem->next->prev = new_elem;
		elem->next = new_elem;
	}
}

void	clst_add_elem_front(t_stack *root, t_stack new)
{
	clst_add_elem_after(root, new);
}

void	clst_add_elem_back(t_stack *root, t_stack new)
{
	clst_add_elem_before(root, new);
}
