/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:41:46 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 17:21:29 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../includes/color_shell.h"
#include <stdio.h>

void	ft_lst_print_node(t_lst *node)
{
	if (node)
	{
		if (node->content)
			ft_printf(""C_G_YELLOW"content: [%s]"C_RES"\n",
			(char *)node->content);
		if (node->prev)
			ft_printf(""C_G_GREEN"	prev: [%s]"C_RES"\n",
			(char *)node->prev->content);
		else
			ft_printf(""C_G_GREEN"	prev: [%s]"C_RES"\n",
			(char *)node->prev);
		if (node->next)
			ft_printf(""C_G_RED"	next: [%s]"C_RES"\n",
			(char *)node->next->content);
		else
			ft_printf(""C_G_RED"	next: [%s]"C_RES"\n",
			(char *)node->next);
	}
}

void	ft_lst_print_content(void *content)
{
	if (content && *(char *)content)
		ft_printf(""C_G_YELLOW"content: [%s]"C_RES"\n", (char *)content);
}

void	ft_lst_print_node_content(t_lst *node)
{
	if (node && node->content)
		ft_printf(""C_G_GREEN"content: [%s]"C_RES"\n", (char *)node->content);
}
