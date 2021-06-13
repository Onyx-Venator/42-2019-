/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:00:28 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/10 14:42:18 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void get_id_from_value(t_lst_int *lst, int *t)
{
	int i;
	t_lst_int *tmp;

	tmp = lst;
	 while (tmp)
	 {
		 i = 0;
		 while (tmp->value != t[i])
		 	i++;
		// printf("%d  %d %d\n", tmp->value, t[i], i);
		tmp->id = i;
		tmp = tmp->next;
	 }
}

void	ft_int_tab_swap(int *t, int i, int j)
{
	int tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

void	ft_quicksort(int *t, int start, int end)
{
	int	i;
	int	j;
	int pivot;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (t[i] <= t[pivot] && i < end)
				i++;
			while (t[j] > t[pivot])
				j--;
			if (i < j)
				ft_int_tab_swap(t, i, j);
		}
		ft_int_tab_swap(t, pivot, j);
		ft_quicksort(t, start, j - 1);
		ft_quicksort(t, j + 1, end);
	}
}

int	ft_lst_int_size(t_lst_int *lst)
{
	int nb;

	nb = 0;
	while (lst)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}


int main(int argc, char **argv)
{
	int		i;
	t_stack	stack;
	t_lst_int	*tmp;
	int *t;

	i = 1;
	stack.a = NULL;
	stack.b = NULL;
	while (argc > i)
	{
		if (!ft_strisdgit(argv[i]))
		{
			printf("error is digit\n");
			// free lst;
			return (0);
		}
		tmp = malloc(sizeof(t_lst_int));
		if (!tmp)
		{
			// free lst;
			printf("error malloc\n");
			return (0);
		}
		tmp->value = ft_atoi(argv[i]);
		tmp->next = NULL;
		ft_lst_add_back(&(stack.a), tmp);
		i++;
	}
	t = malloc(sizeof(int) * (i));
	if (t == NULL)
	{
		// free lst;
		printf("error malloc\n");
		return (0);
	}
	i = 1;
	while (argc > i)
	{
		if (ft_isdouble(t,i,ft_atoi(argv[i])))
		{
			printf("error double digit\n");
			return (0);
		}
		t[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_quicksort(t, 0, ft_lst_int_size(stack.a) - 1);
	get_id_from_value(stack.a, t);
	print_lst_id(stack.a);
	// sort_stack(stack);
	return (0);
}
