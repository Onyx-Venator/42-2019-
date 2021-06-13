/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst_print_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:41:46 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 17:11:36 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_print_all_nodes(t_lst *lst)
{
	if (lst)
		ft_lst_iter_node(lst, &ft_lst_print_node);
}

void	ft_lst_print_all_contents(t_lst *lst)
{
	if (lst)
		ft_lst_iter_content(lst, &ft_lst_print_content);
}

void	ft_lst_print_all_env_vars(t_lst *first_var)
{
	while (first_var && first_var->next)
	{
		ft_lst_print_current_var(first_var);
		first_var = first_var->next;
	}
	ft_lst_print_current_var(first_var);
}
