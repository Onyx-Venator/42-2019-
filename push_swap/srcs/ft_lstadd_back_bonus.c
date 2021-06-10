/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:23:25 by cofoundo          #+#    #+#             */
/*   Updated: 2021/06/10 14:57:24 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_back(t_value **alst, t_value *new)
{
	t_list	*tmp;

	if (*alst)
	{
		tmp = *alst;
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
	else
		*alst = new;
}
