/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_opt_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:00:31 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/04 14:08:55 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_row_no_color(t_prints dt, int option)
{
	if (option == NUMBER)
	{
		ft_printf(""C_WHITE"%15s%15s"C_RES"\n", dt.print_a, dt.print_b);
		free(dt.print_a);
		free(dt.print_b);
	}
	if (option == END)
	{
		ft_printf(""C_WHITE"%15s%15s\n%15s%15s"C_RES"\n", "___________",
			"___________", "a     ", "b     ");
	}
}

void		replace_to_print(t_stack **tmp, t_prints *dt, int stack)
{
	if (stack == STACK_A)
	{
		free(dt->print_a);
		dt->print_a = ft_strdup(" ");
	}
	if (stack == STACK_B)
	{
		free(dt->print_b);
		dt->print_b = ft_strdup(" ");
	}
	*tmp = (*tmp)->prev;
}

int			print_stacks_no_color(t_stack *a, t_stack *b, int size)
{
	int			i;
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_prints	dt;

	if ((!a || !b) && ft_printf("Error : !a || !b (print_stacks)\n"))
		return (ERROR);
	i = -1;
	tmp_a = a->next;
	tmp_b = b->next;
	dt.size_max = size;
	while (++i < size)
	{
		dt.print_a = ft_itoa(tmp_a->val);
		dt.print_b = ft_itoa(tmp_b->val);
		if (tmp_a == a)
			replace_to_print(&tmp_a, &dt, STACK_A);
		if (tmp_b == b)
			replace_to_print(&tmp_b, &dt, STACK_B);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		print_row_no_color(dt, NUMBER);
	}
	print_row_no_color(dt, END);
	return (SUCCESS);
}
