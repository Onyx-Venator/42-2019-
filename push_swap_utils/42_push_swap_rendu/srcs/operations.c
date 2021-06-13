/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:57 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:57 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **root)
{
	t_stack	*to_move;

	if ((*root)->next != *root)
	{
		to_move = clst_hide_elem((*root)->next);
		clst_add_elem_back(*root, *to_move);
		free(to_move);
	}
}

void	reverse_rotate(t_stack **root)
{
	t_stack	*to_move;

	if ((*root)->next != *root)
	{
		to_move = clst_hide_elem((*root)->prev);
		clst_add_elem_front(*root, *to_move);
		free(to_move);
	}
}

void	swap(t_stack **root)
{
	t_stack *to_move;

	if ((*root)->next != *root && (*root)->next->next != *root)
	{
		to_move = clst_hide_elem((*root)->next->next);
		clst_add_elem_front(*root, *to_move);
		free(to_move);
	}
}

void	push(t_stack **sending, t_stack **receiving)
{
	t_stack *to_move;

	if ((*sending)->next != *sending)
	{
		to_move = clst_hide_elem((*sending)->next);
		clst_add_elem_front(*receiving, *to_move);
		free(to_move);
	}
}
