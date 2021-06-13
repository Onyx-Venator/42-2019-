/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:37:05 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/04 14:51:14 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>


void	print_lst(t_lst_int *list)
{
	// dprintf(1, "plop\n");
	while (list)
	{
		printf("value  = %d\n", list->value);
		list = list->next;
	}
}

void	print_lst_id(t_lst_int *list)
{
	// dprintf(1, "plop\n");
	while (list)
	{
		printf("value  = %d id = %d\n", list->value, list->id);
		list = list->next;
	}
}