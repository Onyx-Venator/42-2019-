/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:07:09 by cofoundo          #+#    #+#             */
/*   Updated: 2019/11/13 21:34:32 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	int		i;

	i = -1;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = malloc(sizeof(content))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
