/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_opt_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:00:31 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/04 14:08:49 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_legend(void)
{
	ft_printf(""C_GREY"\nthis number just came "C_RES"");
	ft_printf(""COL_UP"UP"C_RES"\n");
	ft_printf(""C_GREY"this number just came "C_RES"");
	ft_printf(""COL_DOWN"DOWN"C_RES"\n");
	ft_printf(""C_GREY"this number just came "C_RES"");
	ft_printf(""COL_ROTATE"from THE OTHER SIDE OF ITS STACK"C_RES"\n");
	ft_printf(""C_GREY"this number just came "C_RES"");
	ft_printf(""COL_PUSH"from THE OTHER STACK"C_RES"\n\n");
}

static void	get_color_from_rotate(t_prints *dt)
{
	if (!ft_strcmp(dt->ope, "rb") || !ft_strcmp(dt->ope, "rr"))
	{
		if (dt->i == dt->size_b - 1)
			dt->col_b = COL_ROTATE;
		else
			dt->col_b = COL_UP;
	}
	if (!ft_strcmp(dt->ope, "rra") || !ft_strcmp(dt->ope, "rrr"))
	{
		if (dt->i == 0)
			dt->col_a = COL_ROTATE;
		else
			dt->col_a = COL_DOWN;
	}
	if (!ft_strcmp(dt->ope, "rrb") || !ft_strcmp(dt->ope, "rrr"))
	{
		if (dt->i == 0)
			dt->col_b = COL_ROTATE;
		else
			dt->col_b = COL_DOWN;
	}
}

static void	get_color_from_ope(t_prints *dt)
{
	dt->col_a = COL_RAS;
	dt->col_b = COL_RAS;
	if (dt->i == 0 && (!ft_strcmp(dt->ope, "sa") || !ft_strcmp(dt->ope, "ss")))
		dt->col_a = COL_UP;
	if (dt->i == 1 && (!ft_strcmp(dt->ope, "sa") || !ft_strcmp(dt->ope, "ss")))
		dt->col_a = COL_DOWN;
	if (dt->i == 0 && (!ft_strcmp(dt->ope, "sb") || !ft_strcmp(dt->ope, "ss")))
		dt->col_b = COL_UP;
	if (dt->i == 1 && (!ft_strcmp(dt->ope, "sb") || !ft_strcmp(dt->ope, "ss")))
		dt->col_b = COL_DOWN;
	if (dt->i == 0 && !ft_strcmp(dt->ope, "pa"))
		dt->col_a = COL_PUSH;
	if (dt->i == 0 && !ft_strcmp(dt->ope, "pb"))
		dt->col_b = COL_PUSH;
	if (!ft_strcmp(dt->ope, "ra") || !ft_strcmp(dt->ope, "rr"))
	{
		if (dt->i == dt->size_a - 1)
			dt->col_a = COL_ROTATE;
		else
			dt->col_a = COL_UP;
	}
	else
		get_color_from_rotate(dt);
}

static void	print_row_color(t_stack *a, t_stack *b, t_prints dt, int option)
{
	dt.size_a = clst_size(a);
	dt.size_b = clst_size(b);
	get_color_from_ope(&dt);
	if (option == NUMBER)
	{
		ft_printf("%s%15s"C_RES"%s%15s"C_RES"\n", dt.col_a, dt.print_a,
		dt.col_b, dt.print_b);
		free(dt.print_a);
		free(dt.print_b);
	}
	if (option == END)
		ft_printf(""COL_RAS"%15s%15s\n%15s%15s"C_RES"\n\n\n", "___________",
		"___________", "stack a  ", "stack b  ");
}

void		print_stacks_color(t_stack *a, t_stack *b, int size, char *ope)
{
	int			i;
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_prints	dt;

	i = -1;
	tmp_a = a->next;
	tmp_b = b->next;
	dt.size_max = size;
	dt.ope = ope;
	while (++i < size)
	{
		dt.i = i;
		dt.print_a = ft_itoa(tmp_a->val);
		dt.print_b = ft_itoa(tmp_b->val);
		if (tmp_a == a)
			replace_to_print(&tmp_a, &dt, STACK_A);
		if (tmp_b == b)
			replace_to_print(&tmp_b, &dt, STACK_B);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		print_row_color(a, b, dt, NUMBER);
	}
	print_row_color(a, b, dt, END);
}
