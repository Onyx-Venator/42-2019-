/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_shared.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:49 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/05 18:12:40 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		are_sorted(int size, t_stack *a, t_stack *b)
{
	t_stack	*it;

	it = a->next;
	if (clst_size(a) != size)
		return (0);
	if (b->next != b)
		return (0);
	while (it->next != a)
	{
		if (it->val >= it->next->val)
			return (0);
		it = it->next;
	}
	return (1);
}

int		*create_index_tab(t_stack **a)
{
	int	*t;

	t = clst_to_tab(*a, clst_size(*a));
	ft_quicksort(t, 0, clst_size(*a) - 1);
	fill_list_index(a, t, clst_size(*a));
	return (t);
}

/*
** for each av, check : 1) if int
** 2) if no extra sign -/+
** 3) if not appearing twice
*/

int		check_input(int ac, char **av)
{
	long	i;
	long	n;
	int		j;

	i = -1;
	n = 0;
	while (++i < ac)
	{
		n = ft_atoi_long(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (ERROR);
		j = -1;
		while (av[i][++j] != '\0')
		{
			if (j == 0 && av[i][j] == '-')
				continue ;
			else if (ft_isdigit(av[i][j]) == 0)
				return (ERROR);
		}
		n = -1;
		while (++n < i)
			if (ft_atoi_long(av[i]) == ft_atoi_long(av[n]))
				return (ERROR);
	}
	return (SUCCESS);
}

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*root;
	int		i;

	i = -1;
	root = clst_create_root();
	while (++i < ac)
		clst_add_back(root, ft_atoi(av[i]));
	return (root);
}

int		free_all(char **line, t_stack **a, t_stack **b, char ***input)
{
	if (line)
		ft_strdel(line);
	if (a)
		clst_free_stack(a);
	if (b)
		clst_free_stack(b);
	if (input)
		ft_free_tab(input);
	return (1);
}
