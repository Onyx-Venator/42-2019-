/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:53:14 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/14 16:38:43 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void*), void (*d)(void*))
{
	t_list	*out;
	t_list	*new;
	t_list	*tmp;

	if (!l || !f)
		return (NULL);
	tmp = l;
	if (!(out = ft_lstnew(f(tmp->content))))
		return (NULL);
	new = out;
	tmp = tmp->next;
	while (tmp)
	{
		if (!(out->next = ft_lstnew(f(tmp->content))))
		{
			ft_lstclear(&new, d);
			return (NULL);
		}
		else
		{
			tmp = tmp->next;
			out = out->next;
		}
	}
	return (new);
}
