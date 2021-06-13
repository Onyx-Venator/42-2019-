/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:41:38 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:41:39 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_add_node_front(t_lst **alst, t_lst *new)
{
	if (new)
	{
		(*alst)->prev = new;
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lst_add_node_back(t_lst **alst, t_lst *new)
{
	t_lst	*tmp;

	if (*alst == 0)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = tmp;
	}
}
