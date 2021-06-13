/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:29:10 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/10 13:58:35 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_lst_add_back(t_lst_int **alst, t_lst_int *new)
{
	t_lst_int	*tmp;

	// printf("ft_lst_add_back 1\n");
	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	// printf("ft_lst_add_back 2\n");
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	// printf("ft_lst_add_back 3\n");
	new->next = NULL;
	// printf("ft_lst_add_back\n");
	tmp->next = new;
}
