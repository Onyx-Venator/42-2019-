/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:47 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:47 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 3)
		sort_3(a, b);
	if (size == 4)
		sort_4(a, b);
	if (size == 5)
		sort_5(a, b);
	else
	{
		clean_a(a, b);
		merge_stacks(a, b);
		align_a(a, b);
	}
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	**input;

	size = ac - 1;
	if (ac < 2)
		return (ERROR);
	if (ac == 2 && (input = ft_split(av[1], ' ')))
		size = ft_tablen(input);
	else
		input = ft_tabdup(&av[1]);
	if (check_input(size, input) == ERROR)
	{
		ft_free_tab(&input);
		return (ft_printf("Error (input push_swap)\n"));
	}
	a = fill_stack(size, input);
	b = clst_create_root();
	sort(&a, &b, size);
	free_all(NULL, &a, &b, &input);
	return (SUCCESS);
}
