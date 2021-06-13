/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:41 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:41 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_instruction(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") ||
	!ft_strcmp(line, "ss") || !ft_strcmp(line, "pa") ||
	!ft_strcmp(line, "pb") || !ft_strcmp(line, "ra") ||
	!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr") ||
	!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") ||
	!ft_strcmp(line, "rrr") || !ft_strcmp(line, ""))
		return (1);
	return (0);
}

static void	exec_rotate(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "ra"))
		rotate(&a);
	else if (!ft_strcmp(line, "rb"))
		rotate(&b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(&a);
		rotate(&b);
	}
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(&a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(&b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate(&a);
		reverse_rotate(&b);
	}
}

void		exec_one_ope(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa"))
		swap(&a);
	else if (!ft_strcmp(line, "sb"))
		swap(&b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(&a);
		swap(&b);
	}
	else if (!ft_strcmp(line, "pa"))
		push(&b, &a);
	else if (!ft_strcmp(line, "pb"))
		push(&a, &b);
	else if ((!ft_strcmp(line, "ra")) || (!ft_strcmp(line, "rb")) ||
	(!ft_strcmp(line, "rr")) || (!ft_strcmp(line, "rra")) ||
	(!ft_strcmp(line, "rrb")) || (!ft_strcmp(line, "rrr")))
		exec_rotate(line, a, b);
}

int			exec_ope(char *ope, t_stack **a, t_stack **b, int times)
{
	int	i;

	i = -1;
	while (++i < times)
	{
		exec_one_ope(ope, *a, *b);
		ft_printf("%s\n", ope);
	}
	return (1);
}
