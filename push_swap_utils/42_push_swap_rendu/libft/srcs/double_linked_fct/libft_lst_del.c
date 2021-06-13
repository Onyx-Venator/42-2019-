/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:41:33 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:52:28 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_del(void **to_del)
{
	if (to_del && *to_del)
	{
		free(*to_del);
		*to_del = NULL;
	}
}

void	ft_lst_del_node(t_lst **alst, t_lst *to_del, void (*del)(void **))
{
	t_lst	*tmp;

	if (to_del && del)
	{
		tmp = *alst;
		if (tmp == to_del)
		{
			if (tmp->next)
			{
				tmp->next->prev = NULL;
				*alst = tmp->next;
			}
		}
		else
		{
			if (to_del->next)
				to_del->next->prev = to_del->prev;
			if (to_del->prev)
				to_del->prev->next = to_del->next;
		}
		if (to_del->content)
			del(&to_del->content);
	}
}

void	ft_lst_del_node_at_index(t_lst **alst, int index)
{
	t_lst	*to_del;

	to_del = ft_lst_get_node_at_index(alst, index);
	ft_lst_del_node(alst, to_del, ft_del);
}

void	ft_lst_del_first_node(t_lst **alst)
{
	ft_lst_del_node_at_index(alst, 0);
}

void	ft_lst_del_last_node(t_lst **alst)
{
	ft_lst_del_node_at_index(alst, ft_lst_size(*alst) - 1);
}
