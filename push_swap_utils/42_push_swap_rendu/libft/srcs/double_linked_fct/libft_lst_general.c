/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:41:41 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:52:42 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_lst	*ft_lst_create_node(void *content)
{
	t_lst	*new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		ft_lst_size(t_lst *lst)
{
	int nb;

	nb = 0;
	while (lst)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}

void	ft_lst_iter_content(t_lst *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->next == NULL)
				return ;
			if (f)
				f(lst->content);
			lst = lst->next;
		}
	}
	if (f)
		f(lst->content);
}

void	ft_lst_iter_node(t_lst *lst, void (*f)(t_lst *))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst->next)
	{
		f(lst);
		lst = lst->next;
	}
	f(lst);
}
