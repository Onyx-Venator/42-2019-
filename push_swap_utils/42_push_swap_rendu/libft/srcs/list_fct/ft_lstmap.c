/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:06:36 by tsantoni          #+#    #+#             */
/*   Updated: 2019/10/22 18:41:31 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*temp;
	t_list	*new_element;

	if (lst == 0 || f == 0 || del == 0)
		return (NULL);
	if (!(new_element = ft_lstnew(f(lst->content))))
		return (NULL);
	first = new_element;
	temp = new_element;
	lst = lst->next;
	while (lst)
	{
		if (!(new_element = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		temp->next = new_element;
		temp = new_element;
		lst = lst->next;
	}
	return (first);
}
