/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:24:12 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/14 16:36:35 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*cl;

	if (*lst && del)
	{
		cl = *lst;
		while (cl)
		{
			tmp = cl->next;
			ft_lstdelone(cl, del);
			cl = tmp;
		}
		*lst = NULL;
	}
}
