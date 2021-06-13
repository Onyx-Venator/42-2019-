/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:23:25 by cofoundo          #+#    #+#             */
/*   Updated: 2021/06/13 13:39:40 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_value	*ft_lstlast(t_value *lst)
{
	t_value	*i;

	if (!lst)
		return (NULL);
	i = lst;
	while (i && i->next)
		i = i->next;
	return (i);
}

void	ft_lstadd_back(t_value **alst, t_value *new)
{
	t_value	*tmp;

	if (*alst)
	{
		tmp = *alst;
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
	else
		*alst = new;
}
