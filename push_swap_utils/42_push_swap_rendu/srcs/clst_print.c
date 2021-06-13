/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:36 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:37 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_print_int_tab(t, ac - 1);
*/

void	ft_print_int_tab(int *t, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_printf("'%i'", t[i]);
	ft_printf("\n");
}

/*
** print_stack(a, C_G_GREEN, C_G_YELLOW);
*/

void	print_stack(t_stack *a, char *color1, char *color2)
{
	t_stack *it;

	it = a->next;
	while (it != a)
	{
		ft_printf("%s%i %s[%i]"C_G_GREY"[%i]  "C_RES, color1, it->val,
		color2, it->flag, it->index);
		it = it->next;
	}
	ft_printf("\n");
}

/*
** print_stacks(a, b, clst_max_size(a, b), C_G_YELLOW);
*/

int		print_stacks(t_stack *a, t_stack *b, int size, char *color)
{
	int		i;
	t_stack *it_a;
	t_stack *it_b;
	char	*print_a;
	char	*print_b;

	if ((!a || !b) && ft_printf("Error : !a || !b (print_stacks)\n"))
		return (ERROR);
	i = -1;
	it_a = a->next;
	it_b = b->next;
	while (++i < size)
	{
		print_a = ft_itoa(it_a->val);
		print_b = ft_itoa(it_b->val);
		if (it_a == a && (print_a = " "))
			it_a = it_a->prev;
		if (it_b == b && (print_b = " "))
			it_b = it_b->prev;
		it_a = it_a->next;
		it_b = it_b->next;
		ft_printf("%s	%s	%s	"C_RES"\n", color, print_a, print_b);
	}
	ft_printf("%s	_	_	\n	a	b	"C_RES"\n", color);
	return (SUCCESS);
}
