/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:34 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:34 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*clst_create_root(void)
{
	t_stack *root;

	root = malloc(sizeof(*root));
	if (root != NULL)
	{
		root->prev = root;
		root->next = root;
		root->val = 0;
		root->index = 0;
		root->flag = 0;
	}
	return (root);
}

t_stack	*clst_hide_elem(t_stack *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	return (elem);
}

int		*clst_to_tab(t_stack *a, int size)
{
	int		*t;
	t_stack *tmp;
	int		i;

	if (!(t = malloc(sizeof(int) * size)))
		return (NULL);
	tmp = a->next;
	i = 0;
	while (tmp != a)
	{
		t[i++] = tmp->val;
		tmp = tmp->next;
	}
	return (t);
}

void	clst_clear_stack(t_stack *root)
{
	t_stack	*it;
	t_stack	*tmp;

	it = root->next;
	while (it != root)
	{
		tmp = it->next;
		free(it);
		it = tmp;
	}
}

void	clst_free_stack(t_stack **root)
{
	clst_clear_stack(*root);
	free(*root);
	*root = NULL;
}
